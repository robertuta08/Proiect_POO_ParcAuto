#ifndef CLIENT_H
#define CLIENT_H

#include "utilizator.h"
#include "parc_auto.h"

class Client : public Utilizator {
public:
    Client(int id, const std::string& nume);
    void inchiriazaMasina(ParcAuto& parc);
    void afiseazaMasiniDisponibile(const ParcAuto& parc) const;
};

#endif 

