#/*
#class RessourceNumeriqueFichier {
#    +type: string
#    +taille: int
#    +url: string
#}
#*/

#include "RessourceNumeriqueFichier.h"

RessourceNumeriqueFichier::RessourceNumeriqueFichier(int id, std::string titre, std::string auteur, std::string etat,
                                                     std::string typeFichier, int taille, std::string url)
    : Ressource(id, titre, auteur, etat), typeFichier(typeFichier), taille(taille), url(url) {}

std::string RessourceNumeriqueFichier::getTypeFichier() const {
    return typeFichier;
}

void RessourceNumeriqueFichier::setTypeFichier(const std::string& t) {
    typeFichier = t;
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