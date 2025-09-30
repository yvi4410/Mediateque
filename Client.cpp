#include "Client.h"
#include <iostream>

void Client::add(const std::string&) {
    std::cout << "[Erreur] Vous n'avez pas le droit d'ajouter une ressource.\n";
}

void Client::load(const std::string&) {
    // Maintenant permis pour les clients - lecture seule
    std::cout << "[Client] Chargement des données autorisé.\n";
}

void Client::save(const std::string&) {
    std::cout << "[Erreur] Vous n'avez pas le droit de sauvegarder des données.\n";
}

void Client::clear() {
    std::cout << "[Erreur] Vous n'avez pas le droit de vider les données.\n";
}

void Client::deleteById(int) {
    std::cout << "[Erreur] Vous n'avez pas le droit de supprimer une ressource.\n";
}

void Client::ajouterUtilisateur(const Utilisateur&) {
    std::cout << "[Erreur] Vous n'avez pas le droit d'ajouter un utilisateur.\n";
}

void Client::supprimerUtilisateur(int) {
    std::cout << "[Erreur] Vous n'avez pas le droit de supprimer un utilisateur.\n";
}

void Client::reset() {
    std::cout << "[Erreur] Vous n'avez pas le droit de remettre à zéro.\n";
}

void Client::listerUtilisateurs() {
    std::cout << "[Erreur] Vous n'avez pas le droit de lister les utilisateurs.\n";
}
