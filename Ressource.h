/*
class Ressource {
    +id: int
    +titre: string
    +auteur: string
    +etat: string
}
*/

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
    virtual ~Ressource() = default;

    int getId() const;

    std::string getTitre() const;

    void setId(int newId);

    void setTitre(const std::string& newTitre);

    std::string getAuteur() const;
    void setAuteur(const std::string& newAuteur);

    std::string getEtat() const;
    void setEtat(const std::string& newEtat);


    virtual std::string getType() const { return "Ressource"; }
};