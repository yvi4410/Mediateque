#pragma once
#include <iostream>
#include <string>
#include <vector>

class Utilisateur {
public:
    // Champs publics (selon le diagramme, + = public)
    int id = 0;
    std::string prenom;
    std::string nom;
    std::vector<int> emprunts; // Ressource[*] => ids de ressources (placeholder)

    virtual ~Utilisateur() = default;

    // Constructeurs ultra simples
    Utilisateur() = default;
    Utilisateur(int id_, std::string p, std::string n)
        : id(id_), prenom(std::move(p)), nom(std::move(n)) {}

    // Méthodes du diagramme (placeholders)
    virtual void add(const std::string& type) {
        std::cout << "[Erreur] Vous n'avez pas le droit d'ajouter une ressource (type=" << type << ").\n";
    }

    virtual void list() {
        std::cout << "[Utilisateur] list() -> placeholder: afficherait les ressources disponibles.\n";
    }

    virtual void search(const std::string& q) {
        std::cout << "[Utilisateur] search(\"" << q << "\") -> placeholder: rechercherait dans les ressources.\n";
    }

    virtual void show(int idRessource) {
        std::cout << "[Utilisateur] show(" << idRessource << ") -> placeholder: afficherait les détails.\n";
    }

    virtual void borrow(int idRessource) {
        emprunts.push_back(idRessource);
        std::cout << "[Utilisateur] borrow(" << idRessource << ") -> placeholder: emprunt simulé.\n";
    }
};
