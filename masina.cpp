#include "masina.h"

Masina::Masina(int id, const std::string& marca, const std::string& model, const std::string& status)
    : id(id), marca(marca), model(model), status(status) {}

int Masina::getId() const {
    return id;
}

std::string Masina::getStatus() const {
    return status;
}

void Masina::setStatus(const std::string& status) {
    this->status = status;
}

void Masina::afisare() const {
    std::cout << "ID: " << id << ", Marca: " << marca << ", Model: " << model << ", Status: " << status << "\n";
}