/*
class Administrateur {
    +add(type: string)
    +load(filename: string)
    +save(filename: string)
    +clear()
    +deleteById(id: int)
    +ajouterUtilisateur(u: Utilisateur)
    +supprimerUtilisateur(id: int)
    +reset()
    +listerUtilisateurs()
}
*/

#pragma once
#include <string>
#include <vector>
#include "Utilisateur.h"
#include "Ressource.h"

class Ressource;

class Administrateur : public Utilisateur {
    public:
        Administrateur();
        ~Administrateur();

    // Create a resource (placeholder) - signature kept simple per class diagram
    void add(const std::string& type);
        void load(const std::string& filename);
        void save(const std::string& filename);
        void clear();
        void deleteById(int id);
        void ajouterUtilisateur(const Utilisateur& u);
        void supprimerUtilisateur(int id);
        void reset();
        void listerUtilisateurs();

    protected:
        std::vector<Utilisateur> utilisateurs;
        std::vector<Ressource*> ressources;
        std::vector<Ressource*> resultats;
};