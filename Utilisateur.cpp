#include "Utilisateur.h"
#include "Mediatheque.h"
#include <iostream>

void Utilisateur::add(const std::string& type) {
	std::cout << "[Erreur] Vous n'avez pas le droit d'ajouter une ressource (type=" << type << ").\n";
}

void Utilisateur::list() {
	// Cette méthode n'est plus utilisée - voir Mediatheque::listRessources()
	std::cout << "[Info] Utilisation de la commande 'list' directement.\n";
}

void Utilisateur::search(const std::string& q) {
	// Cette méthode n'est plus utilisée - voir Mediatheque::searchRessources()
	std::cout << "[Info] Utilisation de la commande 'search' directement.\n";
}

void Utilisateur::show(int idRessource) {
	// Cette méthode n'est plus utilisée - voir Mediatheque::showRessource()
	std::cout << "[Info] Utilisation de la commande 'show' directement.\n";
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

// Admin commands - par défaut l'utilisateur ordinaire n'a pas les droits
void Utilisateur::load(const std::string&) {
	// Maintenant permis - la vraie logique est dans Mediatheque::loadFromFile
	std::cout << "[Utilisateur] Chargement des données autorisé.\n";
}

void Utilisateur::save(const std::string&) {
	std::cout << "[Erreur] Vous n'avez pas le droit de sauvegarder des données.\n";
}

void Utilisateur::clear() {
	std::cout << "[Erreur] Vous n'avez pas le droit de vider les données.\n";
}

void Utilisateur::deleteById(int) {
	std::cout << "[Erreur] Vous n'avez pas le droit de supprimer une ressource.\n";
}

void Utilisateur::ajouterUtilisateur(const Utilisateur&) {
	std::cout << "[Erreur] Vous n'avez pas le droit d'ajouter un utilisateur.\n";
}

void Utilisateur::supprimerUtilisateur(int) {
	std::cout << "[Erreur] Vous n'avez pas le droit de supprimer un utilisateur.\n";
}

void Utilisateur::reset() {
	std::cout << "[Erreur] Vous n'avez pas le droit de remettre à zéro.\n";
}

void Utilisateur::listerUtilisateurs() {
	std::cout << "[Erreur] Vous n'avez pas le droit de lister les utilisateurs.\n";
}
