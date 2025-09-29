#pragma once
#include <iostream>

class Utilisateur {
public:
    virtual ~Utilisateur() = default;

    // Action par défaut : pas le droit d'ajouter
    virtual void add() {
        std::cout << "[Erreur] Vous n'avez pas le droit d'ajouter une ressource.\n";
    }
};
