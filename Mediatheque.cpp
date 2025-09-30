#include "Mediatheque.h"
#include "Utilisateur.h"
#include "Administrateur.h"
#include <iostream>
#include <algorithm>
#include <cctype>
#include <sstream>

void Mediatheque::setCurrentUser(std::unique_ptr<Utilisateur> user) {
    currentUser = std::move(user);
}

Utilisateur* Mediatheque::getCurrentUser() const {
    return currentUser.get();
}


void Mediatheque::dispatch() {
    std::string line;
    std::cout << "Commandes disponibles: add [type] | list | search <q> | show <id> | borrow <id> | "
              << "load <file> | save <file> | clear | delete <id> | ajouterUtilisateur <id> <prenom> <nom> | "
              << "supprimerUtilisateur <id> | reset | listerUtilisateurs | bye\n";

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
            if (currentUser) currentUser->list();
            else std::cout << "[Erreur] Aucun utilisateur connecté.\n";

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
            else {
                auto* admin = dynamic_cast<Administrateur*>(currentUser.get());
                if (admin) admin->load(arg);
                else std::cout << "[Erreur] Commande réservée aux administrateurs.\n";
            }

        } else if (cmd == "save") {
            if (!currentUser) { std::cout << "[Erreur] Aucun utilisateur connecté.\n"; }
            else {
                auto* admin = dynamic_cast<Administrateur*>(currentUser.get());
                if (admin) admin->save(arg);
                else std::cout << "[Erreur] Commande réservée aux administrateurs.\n";
            }

        } else if (cmd == "clear") {
            if (!currentUser) { std::cout << "[Erreur] Aucun utilisateur connecté.\n"; }
            else {
                auto* admin = dynamic_cast<Administrateur*>(currentUser.get());
                if (admin) admin->clear();
                else std::cout << "[Erreur] Commande réservée aux administrateurs.\n";
            }

        } else if (cmd == "delete") {
            if (!currentUser) { std::cout << "[Erreur] Aucun utilisateur connecté.\n"; }
            else {
                int id = arg.empty() ? -1 : std::stoi(arg);
                auto* admin = dynamic_cast<Administrateur*>(currentUser.get());
                if (admin) admin->deleteById(id);
                else std::cout << "[Erreur] Commande réservée aux administrateurs.\n";
            }

        } else if (cmd == "ajouterutilisateur") {
            if (!currentUser) { std::cout << "[Erreur] Aucun utilisateur connecté.\n"; }
            else {
                std::istringstream as(arg);
                int id; std::string prenom, nom;
                if (!(as >> id >> prenom >> nom)) {
                    std::cout << "Usage: ajouterUtilisateur <id> <prenom> <nom>\n";
                } else {
                    auto* admin = dynamic_cast<Administrateur*>(currentUser.get());
                    if (admin) {
                        Utilisateur u(id, prenom, nom);
                        admin->ajouterUtilisateur(u);
                    } else std::cout << "[Erreur] Commande réservée aux administrateurs.\n";
                }
            }

        } else if (cmd == "supprimerutilisateur") {
            if (!currentUser) { std::cout << "[Erreur] Aucun utilisateur connecté.\n"; }
            else {
                int id = arg.empty() ? -1 : std::stoi(arg);
                auto* admin = dynamic_cast<Administrateur*>(currentUser.get());
                if (admin) admin->supprimerUtilisateur(id);
                else std::cout << "[Erreur] Commande réservée aux administrateurs.\n";
            }

        } else if (cmd == "reset") {
            if (!currentUser) { std::cout << "[Erreur] Aucun utilisateur connecté.\n"; }
            else {
                auto* admin = dynamic_cast<Administrateur*>(currentUser.get());
                if (admin) admin->reset();
                else std::cout << "[Erreur] Commande réservée aux administrateurs.\n";
            }

        } else if (cmd == "listerutilisateurs") {
            if (!currentUser) { std::cout << "[Erreur] Aucun utilisateur connecté.\n"; }
            else {
                auto* admin = dynamic_cast<Administrateur*>(currentUser.get());
                if (admin) admin->listerUtilisateurs();
                else std::cout << "[Erreur] Commande réservée aux administrateurs.\n";
            }
        } else {
            std::cout << "Commande inconnue. Utilisez: add [type] | list | search <q> | show <id> | borrow <id> | bye\n";
        }
    }
}
