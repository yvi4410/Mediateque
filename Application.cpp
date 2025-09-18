#include "Application.h"
#include <iostream>
#include <sstream>

void Application::add(const std::string&) {}
void Application::deleteResource(int) {}
void Application::bye() {}
void Application::list() {}
void Application::load(const std::string&) {}
void Application::save(const std::string&) {}
void Application::show(int) {}
void Application::clear() {}
void Application::reset() {}
void Application::search(const std::string&) {}

void Application::dispatch() {
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