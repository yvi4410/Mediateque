#include "Ressource.h"

Ressource::Ressource(int id, std::string titre, std::string auteur, std::string etat)
                : id(id), titre(titre), auteur(auteur), etat(etat) {}

Ressource::~Ressource() {}

int Ressource::getId() const {
    return id;
}
std::string Ressource::getRessourceTitle() const {
    return titre;
}
std::string Ressource::getAuteur() const {
    return auteur;
}
std::string Ressource::getEtat() const {
    return etat;
}