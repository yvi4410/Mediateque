#include "Administrateur.h"

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

Administrateur::Administrateur() = default;
Administrateur::~Administrateur() = default;

void Administrateur::add(const std::string& /*type*/) {
    // placeholder: créer une ressource (implémentation à venir)
}

void Administrateur::load(const std::string& /*filename*/) {
    // placeholder: charger des ressources
}

void Administrateur::save(const std::string& /*filename*/) {
    // placeholder: sauvegarder des ressources
}

void Administrateur::clear() {
    // placeholder: réinitialiser les résultats
}

void Administrateur::deleteById(int /*id*/) {
    // placeholder: supprimer une ressource par id
}

void Administrateur::ajouterUtilisateur(const Utilisateur& /*u*/) {
    // placeholder: ajouter un utilisateur
}

void Administrateur::supprimerUtilisateur(int /*id*/) {
    // placeholder: supprimer utilisateur
}

void Administrateur::reset() {
    // placeholder: reset global
}

void Administrateur::listerUtilisateurs() {
    // placeholder: lister utilisateurs
}

