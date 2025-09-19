#pragma once
#include <string>
#include <vector>
#include <memory>
#include "Ressource.h"

class Mediatheque {

private:
    std::vector<std::unique_ptr<Ressource>> ressources;

public:
    void dispatch();
    void bye();
    void add(const std::string& type);
    void load(const std::string& filename);
    void save(const std::string& filename);
    void search(const std::string& chaine);
    void clear();
    void list();
    void show(int id);
    void deleteResource(int id);
    void reset();
};