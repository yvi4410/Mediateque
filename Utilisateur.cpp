#include "Utilisateur.h"
#include <iostream>

void Utilisateur::add(const std::string& type) {
	std::cout << "[Erreur] Vous n'avez pas le droit d'ajouter une ressource (type=" << type << ").\n";
}

void Utilisateur::list() {
	std::cout << "[Utilisateur] list() -> placeholder: afficherait les ressources disponibles.\n";
}

void Utilisateur::search(const std::string& q) {
	std::cout << "[Utilisateur] search(\"" << q << "\") -> placeholder: rechercherait dans les ressources.\n";
}

void Utilisateur::show(int idRessource) {
	std::cout << "[Utilisateur] show(" << idRessource << ") -> placeholder: afficherait les détails.\n";
}

void Utilisateur::borrow(int idRessource) {
	emprunts.push_back(idRessource);
	std::cout << "[Utilisateur] borrow(" << idRessource << ") -> placeholder: emprunt simulé.\n";
}
