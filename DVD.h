/*
class DVD {
    +nbChapitres: int
}
*/

#pragma once
#include "RessourceDigitaleAV.h"

class DVD : public RessourceDigitaleAV {
private:
    int nbChapitres;

public:
    DVD(int id, std::string titre, std::string auteur, std::string etat,
        int duree, std::string maison, int nbChapitres);

    int getNbChapitres() const;
    void setNbChapitres(int n);

    std::string getType() const override { return "DVD"; }
};