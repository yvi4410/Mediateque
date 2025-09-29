#include "Mediatheque.h"
#include "Utilisateur.h"
#include <iostream>
#include <algorithm>
#include <cctype>
#include <sstream>

void Mediatheque::setCurrentUser(std::unique_ptr<Utilisateur> user) {
    currentUser = std::move(user);
}

Utilisateur* Mediatheque::getCurrentUser() const {
    return currentUser.get();
}

static std::string to_lower_copy(std::string s) {
    std::transform(s.begin(), s.end(), s.begin(),
                   [](unsigned char c){ return static_cast<char>(std::tolower(c)); });
    return s;
}

void Mediatheque::dispatch() {
    std::string line;
    std::cout << "Commandes disponibles: add [type] | list | search <q> | show <id> | borrow <id> | bye\n";

    while (true) {
        std::cout << "> ";
        if (!std::getline(std::cin, line)) break;
        if (line.empty()) continue;

        // Parse très simple: commande + (arg1)
        std::istringstream iss(line);
        std::string cmd;
        iss >> cmd;
        std::string arg;
        std::getline(iss, arg);               // récupère le reste
        if (!arg.empty() && arg[0] == ' ')    // trim espace initial
            arg.erase(0, 1);

        std::string cmdLower = to_lower_copy(cmd);

        if (cmdLower == "bye") {
            std::cout << "Au revoir.\n";
            break;

        } else if (cmdLower == "add") {
            const std::string type = arg.empty() ? "default" : to_lower_copy(arg);
            if (currentUser) currentUser->add(type);
            else std::cout << "[Erreur] Aucun utilisateur connecté.\n";

        } else if (cmdLower == "list") {
            if (currentUser) currentUser->list();
            else std::cout << "[Erreur] Aucun utilisateur connecté.\n";

        } else if (cmdLower == "search") {
            if (currentUser) currentUser->search(arg);
            else std::cout << "[Erreur] Aucun utilisateur connecté.\n";

        } else if (cmdLower == "show") {
            int idR = arg.empty() ? -1 : std::stoi(arg);
            if (currentUser) currentUser->show(idR);
            else std::cout << "[Erreur] Aucun utilisateur connecté.\n";

        } else if (cmdLower == "borrow") {
            int idR = arg.empty() ? -1 : std::stoi(arg);
            if (currentUser) currentUser->borrow(idR);
            else std::cout << "[Erreur] Aucun utilisateur connecté.\n";

        } else {
            std::cout << "Commande inconnue. Utilisez: add [type] | list | search <q> | show <id> | borrow <id> | bye\n";
        }
    }
}
