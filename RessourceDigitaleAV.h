/*
class RessourceDigitaleAV {
    +duree: int
    +maisonProduction: string
}
*/

#pragma once
#include "Ressource.h"

class RessourceDigitaleAV : public Ressource {
protected:
    int duree;
    std::string maison;

public:
    RessourceDigitaleAV(int id, std::string titre, std::string auteur, std::string etat,
                        int duree, std::string maison);

    int getDuree() const;
    void setDuree(int d);

    std::string getMaison() const;
    void setMaison(const std::string& m);
};