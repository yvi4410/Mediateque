#/*
#class Mediatheque {
#    +currentUser: Utilisateur
#    +ressources: Ressource
#    +getRessource()
#    +deleteRessource(id: int)
#    +run()
#    +dispatch(cmd: string)
#}
#*/

#include "Mediatheque.h"
#include "Ressource.h"
#include "Administrateur.h"
#include "Client.h"
#include "Utilisateur.h"
#include <iostream>
#include <sstream>
#include <algorithm>
#include <cctype>

/*
class Mediatheque {
	    +currentUser: Utilisateur
	    +ressources: Ressource
		+getRessource()
	    +deleteRessource(id: int)
	    +run()
	    +dispatch(cmd: string)
    }
*/

// Minimal, clean implementations (placeholders) following the class diagram

const std::vector<std::unique_ptr<Ressource>>& Mediatheque::getRessources() const {
    return ressources;
}

Ressource* Mediatheque::getRessource(int id) const {
    for (const auto& r : ressources) {
        if (r && r->getId() == id) return r.get();
    }
    return nullptr;
}

void Mediatheque::deleteRessource(int /*id*/) {
    // placeholder: supprimer une ressource
}

void Mediatheque::run() {
    // placeholder: boucle principale (implémentation interactive ou tests)
    dispatch();
}

void Mediatheque::dispatch() {
    std::string line;
    while (true) {
        std::cout << "> ";
        if (!std::getline(std::cin, line)) break;

        std::istringstream iss(line);
        std::string cmd;
        iss >> cmd;
    // lowercase comparison
    std::transform(cmd.begin(), cmd.end(), cmd.begin(), [](unsigned char c){ return static_cast<char>(::tolower(c)); });

        if (cmd == "bye") {
            // exit loop
            break;
        }

        if (cmd == "add") {
            std::string type;
            iss >> type;
            auto admin = dynamic_cast<Administrateur*>(currentUser.get());
            if (!admin) {
                std::cout << "Erreur: vous n'etes pas administrateur." << std::endl;
                continue;
            }
            admin->add(type);
            std::cout << "[Mediatheque] add executed (placeholder)." << std::endl;
            continue;
        }

        std::cout << "Commande inconnue: " << cmd << std::endl;
    }
}

void Mediatheque::dispatch(const std::string& /*cmd*/) {
    // placeholder: exécuter une commande textuelle
}

Utilisateur* Mediatheque::getCurrentUser() const { return currentUser.get(); }

void Mediatheque::setCurrentUser(std::unique_ptr<Utilisateur> user) { currentUser = std::move(user); }