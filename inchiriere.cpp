#include "inchiriere.h"
#include <iostream>

Inchiriere::Inchiriere(int idInchiriere, int idMasina, int idClient, const std::string& dataInchiriere, const std::string& dataReturnare)
    : idInchiriere(idInchiriere), idMasina(idMasina), idClient(idClient), dataInchiriere(dataInchiriere), dataReturnare(dataReturnare) {}

void Inchiriere::afisare() const {
    std::cout << "ID Inchiriere: " << idInchiriere << ", ID Masina: " << idMasina
        << ", ID Client: " << idClient << ", Data Inchiriere: " << dataInchiriere
        << ", Data Returnare: " << dataReturnare << "\n";
}