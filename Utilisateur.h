#pragma once
#include <string>

class Mediatheque; // Decalration anticipée pour les circular import et eviter les pb

class Utilisateur {

public:
    Utilisateur(int id, const std::string& prenom, const std::string& nom);

    void bye();
    void list(const Mediatheque& mediatheque);
    void search(const std::string& q);
    void show(int id);
    void borrow(int id);

    int getId() const { return id; }
    const std::string& getNom() const { return nom; }
    const std::string& getPrenom() const { return prenom; }

protected:
    int id;
    std::string prenom;
    std::string nom;
};
