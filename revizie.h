#ifndef REVIZIE_H
#define REVIZIE_H

#include <string>

class Revizie {
private:
    int idRevizie;
    int idMasina;
    std::string dataProgramare;
    std::string detalii;

public:
    Revizie(int idRevizie, int idMasina, const std::string& dataProgramare, const std::string& detalii);

    void afisare() const;
};

#endif 

