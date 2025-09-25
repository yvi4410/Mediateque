#include "Mediatheque.h"
#include "Administrateur.h"
#include "Client.h"
#include <iostream>

int main() {
    Mediatheque app;

    std::cout << "Etes-vous administrateur ? (oui/non) : ";
    std::string answer;
    if (!std::getline(std::cin, answer)) return 0;

    if (answer == "oui" || answer == "o" || answer == "yes") {
        app.setCurrentUser(std::make_unique<Administrateur>());
        std::cout << "Mode administrateur active." << std::endl;
    } else {
        app.setCurrentUser(std::make_unique<Client>(1, "Client", "Unique"));
        std::cout << "Mode client active." << std::endl;
    }

    app.dispatch();
    return 0;
}