#include "Mediatheque.h"
#include "Utilisateur.h"
#include "Administrateur.h"
#include "Ressource.h"
#include "Livre.h"
#include "CD.h"
#include "DVD.h"
#include "VHS.h"
#include "Revue.h"
#include <iostream>
#include <algorithm>
#include <cctype>
#include <sstream>
#include <fstream>

void Mediatheque::setCurrentUser(std::unique_ptr<Utilisateur> user) {
    currentUser = std::move(user);
    if (currentUser) {
        currentUser->setMediatheque(this);
    }
}

Utilisateur* Mediatheque::getCurrentUser() const {
    return currentUser.get();
}

void Mediatheque::showCommands() const {
    std::cout << "\n==== COMMANDES DISPONIBLES ====\n";
    std::cout << "• add [type]       - Ajouter une ressource (admin uniquement)\n";
    std::cout << "• list             - Afficher toutes les ressources\n";
    std::cout << "• search <mot>     - Rechercher des ressources\n";
    std::cout << "• show <id>        - Afficher les détails d'une ressource\n";
    std::cout << "• borrow <id>      - Emprunter une ressource\n";
    std::cout << "• showborrow       - Afficher vos emprunts\n";
    std::cout << "• load <fichier>   - Charger des données depuis un fichier\n";
    std::cout << "• save <fichier>   - Sauvegarder (admin uniquement)\n";
    std::cout << "• clear            - Effacer les résultats de recherche\n";
    std::cout << "• delete <id>      - Supprimer une ressource (admin uniquement)\n";
    std::cout << "• reset            - Supprimer toutes les ressources (admin uniquement)\n";
    std::cout << "• bye              - Quitter l'application\n";
    std::cout << "================================\n";
}


void Mediatheque::dispatch() {
    std::string line;
    showCommands(); // Afficher les commandes au début

    while (true) {
        std::cout << "\n> ";
        if (!std::getline(std::cin, line)) break;
        if (line.empty()) continue;

        // Parse très simple: commande + (arg1)
        std::istringstream iss(line);
        std::string cmd;
        iss >> cmd;
        std::string arg;
        std::getline(iss, arg);               // récupère le reste
        if (!arg.empty() && arg[0] == ' ')    // trim espace initial
            arg.erase(0, 1);


        if (cmd == "bye") {
            std::cout << "Au revoir.\n";
            break;

        } else if (cmd == "add") {
            if (currentUser) currentUser->add(arg);
            else std::cout << "[Erreur] Aucun utilisateur connecté.\n";
            showCommands();

        } else if (cmd == "list") {
            listRessources();
            showCommands();

        } else if (cmd == "search") {
            searchRessources(arg);
            showCommands();

        } else if (cmd == "show") {
            int idR = arg.empty() ? -1 : std::stoi(arg);
            showRessource(idR);
            showCommands();

        } else if (cmd == "borrow") {
            int idR = arg.empty() ? -1 : std::stoi(arg);
            if (currentUser) currentUser->borrow(idR);
            else std::cout << "[Erreur] Aucun utilisateur connecté.\n";
            showCommands();

        } else if (cmd == "showborrow") {
            if (currentUser) currentUser->showBorrow();
            else std::cout << "[Erreur] Aucun utilisateur connecté.\n";
            showCommands();

        } else if (cmd == "load") {
            if (!currentUser) { 
                std::cout << "[Erreur] Aucun utilisateur connecté.\n"; 
            } else {
                // Tous les utilisateurs peuvent charger des fichiers
                loadFromFile(arg);
            }
            showCommands();

        } else if (cmd == "save") {
            if (!currentUser) { 
                std::cout << "[Erreur] Aucun utilisateur connecté.\n"; 
            } else {
                currentUser->save(arg);
                if (dynamic_cast<Administrateur*>(currentUser.get())) {
                    saveToFile(arg);
                }
            }
            showCommands();

        } else if (cmd == "clear") {
            clearSearchResults();
            showCommands();

        } else if (cmd == "delete") {
            if (!currentUser) { 
                std::cout << "[Erreur] Aucun utilisateur connecté.\n"; 
            } else {
                int id = arg.empty() ? -1 : std::stoi(arg);
                currentUser->deleteById(id);
                if (dynamic_cast<Administrateur*>(currentUser.get())) {
                    deleteRessource(id);
                }
            }
            showCommands();

        } else if (cmd == "ajouterutilisateur") {
            if (!currentUser) { std::cout << "[Erreur] Aucun utilisateur connecté.\n"; }
            else {
                std::istringstream as(arg);
                int id; std::string prenom, nom;
                if (!(as >> id >> prenom >> nom)) {
                    std::cout << "Usage: ajouterUtilisateur <id> <prenom> <nom>\n";
                } else {
                    Utilisateur u(id, prenom, nom);
                    currentUser->ajouterUtilisateur(u);
                }
            }
            showCommands();

        } else if (cmd == "supprimerutilisateur") {
            if (!currentUser) { std::cout << "[Erreur] Aucun utilisateur connecté.\n"; }
            else {
                int id = arg.empty() ? -1 : std::stoi(arg);
                currentUser->supprimerUtilisateur(id);
            }
            showCommands();

        } else if (cmd == "reset") {
            if (!currentUser) { 
                std::cout << "[Erreur] Aucun utilisateur connecté.\n"; 
            } else {
                currentUser->reset();
                if (dynamic_cast<Administrateur*>(currentUser.get())) {
                    resetRessources();
                }
            }
            showCommands();

        } else if (cmd == "listerutilisateurs") {
            if (!currentUser) { std::cout << "[Erreur] Aucun utilisateur connecté.\n"; }
            else currentUser->listerUtilisateurs();
            showCommands();
        } else {
            std::cout << "Commande inconnue.\n";
            showCommands();
        }
    }
}

