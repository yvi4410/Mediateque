#include "Mediatheque.h"
#include "Ressource.h"
#include <iostream>
#include <sstream>

/*
class Mediatheque {
	    +utilisateurs: Utilisateur
	    +ressources: Ressource
		+getRessource()
	    +deleteRessource(id: int)
	    +run()
	    +dispatch(cmd: string)
    }
*/

const std::vector<std::unique_ptr<Ressource>>& Mediatheque::getRessources() const {
    return ressources;
}


void Mediatheque::deleteResource(int id) {
    // Trouver et supprimer la ressource par ID
}

void Mediatheque::dispatch() {
    std::string input;
    while (true) {
        std::cout << "Menu :\n"
                  << "1. BYE\n"
                  << "2. ADD type\n"
                  << "3. LOAD filename\n"
                  << "4. SAVE filename\n"
                  << "5. SEARCH chaine\n"
                  << "6. CLEAR\n"
                  << "7. LIST\n"
                  << "8. SHOW id\n"
                  << "9. DELETE id\n"
                  << "10. RESET\n"
                  << "11. LISTER UTILISATEURS\n"
                  << "Entrez votre commande : ";
        std::getline(std::cin, input);

        std::istringstream iss(input);
        std::string cmd;
        iss >> cmd;

        if (cmd == "BYE" || "bye") {
            bye();
            break;
        } else if (cmd == "ADD" || "add") {
            // Administrateur::add() // Seul Administrateur peut ajouter, non pas Client
        } else if (cmd == "LOAD" || "load") {
            // Administrateur::load() // Seul Administrateur peut charger, non pas Client
        } else if (cmd == "SAVE" || "save") {
            // Administrateur::save() // Seul Administrateur peut sauvegarder, non pas Client
        } else if (cmd == "SEARCH" || "search") {
            // Utilisateur::search() // Client et Administrateur peuvent chercher
        } else if (cmd == "CLEAR" || "clear") {
            // Administrateur::clear() // Seul Administrateur peut clear, non pas Client
        } else if (cmd == "LIST" || "list") {
            // Utilisateur::list() // Client et Administrateur peuvent lister
        } else if (cmd == "SHOW" || "show") {
            // Utilisateur::show() // Client et Administrateur peuvent montrer
        } else if (cmd == "DELETE" || "delete") {
            // Administrateur::deleteById() // Seul Administrateur peut delete, non pas Client
        } else if (cmd == "RESET" || "reset") {
            // Administrateur::reset() // Seul Administrateur peut reset, non pas Client
        } else if (cmd == "LISTER UTILISATEURS" || "lister utilisateurs") {
            // Administrateur::listerUtilisateurs() // Seul Administrateur peut lister les utilisateurs
        } else {
            std::cout << "Commande inconnue.\n";
        }
    }
}