#include "VHS.h"

VHS::VHS(int id, std::string titre, std::string auteur, std::string etat,
		 int duree, std::string maisonProduction)
	: RessourceDigitaleAV(id, titre, auteur, etat, duree, maisonProduction) {}
