/*
class VHS {
    // inherits from RessourceDigitaleAV
}
*/

#pragma once
#include "RessourceDigitaleAV.h"

class VHS : public RessourceDigitaleAV {
public:
    VHS(int id, std::string titre, std::string auteur, std::string etat,
        int duree, std::string maison);

    int getDuree() const;

    void setDuree(int d);

    std::string getMaison() const;

    void setMaison(const std::string &m);

    std::string getType() const override { return "VHS"; }
};