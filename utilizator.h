#ifndef UTILIZATOR_H
#define UTILIZATOR_H

#include <string>

class Utilizator {
protected:
    int id;
    std::string nume;
    std::string rol;

public:
    Utilizator(int id, const std::string& nume, const std::string& rol);
    int getId() const;
    std::string getRol() const;
    virtual ~Utilizator() = default;
};

#endif 
