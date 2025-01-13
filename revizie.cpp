#include "revizie.h"
#include <iostream>

Revizie::Revizie(int idRevizie, int idMasina, const std::string& dataProgramare, const std::string& detalii)
    : idRevizie(idRevizie), idMasina(idMasina), dataProgramare(dataProgramare), detalii(detalii) {}

void Revizie::afisare() const {
    std::cout << "ID Revizie: " << idRevizie << ", ID Masina: " << idMasina
        << ", Data Programare: " << dataProgramare << ", Detalii: " << detalii << "\n";
}
