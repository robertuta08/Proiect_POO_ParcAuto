#include "parc_auto.h"
#include <iostream>
#include <algorithm>

ParcAuto::ParcAuto() {}

void ParcAuto::adaugaMasina(const Masina& masina) {
    masini.push_back(masina);
}

void ParcAuto::adaugaRevizie(const Revizie& revizie) {
    revizii.push_back(revizie);
}

bool ParcAuto::inchiriazaMasina(int idMasina, int idClient) {
    for (auto& masina : masini) {
        if (masina.getId() == idMasina && masina.getStatus() == "disponibil") {
            masina.setStatus("inchiriat");
            inchirieri.emplace_back(inchirieri.size() + 1, idMasina, idClient, "2025-01-12", "2025-01-20");
            return true;
        }
    }
    return false;
}

void ParcAuto::actualizeazaStatusMasina(int idMasina, const std::string& status) {
    for (auto& masina : masini) {
        if (masina.getId() == idMasina) {
            masina.setStatus(status);
            return;
        }
    }
}

void ParcAuto::afiseazaMasini() const {
    for (const auto& masina : masini) {
        masina.afisare();
    }
}

void ParcAuto::afiseazaMasiniDisponibile() const {
    for (const auto& masina : masini) {
        if (masina.getStatus() == "disponibil") {
            masina.afisare();
        }
    }
}

void ParcAuto::afiseazaRevizii() const {
    for (const auto& revizie : revizii) {
        revizie.afisare();
    }
}