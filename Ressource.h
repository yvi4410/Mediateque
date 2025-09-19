#pragma once
#include <string>

class Ressource {
    
protected:
    int id;
    std::string titre;
    std::string auteur;
    std::string etat;

public:
    Ressource(int id, std::string titre, std::string auteur, std::string etat);

    ~Ressource();

    std::string getRessourceTitle() const;
    int getId() const;
    std::string getAuteur() const;
    std::string getEtat() const;

};