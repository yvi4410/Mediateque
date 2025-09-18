#pragma once
#include <string>
#include "RessourcePapier.h"

class Livre : public RessourcePapier {
public:
    Livre(int id, std::string titre, std::string auteur, std::string etat, 
        int annee, int nbPage, std::string collection, std::string resume);
};
