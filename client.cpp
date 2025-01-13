#include "client.h"
#include <iostream>

Client::Client(int id, const std::string& nume) : Utilizator(id, nume, "client") {}

void Client::inchiriazaMasina(ParcAuto& parc) {
    int idMasina;
    std::cout << "Introdu ID-ul masinii pe care doresti sa o inchiriezi: ";
    std::cin >> idMasina;

    if (parc.inchiriazaMasina(idMasina, this->getId())) {
        std::cout << "Masina cu ID-ul " << idMasina << " a fost inchiriata cu succes!\n";
    }
    else {
        std::cout << "Masina cu ID-ul " << idMasina << " nu este disponibila pentru inchiriere!\n";
    }
}

void Client::afiseazaMasiniDisponibile(const ParcAuto& parc) const {
    parc.afiseazaMasiniDisponibile();
}
