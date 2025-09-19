#include "VHS.h"

VHS::VHS(int id, std::string titre, std::string auteur, std::string etat,
		 int duree, std::string maison)
	: RessourceDigitaleAV(id, titre, auteur, etat, duree, maison) {}

int VHS::getDuree() const {
    return duree;
}

void VHS::setDuree(int d) {
    duree = d;
}

std::string VHS::getMaison() const {
    return maison;
}

void VHS::setMaison(const std::string& m) {
    maison = m;
}
