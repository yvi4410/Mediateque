#pragma once
#include "RessourceDigitaleAV.h"

class CD : public RessourceDigitaleAV {
private:
    int nbPistes;

public:
    CD(int id, std::string titre, std::string auteur, std::string etat,
       int duree, std::string maison, int nbPistes);

    int getNbPistes() const;
    void setNbPistes(int n);

    std::string getType() const override { return "CD"; }
};