#include "Mediatheque.h"
#include "Utilisateur.h"
#include "Administrateur.h"
#include "Client.h"
#include "Ressource.h"
#include "Livre.h"
#include "Revue.h"
#include "CD.h"
#include "DVD.h"
#include "VHS.h"
#include <iostream>
#include <algorithm>
#include <sstream>
#include <fstream>

// (Simplifié) : on conserve la casse telle quelle, pas de normalisation

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
    showCommands(); 

    while (true) {
        std::cout << "\n> ";
        if (!std::getline(std::cin, line)) break;
        if (line.empty()) continue;

        std::istringstream iss(line);
        std::string cmd;
        iss >> cmd;
        std::string arg;
        std::getline(iss, arg);
        if (!arg.empty() && arg[0] == ' ')
            arg.erase(0, 1);


        if (cmd == "bye") {
            std::cout << "Au revoir.\n";
            break;

        } else if (cmd == "add") {
            currentUser->add(arg);
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
            currentUser->borrow(idR);
            showCommands();

        } else if (cmd == "showborrow") {
            currentUser->showBorrow();
            showCommands();

        } else if (cmd == "load") {
            // Chargement accessible (implémentation dans Medue)
            loadFromFile(arg);
            showCommands();

        } else if (cmd == "save") {
            if (auto admin = dynamic_cast<Administrateur*>(currentUser.get())) {
                admin->save(arg);
                saveToFile(arg);
            } else {
                std::cout << "[Erreur] Vous n'avez pas le droit de sauvegarder.\n";
            }
            showCommands();

        } else if (cmd == "clear") {
            clearSearchResults();
            showCommands();

        } else if (cmd == "delete") {
            int id = arg.empty() ? -1 : std::stoi(arg);
            if (auto admin = dynamic_cast<Administrateur*>(currentUser.get())) {
                admin->deleteById(id);
                deleteRessource(id);
            } else {
                std::cout << "[Erreur] Vous n'avez pas le droit de supprimer.\n";
            }
            showCommands();

        } else if (cmd == "ajouterutilisateur") {
            if (auto admin = dynamic_cast<Administrateur*>(currentUser.get())) {
                std::istringstream as(arg);
                int id; std::string prenom, nom;
                if (!(as >> id >> prenom >> nom)) {
                    std::cout << "Usage: ajouterUtilisateur <id> <prenom> <nom>\n";
                } else {
                    Utilisateur u(id, prenom, nom);
                    admin->ajouterUtilisateur(u);
                }
            } else {
                std::cout << "[Erreur] Vous n'avez pas le droit d'ajouter un utilisateur.\n";
            }
            showCommands();

        } else if (cmd == "supprimerutilisateur") {
            if (auto admin = dynamic_cast<Administrateur*>(currentUser.get())) {
                int id = arg.empty() ? -1 : std::stoi(arg);
                admin->supprimerUtilisateur(id);
            } else {
                std::cout << "[Erreur] Vous n'avez pas le droit de supprimer un utilisateur.\n";
            }
            showCommands();

        } else if (cmd == "reset") {
            if (auto admin = dynamic_cast<Administrateur*>(currentUser.get())) {
                admin->reset();
                resetRessources();
            } else {
                std::cout << "[Erreur] Vous n'avez pas le droit de remettre à zéro.\n";
            }
            showCommands();

        } else if (cmd == "listerutilisateurs") {
            if (auto admin = dynamic_cast<Administrateur*>(currentUser.get())) {
                admin->listerUtilisateurs();
            } else {
                std::cout << "[Erreur] Vous n'avez pas le droit de lister les utilisateurs.\n";
            }
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

void Mediatheque::displayRessourceDetails(const Ressource* ressource) const {
    std::cout << "ID: " << ressource->getId() 
              << " | Type: " << ressource->getType()
              << " | Titre: " << ressource->getTitre()
              << " | Auteur: " << ressource->getAuteur()
              << " | Etat: " << ressource->getEtat();
    
    // Affichage des détails spécifiques selon le type
    std::string type = ressource->getType();
    std::transform(type.begin(), type.end(), type.begin(), ::tolower);

    if (type == "livre") {
        const Livre* livre = dynamic_cast<const Livre*>(ressource);
        if (livre) {
            std::cout << " | Année: " << livre->getAnnee()
                      << " | Pages: " << livre->getNbPages()
                      << " | Collection: " << livre->getCollection()
                      << " | Résumé: " << livre->getResume();
        }
    } else if (type == "cd") {
        const CD* cd = dynamic_cast<const CD*>(ressource);
        if (cd) {
            std::cout << " | Durée: " << cd->getDuree() << "min"
                      << " | Maison: " << cd->getMaison()
                      << " | Pistes: " << cd->getNbPistes();
        }
    } else if (type == "revue") {
        const Revue* revue = dynamic_cast<const Revue*>(ressource);
        if (revue) {
            std::cout << " | Année: " << revue->getAnnee()
                      << " | Pages: " << revue->getNbPage()
                      << " | Collection: " << revue->getCollection()
                      << " | Éditeur: " << revue->getEditeur()
                      << " | Articles: " << revue->getArticles().size();
        }
    } else if (type == "dvd") {
        const DVD* dvd = dynamic_cast<const DVD*>(ressource);
        if (dvd) {
            std::cout << " | Durée: " << dvd->getDuree() << "min"
                      << " | Maison: " << dvd->getMaison()
                      << " | Chapitres: " << dvd->getNbChapitres();
        }
    } else if (type == "vhs") {
        const VHS* vhs = dynamic_cast<const VHS*>(ressource);
        if (vhs) {
            std::cout << " | Durée: " << vhs->getDuree() << "min"
                      << " | Maison: " << vhs->getMaison();
        }
    }
    
    // Ajouter [non disponible] si emprunté
    if (ressource->getEtat() == "Emprunte") {
        std::cout << " [non disponible]";
    }
    std::cout << "\n";
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
            displayRessourceDetails(ressource.get());
        }
    } else {
        // Afficher les résultats de recherche
        std::cout << "=== Résultats de recherche ===\n";
        for (const auto& ressource : searchResults) {
            displayRessourceDetails(ressource);
        }
    }
}

