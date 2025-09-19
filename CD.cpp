#include "CD.h"

CD::CD(int id, std::string titre, std::string auteur, std::string etat,
	   int duree, std::string maisonProduction, int nbPistes)
	: RessourceDigitaleAV(id, titre, auteur, etat, duree, maisonProduction), nbPistes(nbPistes) {}

int CD::getNbPistes() const {
	return nbPistes;
}

void CD::setNbPistes(int n) {
	nbPistes = n;
}
