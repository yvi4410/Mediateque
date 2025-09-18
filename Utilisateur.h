#pragma once

#include <string>

namespace mediatheque {

    class Utilisateur {
    public:
        Utilisateur(std::string nom, std::string prenom)
            : nom_(std::move(nom)), prenom_(std::move(prenom)) {}

        // Getters
        const std::string& nom() const noexcept { return nom_; }
        const std::string& prenom() const noexcept { return prenom_; }

        // Setters
        void setNom(std::string nom) { nom_ = std::move(nom); }
        void setPrenom(std::string prenom) { prenom_ = std::move(prenom); }

        // Destructeur virtuel pour permettre l'héritage (Client, Administrateur, etc.)
        virtual ~Utilisateur() = default;

        Utilisateur();

        virtual void bye();
        virtual void list();
        virtual void show(int id);
        virtual void search(const std::string& q);
        virtual void clear();
        virtual void add(const std::string& type);
        virtual void load(const std::string& filename);
        virtual void save(const std::string& filename);
        virtual void deleteById(int id);
        virtual void reset();


    protected:
        std::string nom_;
        std::string prenom_;
    };

} // namespace mediatheque