void Mediatheque::searchRessources(const std::string& query) {
    searchResults.clear();
    
    if (query.empty()) {
        std::cout << "Veuillez spécifier une chaîne de recherche.\n";
        return;
    }
    
    // Recherche dans tous les attributs selon le type
    // Recherche sensible à la casse (on utilise la query fournie)
    std::string queryStr = query;
    
    for (const auto& ressource : ressources) {
        bool found = false;
        
        // Recherche dans les attributs de base
        std::string titre = ressource->getTitre();
        std::string auteur = ressource->getAuteur();
        std::string etat = ressource->getEtat();
    // recherche sensible à la casse : on garde titre/auteur/etat comme fournis
        
        if (titre.find(queryStr) != std::string::npos || 
            auteur.find(queryStr) != std::string::npos ||
            etat.find(queryStr) != std::string::npos) {
            found = true;
        }
        
        // Recherche dans les attributs spécifiques selon le type
        if (!found) {
            if (auto livre = dynamic_cast<Livre*>(ressource.get())) {
                std::string collection = livre->getCollection();
                std::string resume = livre->getResume();
                // garder collection/resume tels quels
                if (collection.find(queryStr) != std::string::npos ||
                    resume.find(queryStr) != std::string::npos ||
                    std::to_string(livre->getAnnee()).find(queryStr) != std::string::npos) {
                    found = true;
                }
            } else if (auto cd = dynamic_cast<CD*>(ressource.get())) {
                std::string maison = cd->getMaison();
                // garder maison tel quel
                if (maison.find(queryStr) != std::string::npos) {
                    found = true;
                }
            } else if (auto revue = dynamic_cast<Revue*>(ressource.get())) {
                std::string collection = revue->getCollection();
                std::string resume = revue->getResume();
                std::string editeur = revue->getEditeur();
                // garder collection/resume/editeur tels quels
                if (collection.find(queryStr) != std::string::npos ||
                    resume.find(queryStr) != std::string::npos ||
                    editeur.find(queryStr) != std::string::npos ||
                    std::to_string(revue->getAnnee()).find(queryStr) != std::string::npos) {
                    found = true;
                }
            } else if (auto dvd = dynamic_cast<DVD*>(ressource.get())) {
                std::string maison = dvd->getMaison();
                // garder maison tel quel
                if (maison.find(queryStr) != std::string::npos) {
                    found = true;
                }
            } else if (auto vhs = dynamic_cast<VHS*>(ressource.get())) {
                std::string maison = vhs->getMaison();
                // garder maison tel quel
                if (maison.find(queryStr) != std::string::npos) {
                    found = true;
                }
            }
        }
        
        if (found) {
            searchResults.push_back(ressource.get());
        }
    }
    
    std::cout << "Recherche terminée. " << searchResults.size() << " résultat(s) trouvé(s).\n";
    
    // Afficher directement les résultats
    if (!searchResults.empty()) {
        std::cout << "=== Résultats de la recherche ===\n";
        for (const auto& ressource : searchResults) {
            displayRessourceDetails(ressource);
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
        
        // On utilise le type tel quel dans le fichier (ex: "livre" ou "Livre")
        // Si nécessaire, le fichier doit contenir les types exacts correspondants.
        
        if (type == "livre" or type == "Livre") {
            int id, annee, nbPages;
            std::string titre, auteur, etat, collection, resume;
            
            if (iss >> id >> titre >> auteur >> etat >> annee >> nbPages >> collection >> resume) {
                auto livre = std::make_unique<Livre>(id, titre, auteur, etat, annee, nbPages, collection, resume);
                ressources.push_back(std::move(livre));
                count++;
            }
        } else if (type == "cd" or type == "CD") {
            int id, duree, nbPistes;
            std::string titre, auteur, etat, maison;
            
            if (iss >> id >> titre >> auteur >> etat >> duree >> maison >> nbPistes) {
                auto cd = std::make_unique<CD>(id, titre, auteur, etat, duree, maison, nbPistes);
                ressources.push_back(std::move(cd));
                count++;
            }
        } else if (type == "revue" or type == "Revue") {
            int id, annee, nbPages, nbArticles;
            std::string titre, auteur, etat, collection, resume, editeur;
            
            if (iss >> id >> titre >> auteur >> etat >> annee >> nbPages >> collection >> resume >> editeur >> nbArticles) {
                // Pour simplifier, on crée un vecteur d'articles vide
                std::vector<std::string> articles;
                auto revue = std::make_unique<Revue>(id, titre, auteur, etat, annee, nbPages, collection, resume, editeur, articles);
                ressources.push_back(std::move(revue));
                count++;
            }
        } else if (type == "dvd" or type == "DVD") {
            int id, duree, nbChapitres;
            std::string titre, auteur, etat, maison;
            
            if (iss >> id >> titre >> auteur >> etat >> duree >> maison >> nbChapitres) {
                auto dvd = std::make_unique<DVD>(id, titre, auteur, etat, duree, maison, nbChapitres);
                ressources.push_back(std::move(dvd));
                count++;
            }
        } else if (type == "vhs" or type == "VHS") {
            int id, duree;
            std::string titre, auteur, etat, maison;
            
            if (iss >> id >> titre >> auteur >> etat >> duree >> maison) {
                auto vhs = std::make_unique<VHS>(id, titre, auteur, etat, duree, maison);
                ressources.push_back(std::move(vhs));
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
    // écrire le type tel quel
    file << type << " " 
             << ressource->getId() << " "
             << ressource->getTitre() << " "
             << ressource->getAuteur() << " "
             << ressource->getEtat();
        
        // Ajouter des détails spécifiques selon le type
        if (auto livre = dynamic_cast<Livre*>(ressource.get())) {
            file << " " << livre->getAnnee() 
                 << " " << livre->getNbPages() 
                 << " " << livre->getCollection() 
                 << " " << livre->getResume();
        } else if (auto cd = dynamic_cast<CD*>(ressource.get())) {
            file << " " << cd->getDuree() 
                 << " " << cd->getMaison() 
                 << " " << cd->getNbPistes();
        } else if (auto revue = dynamic_cast<Revue*>(ressource.get())) {
            file << " " << revue->getAnnee() 
                 << " " << revue->getNbPages() 
                 << " " << revue->getCollection() 
                 << " " << revue->getResume() 
                 << " " << revue->getEditeur() 
                 << " " << revue->getArticles().size();
        } else if (auto dvd = dynamic_cast<DVD*>(ressource.get())) {
            file << " " << dvd->getDuree() 
                 << " " << dvd->getMaison() 
                 << " " << dvd->getNbChapitres();
        } else if (auto vhs = dynamic_cast<VHS*>(ressource.get())) {
            file << " " << vhs->getDuree() 
                 << " " << vhs->getMaison();
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