void Mediatheque::addRessource(std::unique_ptr<Ressource> ressource) {
    ressources.push_back(std::move(ressource));
}

void Mediatheque::listRessources() const {
    if (searchResults.empty()) {
        // Afficher toutes les ressources
        if (ressources.empty()) {
            std::cout << "Aucune ressource disponible.\n";
            return;
        }
        std::cout << "=== Liste des ressources ===\n";
        for (const auto& ressource : ressources) {
            std::cout << "ID: " << ressource->getId() 
                      << " | Type: " << ressource->getType()
                      << " | Titre: " << ressource->getTitre()
                      << " | Auteur: " << ressource->getAuteur()
                      << " | Etat: " << ressource->getEtat();
            
            // Ajouter [non disponible] si emprunté
            if (ressource->getEtat() == "Emprunte") {
                std::cout << " [non disponible]";
            }
            std::cout << "\n";
        }
    } else {
        // Afficher les résultats de recherche
        std::cout << "=== Résultats de recherche ===\n";
        for (const auto& ressource : searchResults) {
            std::cout << "ID: " << ressource->getId() 
                      << " | Type: " << ressource->getType()
                      << " | Titre: " << ressource->getTitre()
                      << " | Auteur: " << ressource->getAuteur()
                      << " | Etat: " << ressource->getEtat();
            
            // Ajouter [non disponible] si emprunté
            if (ressource->getEtat() == "Emprunte") {
                std::cout << " [non disponible]";
            }
            std::cout << "\n";
        }
    }
}

void Mediatheque::searchRessources(const std::string& query) {
    searchResults.clear();
    
    if (query.empty()) {
        std::cout << "Veuillez spécifier une chaîne de recherche.\n";
        return;
    }
    
    // Recherche dans titre, auteur
    for (const auto& ressource : ressources) {
        std::string titre = ressource->getTitre();
        std::string auteur = ressource->getAuteur();
        
        // Conversion en minuscules pour recherche insensible à la casse
        std::transform(titre.begin(), titre.end(), titre.begin(), ::tolower);
        std::transform(auteur.begin(), auteur.end(), auteur.begin(), ::tolower);
        std::string queryLower = query;
        std::transform(queryLower.begin(), queryLower.end(), queryLower.begin(), ::tolower);
        
        if (titre.find(queryLower) != std::string::npos || 
            auteur.find(queryLower) != std::string::npos) {
            searchResults.push_back(ressource.get());
        }
    }
    
    std::cout << "Recherche terminée. " << searchResults.size() << " résultat(s) trouvé(s).\n";
    
    // Afficher directement les résultats
    if (!searchResults.empty()) {
        std::cout << "=== Résultats de la recherche ===\n";
        for (const auto& ressource : searchResults) {
            std::cout << "ID: " << ressource->getId() 
                      << " | Type: " << ressource->getType()
                      << " | Titre: " << ressource->getTitre()
                      << " | Auteur: " << ressource->getAuteur()
                      << " | Etat: " << ressource->getEtat() << "\n";
        }
    }
}

void Mediatheque::clearSearchResults() {
    searchResults.clear();
    std::cout << "Résultats de recherche effacés. Retour à la liste complète.\n";
}

