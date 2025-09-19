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

    virtual ~Ressource(); // ✅ Ajout du mot-clé “virtual”

    int getId() const;
    std::string getRessourceTitle() const;
    std::string getAuteur() const;
    std::string getEtat() const;

    virtual std::string getType() const { return "Ressource"; }
};