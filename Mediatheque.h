#pragma once
#include <memory>
#include <string>
#include <vector>
#include "Ressource.h"

class Utilisateur;

class Mediatheque {
public:
    Mediatheque() = default;

    void setCurrentUser(std::unique_ptr<Utilisateur> user);
    Utilisateur* getCurrentUser() const;

    // Boucle d'interface simple
    void dispatch();

    // Gestion des ressources
    void addRessource(std::unique_ptr<Ressource> ressource);
    void listRessources() const;
    std::vector<Ressource*> searchResults;

private:
    std::unique_ptr<Utilisateur> currentUser;
    std::vector<std::unique_ptr<Ressource>> ressources;
};
