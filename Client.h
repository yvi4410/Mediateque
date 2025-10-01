#pragma once
#include "Utilisateur.h"

class Client : public Utilisateur {
public:
    ~Client() override = default;
    
    // Méthodes interdites aux clients (placeholders)
    // Seules les méthodes réellement modifiées sont redéclarées.
    void add(const std::string& type) override;
    void load(const std::string& filename);
};
