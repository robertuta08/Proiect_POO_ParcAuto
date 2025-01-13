#include "utilizator.h"

Utilizator::Utilizator(int id, const std::string& nume, const std::string& rol)
    : id(id), nume(nume), rol(rol) {}

int Utilizator::getId() const {
    return id;
}

std::string Utilizator::getRol() const {
    return rol;
}
