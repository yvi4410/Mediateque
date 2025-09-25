/*
class RessourceNumeriqueFichier {
    +type: string
    +taille: int
    +url: string
}
*/

#pragma once
#include "Ressource.h"

class RessourceNumeriqueFichier : public Ressource {
private:
    std::string typeFichier;
    int taille;
    std::string url;

public:
    RessourceNumeriqueFichier(int id, std::string titre, std::string auteur, std::string etat,
                               std::string typeFichier, int taille, std::string url);

    std::string getTypeFichier() const;
    void setTypeFichier(const std::string& t);

    int getTaille() const;
    void setTaille(int t);

    std::string getUrl() const;
    void setUrl(const std::string& u);

    std::string getType() const override { return "Fichier"; }
};