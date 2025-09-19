#include "Utilisateur.h"
#include <iostream>

namespace mediatheque {

Utilisateur::Utilisateur(int id, const std::string& prenom, const std::string& nom)
    : id(id), prenom(prenom), nom(nom) {}

void Utilisateur::bye() {
    std::cout << "Au revoir !" << std::endl;
}

void Utilisateur::list() {
    std::cout << "list()" << std::endl;
}

void Utilisateur::search(const std::string& q) {
    std::cout << "search(" << q << ")" << std::endl;
}

void Utilisateur::show(int id) {
    std::cout << "show(" << id << ")" << std::endl;
}

void Utilisateur::borrow(int id) {
    std::cout << "borrow(" << id << ")" << std::endl;
}

}