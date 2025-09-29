#include "Administrateur.h"
#include <iostream>

void Administrateur::add(const std::string& type) {
    std::cout << "[Admin] add(type=\"" << type << "\") -> placeholder: vous avez cliqué sur add.\n";
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
