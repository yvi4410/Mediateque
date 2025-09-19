#include "Administrateur.h"
#include <iostream>
#include <algorithm>
#include <sstream>
#include <fstream>
#include "Livre.h"
#include "Revue.h"
#include "CD.h"
#include "DVD.h"
#include "VHS.h"
#include "RessourceNumeriqueFichier.h"



    Administrateur::Administrateur() {
    }
    Administrateur::~Administrateur() {
    }

    void Administrateur::add(const std::string& type) {
    Ressource* r = nullptr;

    int id;
    std::string titre, auteur, etat;

    std::cout << "ID : ";
    std::cin >> id;
    std::cin.ignore();

    std::cout << "Titre : ";
    std::getline(std::cin, titre);

    std::cout << "Auteur : ";
    std::getline(std::cin, auteur);

    std::cout << "État : ";
    std::getline(std::cin, etat);

    if (type == "Livre") {
        int annee, nbPages;
        std::string collection, resume;

        std::cout << "Année : ";
        std::cin >> annee;
        std::cout << "Nombre de pages : ";
        std::cin >> nbPages;
        std::cin.ignore();

        std::cout << "Collection : ";
        std::getline(std::cin, collection);

        std::cout << "Résumé : ";
        std::getline(std::cin, resume);

        r = new Livre(id, titre, auteur, etat, annee, nbPages, collection, resume);
    }

    else if (type == "Revue") {
        int annee, nbPages, nbArticles;
        std::string collection, resume, editeur;
        std::vector<std::string> nomsArticles;

        std::cout << "Année : "; std::cin >> annee;
        std::cout << "Pages : "; std::cin >> nbPages;
        std::cout << "Collection : "; std::cin.ignore(); std::getline(std::cin, collection);
        std::cout << "Résumé : "; std::getline(std::cin, resume);

        std::cout << "Éditeur : "; std::getline(std::cin, editeur);
        std::cout << "Nombre d'articles : "; std::cin >> nbArticles;
        std::cin.ignore();

        for (int i = 0; i < nbArticles; ++i) {
            std::string article;
            std::cout << "Nom de l’article " << (i + 1) << " : ";
            std::getline(std::cin, article);
            nomsArticles.push_back(article);
        }

        r = new Revue(id, titre, auteur, etat, annee, nbPages, collection, resume, editeur, nomsArticles);
    }

    else if (type == "CD") {
        int duree, nbPistes;
        std::string maison;

        std::cout << "Durée : "; std::cin >> duree;
        std::cout << "Maison de production : "; std::cin.ignore(); std::getline(std::cin, maison);
        std::cout << "Nombre de pistes : "; std::cin >> nbPistes;

        r = new CD(id, titre, auteur, etat, duree, maison, nbPistes);
    }

    else if (type == "DVD") {
        int duree, nbChapitres;
        std::string maison;

        std::cout << "Durée : "; std::cin >> duree;
        std::cout << "Maison de production : "; std::cin.ignore(); std::getline(std::cin, maison);
        std::cout << "Nombre de chapitres : "; std::cin >> nbChapitres;

        r = new DVD(id, titre, auteur, etat, duree, maison, nbChapitres);
    }

    else if (type == "VHS") {
        int duree;
        std::string maison;

        std::cout << "Durée : "; std::cin >> duree;
        std::cout << "Maison de production : "; std::cin.ignore(); std::getline(std::cin, maison);

        r = new VHS(id, titre, auteur, etat, duree, maison);
    }

    else if (type == "Fichier") {
        std::string url, typeFichier;
        int taille;

        std::cout << "Type de fichier : "; std::getline(std::cin, typeFichier);
        std::cout << "Taille (Ko) : "; std::cin >> taille;
        std::cin.ignore();
        std::cout << "URL : "; std::getline(std::cin, url);

        r = new RessourceNumeriqueFichier(id, titre, auteur, etat, typeFichier, taille, url);
    }

    else {
        std::cout << "Type inconnu : " << type << std::endl;
        return;
    }

    ressources.push_back(r);
    std::cout << "[Admin] Ressource ajoutée avec succès !" << std::endl;
}

    void Administrateur::load(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Erreur : impossible d’ouvrir le fichier " << filename << std::endl;
        return;
    }

    // Supprimer les ressources existantes
    for (Ressource* r : ressources) {
        delete r;
    }
    ressources.clear();

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string type;
        std::getline(iss, type, ';');

        try {
            if (type == "Livre") {
                int id, annee, nbPages;
                std::string titre, auteur, etat, collection, resume;

                std::getline(iss, line, ';'); id = std::stoi(line);
                std::getline(iss, titre, ';');
                std::getline(iss, auteur, ';');
                std::getline(iss, etat, ';');
                std::getline(iss, line, ';'); annee = std::stoi(line);
                std::getline(iss, line, ';'); nbPages = std::stoi(line);
                std::getline(iss, collection, ';');
                std::getline(iss, resume);

                ressources.push_back(new Livre(id, titre, auteur, etat, annee, nbPages, collection, resume));
            }

            else if (type == "Revue") {
                int id, annee, nbPages;
                std::string titre, auteur, etat, collection, resume, editeur, articles_str;
                std::vector<std::string> articles;

                std::getline(iss, line, ';'); id = std::stoi(line);
                std::getline(iss, titre, ';');
                std::getline(iss, auteur, ';');
                std::getline(iss, etat, ';');
                std::getline(iss, line, ';'); annee = std::stoi(line);
                std::getline(iss, line, ';'); nbPages = std::stoi(line);
                std::getline(iss, collection, ';');
                std::getline(iss, resume, ';');
                std::getline(iss, editeur, ';');
                std::getline(iss, articles_str);

                std::istringstream artStream(articles_str);
                std::string article;
                while (std::getline(artStream, article, ',')) {
                    articles.push_back(article);
                }

                ressources.push_back(new Revue(id, titre, auteur, etat, annee, nbPages, collection, resume, editeur, articles));
            }

            else if (type == "CD") {
                int id, duree, nbPistes;
                std::string titre, auteur, etat, maison;

                std::getline(iss, line, ';'); id = std::stoi(line);
                std::getline(iss, titre, ';');
                std::getline(iss, auteur, ';');
                std::getline(iss, etat, ';');
                std::getline(iss, line, ';'); duree = std::stoi(line);
                std::getline(iss, maison, ';');
                std::getline(iss, line); nbPistes = std::stoi(line);

                ressources.push_back(new CD(id, titre, auteur, etat, duree, maison, nbPistes));
            }

            else if (type == "DVD") {
                int id, duree, nbChapitres;
                std::string titre, auteur, etat, maison;

                std::getline(iss, line, ';'); id = std::stoi(line);
                std::getline(iss, titre, ';');
                std::getline(iss, auteur, ';');
                std::getline(iss, etat, ';');
                std::getline(iss, line, ';'); duree = std::stoi(line);
                std::getline(iss, maison, ';');
                std::getline(iss, line); nbChapitres = std::stoi(line);

                ressources.push_back(new DVD(id, titre, auteur, etat, duree, maison, nbChapitres));
            }

            else if (type == "VHS") {
                int id, duree;
                std::string titre, auteur, etat, maison;

                std::getline(iss, line, ';'); id = std::stoi(line);
                std::getline(iss, titre, ';');
                std::getline(iss, auteur, ';');
                std::getline(iss, etat, ';');
                std::getline(iss, line, ';'); duree = std::stoi(line);
                std::getline(iss, maison);

                ressources.push_back(new VHS(id, titre, auteur, etat, duree, maison));
            }

            else if (type == "Fichier") {
                int id, taille;
                std::string titre, auteur, etat, typeFichier, url;

                std::getline(iss, line, ';'); id = std::stoi(line);
                std::getline(iss, titre, ';');
                std::getline(iss, auteur, ';');
                std::getline(iss, etat, ';');
                std::getline(iss, typeFichier, ';');
                std::getline(iss, line, ';'); taille = std::stoi(line);
                std::getline(iss, url);

                ressources.push_back(new RessourceNumeriqueFichier(id, titre, auteur, etat, typeFichier, taille, url));
            }

            else {
                std::cerr << "[ERREUR] Type inconnu : " << type << std::endl;
            }
        } catch (...) {
            std::cerr << "[ERREUR] Ligne mal formée : " << line << std::endl;
        }
    }

    std::cout << "[Admin] Chargement des ressources terminé depuis '" << filename << "'" << std::endl;
}
void Administrateur::save(const std::string& filename) {
    std::ofstream file(filename);
    if (!file) {
        std::cerr << "Erreur : impossible de créer le fichier " << filename << std::endl;
        return;
    }

    for (Ressource* r : ressources) {
        // LIVRE
        if (auto* livre = dynamic_cast<Livre*>(r)) {
            file << "Livre;" << livre->getId() << ";" << livre->getTitre() << ";" << livre->getAuteur()
                 << ";" << livre->getEtat() << ";" << livre->getAnnee() << ";" << livre->getNbPages()
                 << ";" << livre->getCollection() << ";" << livre->getResume() << "\n";
        }
        // REVUE
        else if (auto* revue = dynamic_cast<Revue*>(r)) {
            file << "Revue;" << revue->getId() << ";" << revue->getTitre() << ";" << revue->getAuteur()
                 << ";" << revue->getEtat() << ";" << revue->getAnnee() << ";" << revue->getNbPages()
                 << ";" << revue->getCollection() << ";" << revue->getResume() << ";" << revue->getEditeur() << ";";

            const auto& articles = revue->getArticles();
            for (size_t i = 0; i < articles.size(); ++i) {
                file << articles[i];
                if (i < articles.size() - 1) file << ",";
            }
            file << "\n";
        }
        // CD
        else if (auto* cd = dynamic_cast<CD*>(r)) {
            file << "CD;" << cd->getId() << ";" << cd->getTitre() << ";" << cd->getAuteur()
                 << ";" << cd->getEtat() << ";" << cd->getDuree() << ";" << cd->getMaison()
                 << ";" << cd->getNbPistes() << "\n";
        }
        // DVD
        else if (auto* dvd = dynamic_cast<DVD*>(r)) {
            file << "DVD;" << dvd->getId() << ";" << dvd->getTitre() << ";" << dvd->getAuteur()
                 << ";" << dvd->getEtat() << ";" << dvd->getDuree() << ";" << dvd->getMaison()
                 << ";" << dvd->getNbChapitres() << "\n";
        }
        // VHS
        else if (auto* vhs = dynamic_cast<VHS*>(r)) {
            file << "VHS;" << vhs->getId() << ";" << vhs->getTitre() << ";" << vhs->getAuteur()
                 << ";" << vhs->getEtat() << ";" << vhs->getDuree() << ";" << vhs->getMaison()
                 << "\n";
        }
        // FICHIER
        else if (auto* fichier = dynamic_cast<RessourceNumeriqueFichier*>(r)) {
            file << "Fichier;" << fichier->getId() << ";" << fichier->getTitre() << ";" << fichier->getAuteur()
                 << ";" << fichier->getEtat() << ";" << fichier->getTypeFichier() << ";" << fichier->getTaille()
                 << ";" << fichier->getUrl() << "\n";
        }
        else {
            std::cerr << "[ERREUR] Ressource de type inconnu, non sauvegardée." << std::endl;
        }
    }

    std::cout << "[Admin] Sauvegarde terminée vers '" << filename << "'." << std::endl;
}

    void Administrateur::clear() {
        resultats.clear();
        std::cout << "[Admin] Résultats de recherche réinitialisés. Prochaine recherche appliquée sur toutes les ressources." << std::endl;
    }

    void Administrateur::deleteById(int id) {
        std::cout << "[Admin] Suppression de la ressource avec ID : " << id << std::endl;
        // Même chose que clear : à implémenter plus tard si tu gères les ressources dans une liste
    }

    void Administrateur::ajouterUtilisateur(const Utilisateur& u) {
        utilisateurs.push_back(u);
        std::cout << "[Admin] Utilisateur ajouté : " << u.getNom() << " " << u.getPrenom() << std::endl;
    }

    void Administrateur::supprimerUtilisateur(int id) {
        auto it = std::remove_if(utilisateurs.begin(), utilisateurs.end(),
            [id](const Utilisateur& u) {
                return u.getId() == id;
            });
        if (it != utilisateurs.end()) {
            utilisateurs.erase(it, utilisateurs.end());
            std::cout << "[Admin] Utilisateur avec ID " << id << " supprimé." << std::endl;
        } else {
            std::cout << "[Admin] Aucun utilisateur trouvé avec ID " << id << std::endl;
        }
    }

    void Administrateur::reset() {
        utilisateurs.clear();
        std::cout << "[Admin] Liste des utilisateurs réinitialisée." << std::endl;
        // Ajoute aussi un reset des ressources si tu les ajoutes dans cette classe
    }

    void Administrateur::listerUtilisateurs() {
        std::cout << "[Admin] Liste des utilisateurs :" << std::endl;
        for (const auto& u : utilisateurs) {
            std::cout << " - ID: " << u.getId() << ", Nom: " << u.getNom()
                      << ", Prénom: " << u.getPrenom() << std::endl;
        }
    }

