#pragma once
#include <string>
#include <vector>
#include <memory>
#include "Ressource.h"
#include "Utilisateur.h"

/*
class Mediatheque {
	    +currentUser: Utilisateur
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
	std::unique_ptr<Utilisateur> currentUser;

public:
	Mediatheque() = default;
	~Mediatheque() = default;

	const std::vector<std::unique_ptr<Ressource>>& getRessources() const;
	Ressource* getRessource(int id) const;

    Utilisateur* getCurrentUser() const;
	void setCurrentUser(std::unique_ptr<Utilisateur> user);

	void deleteRessource(int id);
	void run();
	void dispatch();
	void dispatch(const std::string& cmd);	
};