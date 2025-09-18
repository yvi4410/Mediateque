#pragma once
#include <string>
#include "Ressource.h"

class RessourceNumeriqueFichier : public Ressource {
protected:
    std::string type;
    int taille;
    std::string url;

public:
    RessourceNumeriqueFichier(int id, std::string titre, std::string auteur, std::string etat,
                              std::string type, int taille, std::string url);
};
