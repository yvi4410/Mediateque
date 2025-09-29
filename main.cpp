#include "Mediatheque.h"
#include "Administrateur.h"
#include "Client.h"
#include <iostream>
#include <memory>

int main() {
    Mediatheque app;

    std::cout << "Êtes-vous administrateur ? (oui/non) : ";
    std::string answer;
    std::cin >> answer;

    if (answer == "oui" || answer == "o" || answer == "yes" || answer == "y") {
        app.setCurrentUser(std::make_unique<Administrateur>());
        std::cout << "Mode administrateur activé.\n";
    } else {
        app.setCurrentUser(std::make_unique<Client>());
        std::cout << "Mode client activé.\n";
    }

    app.dispatch();
    return 0;
}
