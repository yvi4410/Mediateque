#pragma once
#include "Utilisateur.h"

class Administrateur : public Utilisateur {
public:
    ~Administrateur() override = default;

    void add(const std::string& type) override;

    void load(const std::string& filename) override;
    void save(const std::string& filename) override;
    void clear() override;
    void deleteById(int id) override;
    void ajouterUtilisateur(const Utilisateur& u) override;
    void supprimerUtilisateur(int id) override;
    void reset() override;
    void listerUtilisateurs() override;
};
