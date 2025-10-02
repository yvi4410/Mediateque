#include "Utilisateur.h"
#include "Mediatheque.h"
#include <iostream>

void Utilisateur::add(const std::string& type) {
	std::cout << "[Erreur] Vous n'avez pas le droit d'ajouter une ressource (type=" << type << ").\n";
}

void Utilisateur::borrow(int idRessource) {
	if (!mediatheque) {
		std::cout << "[Erreur] Pas de médiatèque configurée.\n";
		return;
	}

	std::cout << "[Utilisateur] Tentative d'emprunt de la ressource ID " << idRessource << "\n";
	
	Ressource* ressource = mediatheque->findRessource(idRessource);
	if (!ressource) {
		std::cout << "[Erreur] Ressource avec ID " << idRessource << " introuvable.\n";
		return;
	}
	
	if (mediatheque->borrowRessource(idRessource)) {
		emprunts.push_back(idRessource);
		std::cout << "[Utilisateur] Emprunt réussi ! Ressource '" << ressource->getTitre() << "' empruntée.\n";
		std::cout << "[Info] Vous avez maintenant " << emprunts.size() << " emprunt(s).\n";
	} else {
		std::cout << "[Erreur] Cette ressource est déjà empruntée et non disponible.\n";
	}
}

void Utilisateur::showBorrow() {
	if (emprunts.empty()) {
		std::cout << "Aucun emprunt en cours.\n";
		return;
	}
	
	std::cout << "=== Vos emprunts ===\n";
	for (int id : emprunts) {
		Ressource* ressource = mediatheque->findRessource(id);
		if (ressource) {
			std::cout << "ID: " << ressource->getId() 
			          << " | Type: " << ressource->getType()
			          << " | Titre: " << ressource->getTitre()
			          << " | Auteur: " << ressource->getAuteur()
			          << " | Etat: " << ressource->getEtat() << "\n";
		} else {
			std::cout << "- Ressource ID: " << id << " (introuvable)\n";
		}
	}
	std::cout << "Total: " << emprunts.size() << " emprunt(s)\n";
}

void Utilisateur::load(const std::string& filename) {
	mediatheque->loadFromFile(filename);
}
