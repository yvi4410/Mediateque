#pragma once
#include <string>
#include "RessourceDigitaleAV.h"

class DVD : public RessourceDigitaleAV {
protected:
    int nbChapitres;

public:
    DVD(int id, std::string titre, std::string auteur, std::string etat,
        int duree, std::string maisonProduction, int nbChapitres);
};
