#include "RessourceNumeriqueFichier.h"

RessourceNumeriqueFichier::RessourceNumeriqueFichier(int id, std::string titre, std::string auteur, std::string etat,
                                                     std::string type, int taille, std::string url)
    : Ressource(id, titre, auteur, etat), type(type), taille(taille), url(url) {}