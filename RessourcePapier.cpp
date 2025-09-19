#include "RessourcePapier.h"

RessourcePapier::RessourcePapier(int id, std::string titre, std::string auteur, std::string etat,
                                 int annee, int nbPage, std::string collection, std::string resume)
                    : Ressource(id, titre, auteur, etat), 
                      annee(annee), nbPage(nbPage), collection(collection), resume(resume) {}

int RessourcePapier::getAnnee() const {
    return annee;
}
void RessourcePapier::setAnnee(int a) {
    annee = a;
}
int RessourcePapier::getNbPage() const {
    return nbPage;
}
void RessourcePapier::setNbPage(int n) {
    nbPage = n;
}
std::string RessourcePapier::getCollection() const {
    return collection;
}
void RessourcePapier::setCollection(const std::string& c) {
    collection = c;
}
std::string RessourcePapier::getResume() const {
    return resume;
}
void RessourcePapier::setResume(const std::string& r) {
    resume = r;
}