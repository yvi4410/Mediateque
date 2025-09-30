#include "Mediatheque.h"
#include "Utilisateur.h"
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

void Mediatheque::setCurrentUser(std::unique_ptr<Utilisateur> user) {
    currentUser = std::move(user);
    if (currentUser) {
        currentUser->setMediatheque(this);
    }
}

Utilisateur* Mediatheque::getCurrentUser() const {
    return currentUser.get();
}


void Mediatheque::dispatch() {
    std::string line;
    std::cout << "Commandes disponibles:\n>> add [type] \n>> list \n>> search <q> \n>> show <id> \n>> borrow <id> \n"
              << ">> load <file> \n>> save <file> \n>> clear \n>> delete <id> \n>> ajouterUtilisateur <id> <prenom> <nom> \n>> "
              << "supprimerUtilisateur <id> \n>> reset \n>> listerUtilisateurs \n>> bye\n";

    while (true) {
        std::cout << "> ";
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

        } else if (cmd == "list") {
            listRessources();

        } else if (cmd == "search") {
            if (currentUser) currentUser->search(arg);
            else std::cout << "[Erreur] Aucun utilisateur connecté.\n";

        } else if (cmd == "show") {
            int idR = arg.empty() ? -1 : std::stoi(arg);
            if (currentUser) currentUser->show(idR);
            else std::cout << "[Erreur] Aucun utilisateur connecté.\n";

        } else if (cmd == "borrow") {
            int idR = arg.empty() ? -1 : std::stoi(arg);
            if (currentUser) currentUser->borrow(idR);
            else std::cout << "[Erreur] Aucun utilisateur connecté.\n";

        } else if (cmd == "load") {
            if (!currentUser) { std::cout << "[Erreur] Aucun utilisateur connecté.\n"; }
            else currentUser->load(arg);

        } else if (cmd == "save") {
            if (!currentUser) { std::cout << "[Erreur] Aucun utilisateur connecté.\n"; }
            else currentUser->save(arg);

        } else if (cmd == "clear") {
            if (!currentUser) { std::cout << "[Erreur] Aucun utilisateur connecté.\n"; }
            else currentUser->clear();

        } else if (cmd == "delete") {
            if (!currentUser) { std::cout << "[Erreur] Aucun utilisateur connecté.\n"; }
            else {
                int id = arg.empty() ? -1 : std::stoi(arg);
                currentUser->deleteById(id);
            }

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

        } else if (cmd == "supprimerutilisateur") {
            if (!currentUser) { std::cout << "[Erreur] Aucun utilisateur connecté.\n"; }
            else {
                int id = arg.empty() ? -1 : std::stoi(arg);
                currentUser->supprimerUtilisateur(id);
            }

        } else if (cmd == "reset") {
            if (!currentUser) { std::cout << "[Erreur] Aucun utilisateur connecté.\n"; }
            else currentUser->reset();

        } else if (cmd == "listerutilisateurs") {
            if (!currentUser) { std::cout << "[Erreur] Aucun utilisateur connecté.\n"; }
            else currentUser->listerUtilisateurs();
        } else {
            std::cout << "Commande inconnue. Utilisez: add [type] | list | search <q> | show <id> | borrow <id> | bye\n";
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
                      << " | Etat: " << ressource->getEtat() << "\n";
        }
    } else {
        // Afficher seulement les résultats de recherche
        std::cout << "=== Résultats de recherche ===\n";
        for (const auto& ressource : searchResults) {
            std::cout << "ID: " << ressource->getId() 
                      << " | Type: " << ressource->getType()
                      << " | Titre: " << ressource->getTitre()
                      << " | Auteur: " << ressource->getAuteur()
                      << " | Etat: " << ressource->getEtat() << "\n";
        }
    }
}
