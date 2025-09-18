#pragma once
#include <string>
#include "RessourceDigitaleAV.h"

class CD : public RessourceDigitaleAV {
protected:
    int nbPistes;

public:
    CD(int id, std::string titre, std::string auteur, std::string etat,
       int duree, std::string maisonProduction, int nbPistes);
};
