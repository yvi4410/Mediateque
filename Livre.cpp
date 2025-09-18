#include "Livre.h"

Livre::Livre(int id, std::string titre, std::string auteur, std::string etat, 
        int annee, int nbPage, std::string collection, std::string resume)
        : RessourcePapier(id, titre, auteur, etat, annee, nbPage, collection, resume) {}
