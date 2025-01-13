#ifndef INCHIRIERE_H
#define INCHIRIERE_H

#include <string>

class Inchiriere {
private:
    int idInchiriere;
    int idMasina;
    int idClient;
    std::string dataInchiriere;
    std::string dataReturnare;

public:
    Inchiriere(int idInchiriere, int idMasina, int idClient, const std::string& dataInchiriere, const std::string& dataReturnare);

    void afisare() const;
};

#endif 
