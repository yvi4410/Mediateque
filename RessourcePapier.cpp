#include "RessourcePapier.h"

RessourcePapier::RessourcePapier(int id, std::string titre, std::string auteur, std::string etat,
                                 int annee, int nbPage, std::string collection, std::string resume)
                    : Ressource(id, titre, auteur, etat), 
                      annee(annee), nbPage(nbPage), collection(collection), resume(resume) {}