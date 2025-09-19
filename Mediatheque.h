#pragma once
    #include <string>

    class Mediatheque {
    public:
        void dispatch();
        void bye();
        void add(const std::string& type);
        void load(const std::string& filename);
        void save(const std::string& filename);
        void search(const std::string& chaine);
        void clear();
        void list();
        void show(int id);
        void deleteResource(int id);
        void reset();
    };