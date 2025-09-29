#pragma once
#include "Utilisateur.h"

class Client : public Utilisateur {
public:
    ~Client() override = default;
    // Hérite des placeholders Utilisateur (pas d'add autorisé, etc.)
};
