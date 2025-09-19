#pragma once
#include <string>

namespace mediatheque {

class Utilisateur {
public:
    Utilisateur(int id, const std::string& prenom, const std::string& nom);

    void bye();
    void list();
    void search(const std::string& q);
    void show(int id);
    void borrow(int id);

protected:
    int id;
    std::string prenom;
    std::string nom;
};

}