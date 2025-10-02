# Système de Gestion de Médiathèque

<img width="3448" height="3840" alt="Projet Mediathèque _ Mermaid Chart-2025-10-02-070512" src="https://github.com/user-attachments/assets/bc0edce6-1c86-467a-bf51-fcf92828c3e5" />

## Conception :

<img width="1395" height="3840" alt="Untitled diagram _ Mermaid Chart-2025-10-02-071158" src="https://github.com/user-attachments/assets/c2f11935-282f-4046-8620-b89c0233bb06" />

<img width="3840" height="2084" alt="diagramme de séquence" src="https://github.com/user-attachments/assets/494d9825-616d-42a5-aa1d-3851aa50bc56" />



## Description
Application de gestion d'une médiathèque permettant de gérer différents types de ressources (livres, CDs, DVDs, VHS, revues) ainsi que les utilisateurs et leurs emprunts.

## Structure du Projet

### Classes Principales

#### Mediatheque
- Classe centrale gérant l'ensemble du système
- Gère les ressources et les utilisateurs
- Fonctionnalités :
    - Gestion des commandes utilisateur via `dispatch()`
    - Recherche de ressources
    - Affichage des détails
    - Sauvegarde/Chargement des données
    - Gestion des emprunts

#### Utilisateur
- Classe de base pour les utilisateurs
- Attributs : id, prénom, nom (non utilisé dans la version actuelle)
- Méthodes principales :
    - `borrow()` : Emprunter une ressource
    - `showBorrow()` : Afficher les emprunts

#### Administrateur (hérite d'Utilisateur)
- Droits étendus pour la gestion
- Fonctionnalités exclusives :
    - Ajout/Suppression de ressources
    - Gestion des utilisateurs (non utilisé dans la version actuelle)
    - Sauvegarde des données
    - Réinitialisation du système

#### Client (hérite d'Utilisateur)
- Utilisateur standard
- Accès limité aux opérations de base

### Hiérarchie des Ressources

#### Ressource (Classe abstraite)
- Attributs communs : id, titre, auteur, état
- Méthodes virtuelles pour la gestion

#### Types de Ressources
1. **Livre**
    - Attributs : année, nbPages, collection, résumé

2. **CD**
    - Attributs : durée, maison, nbPistes

3. **DVD**
    - Attributs : durée, maison, nbChapitres

4. **VHS**
    - Attributs : durée, maison

5. **Revue**
    - Attributs : année, nbPages, collection, éditeur, articles

6. **Ressources Numériques**
    - Non implémentées dans la version actuelle

## Fonctionnalités Principales

### Commandes Utilisateur
- `add [type]` : Ajouter une ressource (admin)
- `list` : Afficher les ressources
- `search <mot>` : Rechercher des ressources
- `show <id>` : Afficher les détails
- `borrow <id>` : Emprunter
- `showborrow` : Voir ses emprunts
- `load/save` : Gestion des fichiers
- `delete/reset` : Gestion des ressources (admin)
- `bye` : Quitter l'application

### Gestion des Données
- Sauvegarde/Chargement dans des fichiers
- Format texte structuré par type de ressource
- Persistance des données entre sessions

### Système de Recherche
- Recherche dans tous les attributs
- Affichage des résultats détaillés
- Gestion de résultats temporaires

## Sécurité
- Vérification des droits utilisateur
- Protection des opérations administratives

