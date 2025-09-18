
#pragma once
#include "Utilisateur.h"

namespace mediatheque {

class Administrateur : public Utilisateur {
public:
    Administrateur();
    ~Administrateur() override;

    // Méthodes spécifiques à l'administrateur ici
};

}