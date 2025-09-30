#include "Utilisateur.h"
#include <iostream>

void Utilisateur::add(const std::string& type) {
	std::cout << "[Erreur] Vous n'avez pas le droit d'ajouter une ressource (type=" << type << ").\n";
}

void Utilisateur::list() {
	// Cette méthode n'est plus utilisée - voir Mediatheque::listRessources()
	std::cout << "[Info] Utilisation de la commande 'list' directement.\n";
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

// Admin commands - par défaut l'utilisateur ordinaire n'a pas les droits
void Utilisateur::load(const std::string&) {
	std::cout << "[Erreur] Vous n'avez pas le droit de charger des données.\n";
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
