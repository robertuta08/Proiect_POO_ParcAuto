#ifndef PARC_AUTO_H
#define PARC_AUTO_H

#include "masina.h"
#include "inchiriere.h"
#include "revizie.h"
#include "utilizator.h"
#include <vector>
#include <string>

class ParcAuto {
public:
    std::vector<Masina> masini;
    std::vector<Inchiriere> inchirieri;
    std::vector<Revizie> revizii;

    ParcAuto();

    void adaugaMasina(const Masina& masina);
    void adaugaRevizie(const Revizie& revizie);
    bool inchiriazaMasina(int idMasina, int idClient);
    void actualizeazaStatusMasina(int idMasina, const std::string& status);

    void afiseazaMasini() const;
    void afiseazaMasiniDisponibile() const;
    void afiseazaRevizii() const;
};

#endif 

