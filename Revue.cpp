#include "Revue.h"
#include <string>
#include "RessourcePapier.h"

Revue::Revue(int id, std::string titre, std::string auteur, std::string etat,
             int annee, int nbPage, std::string collection, std::string resume,
             std::string editeur, int nbArticles, std::string nomsArticles)
    : RessourcePapier(id, titre, auteur, etat, annee, nbPage, collection, resume),
      editeur(editeur), nbArticles(nbArticles), nomsArticles(nomsArticles) {}