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
        std::cout << " - " << ressource->getTitre() << std::endl;
    }
}

void Utilisateur::search(const std::string& q) {
    std::cout << "search(" << q << ")" << std::endl;
}

void Utilisateur::show(int id) {
    std::cout << "show(" << id << ")" << std::endl;
}

void Utilisateur::borrow(Mediatheque& mediatheque, int id) {
    // --- (3a) Vérifier si la ressource existe encore dans la médiathèque ---
    const auto& ressources = mediatheque.getRessources(); // lecture seule ok
    bool trouve = false;
    for (const auto& r : ressources) {
        // Hypothèse simple : Ressource a getId(); sinon adapte le nom de l'accesseur
        if (r->getId() == id) {
            trouve = true;
            break;
        }
    }
    if (!trouve) {
        std::cout << "[borrow] Ressource " << id << " introuvable dans la médiathèque." << std::endl;
        return;
    }

    // --- (3b) Éviter les doublons côté utilisateur ---
    for (int borrowedId : emprunts) {
        if (borrowedId == id) {
            std::cout << "[borrow] Ressource " << id << " déjà empruntée par cet utilisateur." << std::endl;
            return;
        }
    }

    // --- (3c) Ajouter dans la liste d'emprunts de l'utilisateur ---
    emprunts.push_back(id);

    // --- (3d) Retirer la ressource de la médiathèque ---
    mediatheque.deleteResource(id);

    // --- (3e) Feedback simple ---
    std::cout << "[borrow] OK : l'utilisateur " << this->id
              << " a emprunté la ressource " << id << "." << std::endl;
}