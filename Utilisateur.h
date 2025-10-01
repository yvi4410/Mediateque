#pragma once
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

    // Méthodes du diagramme - déclarations seulement
    virtual void add(const std::string& type);
    virtual void borrow(int idRessource);
    virtual void showBorrow(); // Afficher les emprunts
    virtual void load(const std::string& filename); // Accessible aux clients et admins

protected:
    Mediatheque* mediatheque = nullptr;
};
