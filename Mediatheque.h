#pragma once
#include <string>
#include <vector>
#include <memory>
#include "Ressource.h"
#include "Utilisateur.h"

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

class Ressource;

class Mediatheque {

private:
    std::vector<std::unique_ptr<Ressource>> ressources;
    std::vector<std::unique_ptr<Utilisateur>> utilisateurs;

public:
    const std::vector<std::unique_ptr<Ressource>>& getRessources() const;
    void deleteResource(int id);
    void dispatch();
};