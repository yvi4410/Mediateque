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
    void showCommands() const; // Afficher les commandes disponibles
    void displayRessourceDetails(const Ressource* ressource) const; // Afficher tous les détails d'une ressource

    // Gestion des ressources
    void addRessource(std::unique_ptr<Ressource> ressource);
    void listRessources() const;
    void searchRessources(const std::string& query);
    void clearSearchResults();
    void showRessource(int id) const;
    void deleteRessource(int id);
    void resetRessources();
    void loadFromFile(const std::string& filename);
    void saveToFile(const std::string& filename) const;
    bool borrowRessource(int id); // Emprunter une ressource (change l'état)
    Ressource* findRessource(int id) const; // Trouver une ressource par ID
    std::vector<Ressource*> searchResults;

private:
    std::unique_ptr<Utilisateur> currentUser;
    std::vector<std::unique_ptr<Ressource>> ressources;
};
