#pragma once
#include <string>
#include "Ressource.h"

class RessourceDigitaleAV : public Ressource {
    
protected:
    int duree;
    std::string maisonProduction;

public:
    RessourceDigitaleAV(int id, std::string titre, std::string auteur, std::string etat,
                        int duree, std::string maisonProduction);
};