void Mediatheque::showRessource(int id) const {
    Ressource* ressource = nullptr;
    
    // Chercher dans les résultats de recherche d'abord, sinon dans toutes les ressources
    const auto& listeRecherche = searchResults.empty() ? 
        [this]() {
            std::vector<Ressource*> all;
            for (const auto& r : ressources) all.push_back(r.get());
            return all;
        }() : searchResults;
    
    for (const auto& r : listeRecherche) {
        if (r->getId() == id) {
            ressource = r;
            break;
        }
    }
    
    if (!ressource) {
        std::cout << "Ressource avec ID " << id << " introuvable.\n";
        return;
    }
    
    std::cout << "=== Détails de la ressource ===\n";
    std::cout << "ID: " << ressource->getId() << "\n";
    std::cout << "Type: " << ressource->getType() << "\n";
    std::cout << "Titre: " << ressource->getTitre() << "\n";
    std::cout << "Auteur: " << ressource->getAuteur() << "\n";
    std::cout << "État: " << ressource->getEtat() << "\n";
}

void Mediatheque::deleteRessource(int id) {
    auto it = std::find_if(ressources.begin(), ressources.end(),
                          [id](const std::unique_ptr<Ressource>& r) {
                              return r->getId() == id;
                          });
    
    if (it != ressources.end()) {
        std::cout << "Ressource '" << (*it)->getTitre() << "' supprimée.\n";
        ressources.erase(it);
        clearSearchResults(); // Vider les résultats de recherche
    } else {
        std::cout << "Ressource avec ID " << id << " introuvable.\n";
    }
}

void Mediatheque::resetRessources() {
    ressources.clear();
    searchResults.clear();
    std::cout << "Toutes les ressources ont été supprimées.\n";
}

void Mediatheque::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cout << "[Erreur] Impossible d'ouvrir le fichier: " << filename << "\n";
        return;
    }
    
    ressources.clear();
    searchResults.clear();
    
    std::string line;
    int count = 0;
    
    while (std::getline(file, line)) {
        if (line.empty()) continue;
        
        std::istringstream iss(line);
        std::string type;
        iss >> type;
        
        // Rendre la reconnaissance de type insensible à la casse
        std::transform(type.begin(), type.end(), type.begin(), ::tolower);
        
        if (type == "livre") {
            int id, annee, nbPages;
            std::string titre, auteur, etat, collection, resume;
            
            if (iss >> id >> titre >> auteur >> etat >> annee >> nbPages >> collection >> resume) {
                auto livre = std::make_unique<Livre>(id, titre, auteur, etat, annee, nbPages, collection, resume);
                ressources.push_back(std::move(livre));
                count++;
            }
        } else if (type == "cd") {
            int id, duree, nbPistes;
            std::string titre, auteur, etat, maison;
            
            if (iss >> id >> titre >> auteur >> etat >> duree >> maison >> nbPistes) {
                auto cd = std::make_unique<CD>(id, titre, auteur, etat, duree, maison, nbPistes);
                ressources.push_back(std::move(cd));
                count++;
            }
        }
    }
    
    file.close();
    std::cout << "Chargement terminé. " << count << " ressource(s) chargée(s) depuis " << filename << "\n";
}

void Mediatheque::saveToFile(const std::string& filename) const {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cout << "[Erreur] Impossible de créer le fichier: " << filename << "\n";
        return;
    }
    
    for (const auto& ressource : ressources) {
        std::string type = ressource->getType();
        std::transform(type.begin(), type.end(), type.begin(), ::tolower);
        
        file << type << " " 
             << ressource->getId() << " "
             << ressource->getTitre() << " "
             << ressource->getAuteur() << " "
             << ressource->getEtat();
        
        // Ajouter des détails spécifiques selon le type
        if (type == "livre") {
            // Pour l'instant, sauvegarde basique
            file << " 2023 100 Collection Resume";
        } else if (type == "cd") {
            file << " 60 MaisonProd 12";
        }
        
        file << "\n";
    }
    
    file.close();
    std::cout << "Sauvegarde terminée. " << ressources.size() << " ressource(s) sauvegardée(s) dans " << filename << "\n";
}

bool Mediatheque::borrowRessource(int id) {
    for (const auto& ressource : ressources) {
        if (ressource->getId() == id) {
            if (ressource->getEtat() == "Disponible") {
                ressource->setEtat("Emprunte");
                return true; // Emprunt réussi
            } else {
                return false; // Déjà emprunté
            }
        }
    }
    return false; // Ressource introuvable
}

Ressource* Mediatheque::findRessource(int id) const {
    for (const auto& ressource : ressources) {
        if (ressource->getId() == id) {
            return ressource.get();
        }
    }
    return nullptr; // Pas trouvé
}
