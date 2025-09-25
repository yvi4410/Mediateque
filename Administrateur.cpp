
#include "Administrateur.h"
#include "Mediatheque.h"
#include "Livre.h"
#include "Revue.h"
#include "CD.h"
#include "VHS.h"
#include "DVD.h"
#include "RessourceNumeriqueFichier.h"
#include <iostream>
#include <string>

/*
class Administrateur {
	    +add(type: string)
	    +load(filename: string)
	    +save(filename: string)
	    +clear()
	    +deleteById(id: int)
	    +ajouterUtilisateur(u: Utilisateur)
	    +supprimerUtilisateur(id: int)
	    +reset()
	    +listerUtilisateurs()
    }
*/

Administrateur::Administrateur() = default;
Administrateur::~Administrateur() = default;

void Administrateur::add(const std::string& type) {
    using std::cout; using std::cin; using std::string; using std::getline;

    auto ask = [&](const char* label) {
        cout << label << ": ";
        string s; getline(cin, s);
        return s;
    };
    auto askInt = [&](const char* label) {
        string s = ask(label);
        return s.empty() ? 0 : std::stoi(s);
    };

    // Champs de base Ressource
    const int id = mdb_->nextId();
    const string titre  = ask("Titre");
    const string auteur = ask("Auteur");
    const string etat   = "disponible";

    std::unique_ptr<Ressource> r;

    if (type == "livre") {
        auto p = std::make_unique<Livre>();
        p->id = id; p->titre = titre; p->auteur = auteur; p->etat = etat;
        p->annee = askInt("Année");
        p->nbPages = askInt("Nombre de pages");
        p->collection = ask("Collection");
        p->resume = ask("Résumé");
        r = std::move(p);
    } else if (type == "revue") {
        auto p = std::make_unique<Revue>();
        p->id = id; p->titre = titre; p->auteur = auteur; p->etat = etat;
        p->annee = askInt("Année");
        p->nbPages = askInt("Nombre de pages");
        p->collection = ask("Collection");
        p->resume = ask("Résumé");
        p->editeur = ask("Éditeur");
        p->nbArticles = askInt("Nombre d'articles");
        p->nomsArticles.clear();
        for (int i = 0; i < p->nbArticles; ++i) {
            p->nomsArticles.push_back(ask(("Article #" + std::to_string(i+1)).c_str()));
        }
        r = std::move(p);
    } else if (type == "cd") {
        auto p = std::make_unique<CD>();
        p->id = id; p->titre = titre; p->auteur = auteur; p->etat = etat;
        p->duree = askInt("Durée (minutes)");
        p->maisonProduction = ask("Maison de production");
        p->nbPistes = askInt("Nombre de pistes");
        r = std::move(p);
    } else if (type == "vhs") {
        auto p = std::make_unique<VHS>();
        p->id = id; p->titre = titre; p->auteur = auteur; p->etat = etat;
        p->duree = askInt("Durée (minutes)");
        p->maisonProduction = ask("Maison de production");
        r = std::move(p);
    } else if (type == "dvd") {
        auto p = std::make_unique<DVD>();
        p->id = id; p->titre = titre; p->auteur = auteur; p->etat = etat;
        p->duree = askInt("Durée (minutes)");
        p->maisonProduction = ask("Maison de production");
        p->nbChapitres = askInt("Nombre de chapitres");
        r = std::move(p);
    } else if (type == "fichier") { // RessourceNumeriqueFichier
        auto p = std::make_unique<RessourceNumeriqueFichier>();
        p->id = id; p->titre = titre; p->auteur = auteur; p->etat = etat;
        p->type = ask("Type (ex: pdf/mp3/mp4)");
        p->taille = askInt("Taille (Mo)");
        p->url = ask("URL");
        r = std::move(p);
    } else {
        cout << "Type inconnu: " << type
             << " (attendu: livre, revue, cd, vhs, dvd, fichier)\n";
        return;
    }

    // ⬇️ AU PLUS SIMPLE : on pousse directement dans le tableau de la médiathèque
    mdb_->ressources.push_back(std::move(r));
    cout << "Ressource ajoutée (id=" << id << ").\n";
}


void Administrateur::load(const std::string& /*filename*/) {
    // placeholder: charger des ressources
}

void Administrateur::save(const std::string& /*filename*/) {
    // placeholder: sauvegarder des ressources
}

void Administrateur::clear() {
    // placeholder: réinitialiser les résultats
}

void Administrateur::deleteById(int /*id*/) {
    // placeholder: supprimer une ressource par id
}

void Administrateur::ajouterUtilisateur(const Utilisateur& /*u*/) {
    // placeholder: ajouter un utilisateur
}

void Administrateur::supprimerUtilisateur(int /*id*/) {
    // placeholder: supprimer utilisateur
}

void Administrateur::reset() {
    // placeholder: reset global
}

void Administrateur::listerUtilisateurs() {
    // placeholder: lister utilisateurs
}

