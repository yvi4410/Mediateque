#pragma once
#include "Utilisateur.h"

class Administrateur : public Utilisateur {
public:
    ~Administrateur() override = default;

    // Spécifiques admin (diagramme)
    void add(const std::string& type) override;
    
    // Méthodes admin-only (non présentes dans Utilisateur)
    void save(const std::string& filename);
    void clear();
    void deleteById(int id);
    void ajouterUtilisateur(const Utilisateur& u);
    void supprimerUtilisateur(int id);
    void reset();
    void listerUtilisateurs();
};
