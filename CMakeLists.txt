cmake_minimum_required(VERSION 4.0)
project(untitled)

set(CMAKE_CXX_STANDARD 20)

add_executable(untitled main.cpp
        VHS.cpp
        Utilisateur.cpp
        Administrateur.h
        Administrateur.cpp
        Client.h
        Client.cpp
        Mediatheque.cpp
        CD.cpp
        DVD.cpp
        Livre.cpp
        Ressource.cpp
        RessourceDigitaleAV.cpp
        RessourceNumeriqueFichier.cpp
        RessourcePapier.cpp
        Revue.cpp)
