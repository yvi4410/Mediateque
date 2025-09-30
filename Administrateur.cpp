#include "Administrateur.h"
#include "Mediatheque.h"
#include "Livre.h"
#include "CD.h"
#include "DVD.h"
#include "VHS.h"
#include "Revue.h"
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
        std::cout << "Types de ressources disponibles: livre, cd\n";
        std::cout << "Entrez le type de ressource à ajouter: ";
        std::getline(std::cin, typeRessource);
    }

    std::cout << "[Admin] Ajout d'une ressource de type: " << typeRessource << "\n";
    
    // Demander les informations de base
    std::cout << "ID: ";
    int id;
    std::cin >> id;
    std::cin.ignore(); // vider le buffer
    
    std::cout << "Titre: ";
    std::string titre;
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
        
    } else {
        std::cout << "[Erreur] Type de ressource non supporté: " << typeRessource << "\n";
        std::cout << "Types disponibles: livre, cd\n";
        return;
    }
    
    mediatheque->addRessource(std::move(ressource));
    std::cout << "[Admin] Ressource ajoutée avec succès!\n";
}

void Administrateur::load(const std::string& filename) {
    std::cout << "[Admin] load(\"" << filename << "\") -> placeholder: chargerait des données.\n";
}

void Administrateur::save(const std::string& filename) {
    std::cout << "[Admin] save(\"" << filename << "\") -> placeholder: sauverait des données.\n";
}

void Administrateur::clear() {
    std::cout << "[Admin] clear() -> placeholder: viderait les listes/résultats.\n";
}

void Administrateur::deleteById(int id) {
    std::cout << "[Admin] deleteById(" << id << ") -> placeholder: supprimerait la ressource.\n";
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
    std::cout << "[Admin] reset() -> placeholder: remettrait l'état à zéro.\n";
}

void Administrateur::listerUtilisateurs() {
    std::cout << "[Admin] listerUtilisateurs() -> placeholder: afficherait la liste des utilisateurs.\n";
}
