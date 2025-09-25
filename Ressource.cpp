#include "Ressource.h"

Ressource::Ressource(int id, std::string titre, std::string auteur, std::string etat)
    : id(id), titre(titre), auteur(auteur), etat(etat) {}

Ressource::~Ressource() {}

int Ressource::getId() const {
    return id;
}

std::string Ressource::getTitre() const {
    return titre;
}

std::string Ressource::getAuteur() const {
    return auteur;
}

std::string Ressource::getEtat() const {
    return etat;
}

void Ressource::setId(int newId) {
    id = newId;
}

void Ressource::setTitre(const std::string& newTitre) {
    titre = newTitre;
}

void Ressource::setAuteur(const std::string& newAuteur) {
    auteur = newAuteur;
}

void Ressource::setEtat(const std::string& newEtat) {
    etat = newEtat;
}