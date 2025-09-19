#include "RessourceDigitaleAV.h"

RessourceDigitaleAV::RessourceDigitaleAV(int id, std::string titre, std::string auteur,
     std::string etat, int duree, std::string maisonProduction)
    : Ressource(id, titre, auteur, etat), duree(duree), maison(maison) {}

int RessourceDigitaleAV::getDuree() const {
    return duree;
}

void RessourceDigitaleAV::setDuree(int d) {
    duree = d;
}

std::string RessourceDigitaleAV::getMaison() const {
    return maison;
}

void RessourceDigitaleAV::setMaison(const std::string& m) {
    maison = m;
}
