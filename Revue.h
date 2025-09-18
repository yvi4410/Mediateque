#pragma once
#include <string>
#include "RessourcePapier.h"

class Revue : public RessourcePapier {
protected:
    std::string editeur;
    int nbArticles;
    std::string nomsArticles;

public:
    Revue(int id, std::string titre, std::string auteur, std::string etat,
          int annee, int nbPage, std::string collection, std::string resume,
          std::string editeur, int nbArticles, std::string nomsArticles);
};
