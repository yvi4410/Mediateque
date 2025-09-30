#pragma once
#include <iostream>
#include <string>
#include <vector>

class Mediatheque;

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

    // Référence vers la médiatèque
    void setMediatheque(Mediatheque* media) { mediatheque = media; }

    // Méthodes du diagramme (placeholders) - déclarations seulement
    virtual void add(const std::string& type);
    virtual void list();
    virtual void search(const std::string& q);
    virtual void show(int idRessource);
    virtual void borrow(int idRessource);
    virtual void showBorrow(); // Afficher les emprunts

    // Commandes réservées aux administrateurs mais exposées polimorphiquement
    // Par défaut l'utilisateur n'a pas le droit — les administrateurs override.
    virtual void load(const std::string& filename);
    virtual void save(const std::string& filename);
    virtual void clear();
    virtual void deleteById(int id);
    virtual void ajouterUtilisateur(const Utilisateur& u);
    virtual void supprimerUtilisateur(int id);
    virtual void reset();
    virtual void listerUtilisateurs();

protected:
    Mediatheque* mediatheque = nullptr;
};
