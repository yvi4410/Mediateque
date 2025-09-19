#pragma once
#include <string>
#include "RessourcePapier.h"
#include <vector>

class Revue : public RessourcePapier {
public:
    Revue(int id, std::string titre, std::string auteur, std::string etat,
          int annee, int nbPage, std::string collection, std::string resume,
          std::string editeur, std::vector<std::string> nomsArticles);

    std::string getEditeur() const;
    std::vector<std::string> getArticles() const;

private:
    std::string editeur;
    std::vector<std::string> articles;
};