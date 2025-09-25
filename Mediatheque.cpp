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
    // interactive entry point (placeholder)
    std::cout << "[Mediatheque] dispatch() appelé (placeholder interactif)" << std::endl;
    // could call dispatch(cmd) in a loop when implemented
}

void Mediatheque::dispatch(const std::string& /*cmd*/) {
    // placeholder: exécuter une commande textuelle
}

Utilisateur* Mediatheque::getCurrentUser() const { return currentUser.get(); }

void Mediatheque::setCurrentUser(std::unique_ptr<Utilisateur> user) { currentUser = std::move(user); }