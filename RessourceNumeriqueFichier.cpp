#include "RessourceNumeriqueFichier.h"

RessourceNumeriqueFichier::RessourceNumeriqueFichier(int id, std::string titre, std::string auteur, std::string etat,
                                                     std::string type, int taille, std::string url)
    : Ressource(id, titre, auteur, etat), type(type), taille(taille), url(url) {}

std::string RessourceNumeriqueFichier::getTypeFichier() const {
    return type;
}

void RessourceNumeriqueFichier::setTypeFichier(const std::string& t) {
    type = t;
}

int RessourceNumeriqueFichier::getTaille() const {
    return taille;
}

void RessourceNumeriqueFichier::setTaille(int t) {
    taille = t;
}

std::string RessourceNumeriqueFichier::getUrl() const {
    return url;
}

void RessourceNumeriqueFichier::setUrl(const std::string& u) {
    url = u;
}
