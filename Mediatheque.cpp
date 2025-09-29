#include "Mediatheque.h"
#include "Utilisateur.h"
#include <iostream>
#include <algorithm>
#include <cctype>

void Mediatheque::setCurrentUser(std::unique_ptr<Utilisateur> user) {
    currentUser = std::move(user);
}

Utilisateur* Mediatheque::getCurrentUser() const {
    return currentUser.get();
}

void Mediatheque::dispatch() {
    std::string line;
    std::cout << "Commandes disponibles: add | bye\n";

    while (true) {
        std::cout << "> ";
        if (!std::getline(std::cin, line)) break;

        // minuscule
        std::transform(line.begin(), line.end(), line.begin(),
                       [](unsigned char c){ return static_cast<char>(std::tolower(c)); });

        if (line == "bye") {
            std::cout << "Au revoir.\n";
            break;
        } else if (line == "add") {
            if (currentUser) {
                currentUser->add();
            } else {
                std::cout << "[Erreur] Aucun utilisateur connecté.\n";
            }
        } else if (line.empty()) {
            continue;
        } else {
            std::cout << "Commande inconnue. Utilisez: add | bye\n";
        }
    }
}
