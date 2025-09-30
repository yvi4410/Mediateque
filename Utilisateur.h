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

    // Méthodes du diagramme (placeholders) - déclarations seulement
    virtual void add(const std::string& type);
    virtual void list();
    virtual void search(const std::string& q);
    virtual void show(int idRessource);
    virtual void borrow(int idRessource);
};
