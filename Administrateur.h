#pragma once
#include "Utilisateur.h"

class Administrateur : public Utilisateur {
public:
    ~Administrateur() override = default;

    void add(const std::string& type) override;
    void ajouterUtilisateur(const Utilisateur& u);
    void supprimerUtilisateur(int id);
    void listerUtilisateurs();
};
