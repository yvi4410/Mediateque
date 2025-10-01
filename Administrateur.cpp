#include "Administrateur.h"
#include "Mediatheque.h"
#include "Livre.h"
#include "Revue.h"
#include "CD.h"
#include "DVD.h"
#include "VHS.h"
#include <iostream>
#include <memory>

void Administrateur::add(const std::string& type) {
    if (!mediatheque) {
        std::cout << "[Erreur] Pas de médiatèque configurée.\n";
        return;
    }

    std::string typeRessource = type;
    
    // Si aucun type n'est spécifié, demander à l'utilisateur
    if (typeRessource.empty()) {
        std::cout << "Types de ressources disponibles: livre, revue, cd, vhs, dvd\n";
        std::cout << "Entrez le type de ressource à ajouter: ";
        std::getline(std::cin, typeRessource);
    }

    std::cout << "[Admin] Ajout d'une ressource de type: " << typeRessource << "\n";
    
    // Demander les informations de base
    std::cout << "ID: ";
    int id;
    std::cin >> id;
    
    std::cout << "Titre: ";
    std::string titre;
    std::cin.ignore(); // vider le buffer après la lecture de l'entier
    std::getline(std::cin, titre);
    
    std::cout << "Auteur: ";
    std::string auteur;
    std::getline(std::cin, auteur);
    
    std::string etat = "Disponible"; // état par défaut
    
    std::unique_ptr<Ressource> ressource;
    
    if (typeRessource == "livre") {
        std::cout << "Année: ";
        int annee;
        std::cin >> annee;
        std::cout << "Nombre de pages: ";
        int nbPages;
        std::cin >> nbPages;
        std::cin.ignore();
        std::cout << "Collection: ";
        std::string collection;
        std::getline(std::cin, collection);
        std::cout << "Résumé: ";
        std::string resume;
        std::getline(std::cin, resume);
        
        ressource = std::make_unique<Livre>(id, titre, auteur, etat, annee, nbPages, collection, resume);
        
    } else if (typeRessource == "cd") {
        std::cout << "Durée (en minutes): ";
        int duree;
        std::cin >> duree;
        std::cin.ignore();
        std::cout << "Maison de production: ";
        std::string maison;
        std::getline(std::cin, maison);
        std::cout << "Nombre de pistes: ";
        int nbPistes;
        std::cin >> nbPistes;
        
        ressource = std::make_unique<CD>(id, titre, auteur, etat, duree, maison, nbPistes);
        
    } else if (typeRessource == "revue") {
        std::cout << "Année: ";
        int annee;
        std::cin >> annee;
        std::cout << "Nombre de pages: ";
        int nbPages;
        std::cin >> nbPages;
        std::cin.ignore();
        std::cout << "Collection: ";
        std::string collection;
        std::getline(std::cin, collection);
        std::cout << "Résumé: ";
        std::string resume;
        std::getline(std::cin, resume);
        std::cout << "Éditeur: ";
        std::string editeur;
        std::getline(std::cin, editeur);
        std::cout << "Nombre d'articles: ";
        int nbArticles;
        std::cin >> nbArticles;
        
        // Pour simplifier, on crée un vecteur d'articles vide
        std::vector<std::string> articles;
        
        ressource = std::make_unique<Revue>(id, titre, auteur, etat, annee, nbPages, collection, resume, editeur, articles);
        
    } else if (typeRessource == "dvd") {
        std::cout << "Durée (en minutes): ";
        int duree;
        std::cin >> duree;
        std::cin.ignore();
        std::cout << "Maison de production: ";
        std::string maison;
        std::getline(std::cin, maison);
        std::cout << "Nombre de chapitres: ";
        int nbChapitres;
        std::cin >> nbChapitres;
        
        ressource = std::make_unique<DVD>(id, titre, auteur, etat, duree, maison, nbChapitres);
        
    } else if (typeRessource == "vhs") {
        std::cout << "Durée (en minutes): ";
        int duree;
        std::cin >> duree;
        std::cin.ignore();
        std::cout << "Maison de production: ";
        std::string maison;
        std::getline(std::cin, maison);
        
        ressource = std::make_unique<VHS>(id, titre, auteur, etat, duree, maison);
        
    } else {
        std::cout << "[Erreur] Type de ressource non supporté: " << typeRessource << "\n";
        std::cout << "Types disponibles: livre, revue, cd, dvd, vhs\n";
        return;
    }
    
    mediatheque->addRessource(std::move(ressource));
    std::cout << "[Admin] Ressource ajoutée avec succès!\n";
}

void Administrateur::load(const std::string& filename) {
    // La vraie logique est dans Mediatheque::loadFromFile
    std::cout << "[Admin] Chargement des données depuis " << filename << "\n";
}

void Administrateur::save(const std::string& filename) {
    // La vraie logique est dans Mediatheque::saveToFile
    std::cout << "[Admin] Sauvegarde des données vers " << filename << "\n";
}

void Administrateur::clear() {
    // La vraie logique est dans Mediatheque::clearSearchResults
    std::cout << "[Admin] Effacement des résultats de recherche.\n";
}

void Administrateur::deleteById(int id) {
    // La vraie logique est dans Mediatheque::deleteRessource
    std::cout << "[Admin] Suppression de la ressource ID " << id << "\n";
}

void Administrateur::ajouterUtilisateur(const Utilisateur& u) {
    std::cout << "[Admin] ajouterUtilisateur(id=" << u.id
              << ", prenom=\"" << u.prenom << "\", nom=\"" << u.nom
              << "\") -> placeholder: ajouterait un utilisateur.\n";
}

void Administrateur::supprimerUtilisateur(int id) {
    std::cout << "[Admin] supprimerUtilisateur(" << id << ") -> placeholder: retirerait un utilisateur.\n";
}

void Administrateur::reset() {
    // La vraie logique est dans Mediatheque::resetRessources
    std::cout << "[Admin] Remise à zéro de toutes les ressources.\n";
}

void Administrateur::listerUtilisateurs() {
    std::cout << "[Admin] listerUtilisateurs() -> placeholder: afficherait la liste des utilisateurs.\n";
}
