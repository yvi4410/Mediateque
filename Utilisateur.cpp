#include "Utilisateur.h"
#include "Mediatheque.h"
#include "Ressource.h"  
#include <iostream>

Utilisateur::Utilisateur(int id, const std::string& prenom, const std::string& nom)
    : id(id), prenom(prenom), nom(nom) {}

void Utilisateur::bye() {
    std::cout << "Au revoir !" << std::endl;
}

void Utilisateur::list(const Mediatheque& mediatheque) {
    const auto& ressources = mediatheque.getRessources();

    if (ressources.empty()) {
        std::cout << "(Aucune ressource disponible)" << std::endl;
        return;
    }

    std::cout << "Liste des ressources disponibles :" << std::endl;
    for (const auto& ressource : ressources) {
        std::cout << " - " << ressource->getRessourceTitle() << std::endl;
    }
}

void Utilisateur::search(const std::string& q) {
    std::cout << "search(" << q << ")" << std::endl;
}

void Utilisateur::show(int id) {
    std::cout << "show(" << id << ")" << std::endl;
}

void Utilisateur::borrow(int id) {
    std::cout << "borrow(" << id << ")" << std::endl;
}