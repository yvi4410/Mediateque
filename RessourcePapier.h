#pragma once
#include <string>

class RessourcePapier {
    
protected:
    int annee;
    int nbPage;
    std::string collection;
    std::string resume;

public:
    RessourcePapier(int annee, int nbPage, std::string collection, std::string resume);

};
