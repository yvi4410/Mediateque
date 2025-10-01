/*
class Livre {
    // specialization of RessourcePapier
}
*/

#pragma once
#include <string>
#include "RessourcePapier.h"

class Livre : public RessourcePapier {
public:
    Livre(int id, std::string titre, std::string auteur, std::string etat, 
        int annee, int nbPage, std::string collection, std::string resume);

    int getAnnee() const;

    void setAnnee(int a);

    int getNbPages() const;

    void setNbPages(int n);

    void setNbPage(int n);

    std::string getCollection() const;

    void setCollection(const std::string &c);

    std::string getResume() const;

    void setResume(const std::string &r);

    std::string getType() const override { return "Livre"; }
};
