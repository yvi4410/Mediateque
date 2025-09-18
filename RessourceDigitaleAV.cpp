#include "RessourceDigitaleAV.h"

RessourceDigitaleAV::RessourceDigitaleAV(int id, std::string titre, std::string auteur,
     std::string etat, int duree, std::string maisonProduction)
    : Ressource(id, titre, auteur, etat), duree(duree), maisonProduction(maisonProduction) {}
