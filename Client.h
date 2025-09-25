#pragma once
#include "Utilisateur.h"

class Client : public Utilisateur{
public:
    using Utilisateur::Utilisateur; // constructeur d'utilisateur
};
