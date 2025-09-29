#pragma once
#include "Utilisateur.h"

class Client : public Utilisateur {
public:
    ~Client() override = default;
    // Hérite du comportement par défaut de Utilisateur::add()
};
