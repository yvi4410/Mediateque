#pragma once
#include "Utilisateur.h"

class Administrateur : public Utilisateur {
public:
    ~Administrateur() override = default;

    // L'admin a le droit d'ajouter
    void add() override;
};
