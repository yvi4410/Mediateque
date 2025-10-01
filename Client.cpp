#include "Client.h"
#include <iostream>

void Client::add(const std::string&) {
    std::cout << "[Erreur] Vous n'avez pas le droit d'ajouter une ressource." << std::endl;
}

void Client::load(const std::string&) {
    // Lecture seule autorisée pour les clients
    std::cout << "[Client] Chargement des données autorisé." << std::endl;
}
