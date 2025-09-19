#include "Livre.h"

Livre::Livre(int id, std::string titre, std::string auteur, std::string etat,
        int annee, int nbPage, std::string collection, std::string resume)
        : RessourcePapier(id, titre, auteur, etat, annee, nbPage, collection, resume) {}

int Livre::getAnnee() const {
    return annee;
}

void Livre::setAnnee(int a) {
    annee = a;
}

int Livre::getNbPages() const {
    return nbPage;
}

void Livre::setNbPages(int n) {
    nbPage = n;
}

std::string Livre::getCollection() const {
    return collection;
}

void Livre::setCollection(const std::string& c) {
    collection = c;
}

std::string Livre::getResume() const {
    return resume;
}

void Livre::setResume(const std::string& r) {
    resume = r;
}
