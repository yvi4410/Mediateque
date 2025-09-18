#pragma once
#include <string>
#include "Ressource.h"

class RessourcePapier : public Ressource {
protected:
    int annee;
    int nbPage;
    std::string collection;
    std::string resume;

public:
    RessourcePapier(int id, std::string titre, std::string auteur, std::string etat,
                    int annee, int nbPage, std::string collection, std::string resume);
};
