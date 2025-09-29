#pragma once
#include "Utilisateur.h"

class Administrateur : public Utilisateur {
public:
    ~Administrateur() override = default;

    // Spécifiques admin (diagramme)
    void add(const std::string& type) override;
    void load(const std::string& filename);
    void save(const std::string& filename);
    void clear();
    void deleteById(int id);
    void ajouterUtilisateur(const Utilisateur& u);
    void supprimerUtilisateur(int id);
    void reset();
    void listerUtilisateurs();
};
