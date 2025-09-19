#include "Utilisateur.h"
#include <iostream>

namespace mediatheque {

    Utilisateur::Utilisateur() = default;

    void Utilisateur::bye() {
        std::cout << "Au revoir !" << std::endl;
        exit(0);
    }
    void Utilisateur::list() {
        std::cout << "list()" << std::endl;
    }
    void Utilisateur::show(int id) {
        std::cout << "show(" << id << ")" << std::endl;
    }
    void Utilisateur::search(const std::string& q) {
        std::cout << "search(" << q << ")" << std::endl;
    }
    void Utilisateur::clear() {
        std::cout << "clear()" << std::endl;
    }
    void Utilisateur::add(const std::string& type) {
        std::cout << "add(" << type << ")" << std::endl;
    }
    void Utilisateur::load(const std::string& filename) {
        std::cout << "load(" << filename << ")" << std::endl;
    }
    void Utilisateur::save(const std::string& filename) {
        std::cout << "save(" << filename << ")" << std::endl;
    }
    void Utilisateur::deleteById(int id) {
        std::cout << "deleteById(" << id << ")" << std::endl;
    }
    void Utilisateur::reset() {
        std::cout << "reset()" << std::endl;
    }
}