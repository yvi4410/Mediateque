#include "Administrateur.h"
#include <iostream>
#include <algorithm> // pour std::remove_if
#include <fstream>   // pour load/save si tu fais de la sérialisation simple



    Administrateur::Administrateur() {
    }

    Administrateur::~Administrateur() {
    }

    void Administrateur::add(const std::string& type) {
        std::cout << "[Admin] Ajout d'une ressource de type : " << type << std::endl;
        // Implémentation dépendante de la logique des ressources à ajouter
        // Ex : switch sur type pour créer un Livre, CD, etc. (non montré ici)
    }

    void Administrateur::load(const std::string& filename) {
        std::cout << "[Admin] Chargement des données depuis : " << filename << std::endl;
        // Exemple : chargement fictif
        // Tu peux remplacer ça par un vrai système de sérialisation plus tard
    }

    void Administrateur::save(const std::string& filename) {
        std::cout << "[Admin] Sauvegarde des données vers : " << filename << std::endl;
        // Exemple : sauvegarde fictive
    }

    void Administrateur::clear() {
        std::cout << "[Admin] Nettoyage des ressources" << std::endl;
        // À compléter selon comment tu gères les ressources
    }

    void Administrateur::deleteById(int id) {
        std::cout << "[Admin] Suppression de la ressource avec ID : " << id << std::endl;
        // Même chose que clear : à implémenter plus tard si tu gères les ressources dans une liste
    }

    void Administrateur::ajouterUtilisateur(const Utilisateur& u) {
        utilisateurs.push_back(u);
        std::cout << "[Admin] Utilisateur ajouté : " << u.getNom() << " " << u.getPrenom() << std::endl;
    }

    void Administrateur::supprimerUtilisateur(int id) {
        auto it = std::remove_if(utilisateurs.begin(), utilisateurs.end(),
            [id](const Utilisateur& u) {
                return u.getId() == id;
            });
        if (it != utilisateurs.end()) {
            utilisateurs.erase(it, utilisateurs.end());
            std::cout << "[Admin] Utilisateur avec ID " << id << " supprimé." << std::endl;
        } else {
            std::cout << "[Admin] Aucun utilisateur trouvé avec ID " << id << std::endl;
        }
    }

    void Administrateur::reset() {
        utilisateurs.clear();
        std::cout << "[Admin] Liste des utilisateurs réinitialisée." << std::endl;
        // Ajoute aussi un reset des ressources si tu les ajoutes dans cette classe
    }

    void Administrateur::listerUtilisateurs() {
        std::cout << "[Admin] Liste des utilisateurs :" << std::endl;
        for (const auto& u : utilisateurs) {
            std::cout << " - ID: " << u.getId() << ", Nom: " << u.getNom()
                      << ", Prénom: " << u.getPrenom() << std::endl;
        }
    }

