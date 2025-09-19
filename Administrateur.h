// Administrateur.h
    #pragma once
    #include <string>
    #include <vector>
    #include "Utilisateur.h"

class Administrateur {
    public:
        Administrateur();
        ~Administrateur();

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
        // Ajoute ici d'autres attributs si nécessaire
};