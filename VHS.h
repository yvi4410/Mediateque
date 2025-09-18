#pragma once
#include <string>
#include "RessourceDigitaleAV.h"

class VHS : public RessourceDigitaleAV {
public:
    VHS(int id, std::string titre, std::string auteur, std::string etat,
        int duree, std::string maisonProduction);
};
