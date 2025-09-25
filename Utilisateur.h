#pragma once
#include <string>
#include <vector>

/*
class Utilisateur {
        +id: int
        +prenom: string
        +nom: string
        +emprunts: Ressource[*]
        +list()
        +search(q: string)
        +show(id: int)
        +borrow(id: int)
    }
*/

class Mediatheque; // forward declaration to avoid circular includes

class Utilisateur {
protected:
    int id;
    std::string prenom;
    std::string nom;

    // stocke les ids des ressources empruntées
    std::vector<int> emprunts;

public:
    // Construction / destruction
    Utilisateur(int id, const std::string& prenom, const std::string& nom);
    virtual ~Utilisateur();

    // Comportement (peuvent être surchargés par Administrateur/Client)
    virtual void bye();
    virtual void list(const Mediatheque& mediatheque);
    virtual void search(const std::string& q);
    virtual void show(int id);
    virtual void borrow(Mediatheque& mediatheque, int id);

    // Accesseurs
    int getId() const;
    const std::string& getNom() const;
    const std::string& getPrenom() const;
    const std::vector<int>& getEmprunts() const;

    // Emprunts helpers
    void addEmprunt(int id);
    bool removeEmprunt(int id);

    // Type/role string (surcharge possible)
    virtual std::string getRole() const { return "Utilisateur"; }
};
