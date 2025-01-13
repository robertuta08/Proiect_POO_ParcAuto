#include "admin.h"
#include <iostream>

Admin::Admin(int id, const std::string& nume) : Utilizator(id, nume, "admin") {}

void Admin::adaugaMasina(ParcAuto& parc) {
    int id;
    std::string marca, model, status;
    std::cout << "Adauga o masina noua:\n";
    std::cout << "ID: ";
    std::cin >> id;
    std::cout << "Marca: ";
    std::cin >> marca;
    std::cout << "Model: ";
    std::cin >> model;
    std::cout << "Status (disponibil/inchiriat/revizie): ";
    std::cin >> status;

    parc.adaugaMasina(Masina(id, marca, model, status));
    std::cout << "Masina a fost adaugata cu succes!\n";
}

void Admin::adaugaRevizie(ParcAuto& parc) {
    int idRevizie, idMasina;
    std::string dataProgramare, detalii;

    std::cout << "Adauga o revizie:\n";
    std::cout << "ID revizie: ";
    std::cin >> idRevizie;
    std::cout << "ID masina: ";
    std::cin >> idMasina;
    std::cin.ignore();
    std::cout << "Data programarii (YYYY-MM-DD): ";
    std::getline(std::cin, dataProgramare);
    std::cout << "Detalii: ";
    std::getline(std::cin, detalii);

    parc.actualizeazaStatusMasina(idMasina, "revizie");
    parc.adaugaRevizie(Revizie(idRevizie, idMasina, dataProgramare, detalii));

    std::cout << "Revizia a fost adaugata cu succes!\n";
}

void Admin::afiseazaMasini(const ParcAuto& parc) const {
    parc.afiseazaMasini();
}

void Admin::afiseazaRevizii(const ParcAuto& parc) const {
    parc.afiseazaRevizii();
}
