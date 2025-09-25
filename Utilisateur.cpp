#/*
#class Utilisateur {
#    +id: int
#    +prenom: string
#    +nom: string
#    +emprunts: Ressource[*]
#    +list()
#    +search(q: string)
#    +show(id: int)
#    +borrow(id: int)
#}
#*/

#include "Utilisateur.h"
#include "Mediatheque.h"
#include <vector>
#include <iostream>

/*
class Utilisateur {
	    +id: int
	    +prenom: string
	    +nom: string
	    +ressources: Ressource
	    +list()
	    +search(q: string)
	    +show(id: int)
	    +borrow(id: int)
    }
*/

Utilisateur::Utilisateur(int id, const std::string& prenom, const std::string& nom)
    : id(id), prenom(prenom), nom(nom) {}

Utilisateur::~Utilisateur() = default;

void Utilisateur::bye() {
    std::cout << "Au revoir !" << std::endl;
}

void Utilisateur::list(const Mediatheque& mediatheque) {
    (void)mediatheque; // placeholder
    std::cout << "[Utilisateur::list] placeholder - afficher la liste des ressources." << std::endl;
}

void Utilisateur::search(const std::string& q) {
    std::cout << "[Utilisateur::search] placeholder pour: " << q << std::endl;
}

void Utilisateur::show(int id) {
    std::cout << "[Utilisateur::show] placeholder pour id=" << id << std::endl;
}

void Utilisateur::borrow(Mediatheque& mediatheque, int id) {
    // placeholder qui utilise l'API publique de Mediatheque
    const auto& ressources = mediatheque.getRessources();
    bool trouv = false;
    for (const auto& r : ressources) {
        if (r && r->getId() == id) { trouv = true; break; }
    }
    if (!trouv) {
        std::cout << "[Utilisateur::borrow] ressource introuvable: " << id << std::endl;
        return;
    }
    addEmprunt(id);
    // delegate removal to mediatheque public API (nom exact: deleteResource)
    mediatheque.deleteResource(id);
    std::cout << "[Utilisateur::borrow] Emprunt enregistre: " << id << std::endl;
}

int Utilisateur::getId() const { return id; }
const std::string& Utilisateur::getNom() const { return nom; }
const std::string& Utilisateur::getPrenom() const { return prenom; }
const std::vector<int>& Utilisateur::getEmprunts() const { return emprunts; }

void Utilisateur::addEmprunt(int id) { emprunts.push_back(id); }

bool Utilisateur::removeEmprunt(int id) {
    for (auto it = emprunts.begin(); it != emprunts.end(); ++it) {
        if (*it == id) { emprunts.erase(it); return true; }
    }
    return false;
}