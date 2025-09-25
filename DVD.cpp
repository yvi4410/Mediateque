#/*
#class DVD {
#    +nbChapitres: int
#}
#*/

#include "DVD.h"

DVD::DVD(int id, std::string titre, std::string auteur, std::string etat,
		 int duree, std::string maisonProduction, int nbChapitres)
	: RessourceDigitaleAV(id, titre, auteur, etat, duree, maisonProduction), nbChapitres(nbChapitres) {}

int DVD::getNbChapitres() const {
	return nbChapitres;
}

void DVD::setNbChapitres(int n) {
	nbChapitres = n;
}
