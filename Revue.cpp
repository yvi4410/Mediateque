#include "Revue.h"
#include <string>
#include "RessourcePapier.h"
#include <vector>

Revue::Revue(int id, std::string titre, std::string auteur, std::string etat,
             int annee, int nbPage, std::string collection, std::string resume,
             std::string editeur, std::vector<std::string> nomsArticles)
    : RessourcePapier(id, titre, auteur, etat, annee, nbPage, collection, resume),
      editeur(editeur), articles(nomsArticles) {}

std::string Revue::getEditeur() const {
    return editeur;
}

std::vector<std::string> Revue::getArticles() const {
    return articles;
}

int Revue::getNbPages() const {
    return nbPage;
}

void Revue::setNbPages(int n) {
    nbPage = n;
}

void Revue::setEditeur(const std::string& e) {
    editeur = e;
}

void Revue::setArticles(const std::vector<std::string>& a) {
    articles = a;
}