/*
class Revue {
    +editeur: string
    +nbArticles: int
    +nomsArticles: string[]
}
*/

#pragma once
#include "RessourcePapier.h"
#include <vector>

class Revue : public RessourcePapier {
private:
    std::string editeur;
    std::vector<std::string> articles;

public:
    Revue(int id, std::string titre, std::string auteur, std::string etat,
          int annee, int nbPages, std::string collection, std::string resume,
          std::string editeur, std::vector<std::string> articles);

    std::string getEditeur() const;
    void setEditeur(const std::string& e);

    std::vector<std::string> getArticles() const;

    int getNbPages() const;

    void setNbPages(int n);

    void setArticles(const std::vector<std::string>& a);

    std::string getType() const override { return "Revue"; }
};