#pragma once
#include <string>
#include "Ressource.h"

class RessourcePapier : public Ressource {
protected:
    int annee;
    int nbPage;
    std::string collection;
    std::string resume;

public:
    RessourcePapier(int id, std::string titre, std::string auteur, std::string etat,
                    int annee, int nbPage, std::string collection, std::string resume);

    int getAnnee() const;
    void setAnnee(int a);

    int getNbPage() const;
    void setNbPage(int n);

    std::string getCollection() const;
    void setCollection(const std::string& c);

    std::string getResume() const;
    void setResume(const std::string& r);
};
