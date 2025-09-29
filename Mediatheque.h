#pragma once
#include <memory>
#include <string>

class Utilisateur;

class Mediatheque {
public:
    Mediatheque() = default;

    void setCurrentUser(std::unique_ptr<Utilisateur> user);
    Utilisateur* getCurrentUser() const;

    // Boucle d'interface simple
    void dispatch();

private:
    std::unique_ptr<Utilisateur> currentUser;
};
