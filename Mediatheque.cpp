#include "Mediatheque.h"
#include <iostream>
#include <sstream>

void Mediatheque::add(const std::string&) {}
void Mediatheque::deleteResource(int) {}
void Mediatheque::bye() {}
void Mediatheque::list() {}
void Mediatheque::load(const std::string&) {}
void Mediatheque::save(const std::string&) {}
void Mediatheque::show(int) {}
void Mediatheque::clear() {}
void Mediatheque::reset() {}
void Mediatheque::search(const std::string&) {}

const std::vector<std::unique_ptr<Ressource>>& Mediatheque::getRessources() const {
    return ressources;
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
                  << "Entrez votre commande : ";
        std::getline(std::cin, input);

        std::istringstream iss(input);
        std::string cmd;
        iss >> cmd;

        if (cmd == "BYE") {
            bye();
            break;
        } else if (cmd == "ADD") {
            std::string type;
            iss >> type;
            add(type);
        } else if (cmd == "LOAD") {
            std::string filename;
            iss >> filename;
            load(filename);
        } else if (cmd == "SAVE") {
            std::string filename;
            iss >> filename;
            save(filename);
        } else if (cmd == "SEARCH") {
            std::string chaine;
            iss >> chaine;
            search(chaine);
        } else if (cmd == "CLEAR") {
            clear();
        } else if (cmd == "LIST") {
            list();
        } else if (cmd == "SHOW") {
            int id;
            iss >> id;
            show(id);
        } else if (cmd == "DELETE") {
            int id;
            iss >> id;
            deleteResource(id);
        } else if (cmd == "RESET") {
            reset();
        } else {
            std::cout << "Commande inconnue.\n";
        }
    }
}