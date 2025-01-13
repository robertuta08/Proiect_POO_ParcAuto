#ifndef ADMIN_H
#define ADMIN_H

#include "utilizator.h"
#include "parc_auto.h"

class Admin : public Utilizator {
public:
    Admin(int id, const std::string& nume);
    void adaugaMasina(ParcAuto& parc);
    void adaugaRevizie(ParcAuto& parc);
    void afiseazaMasini(const ParcAuto& parc) const;
    void afiseazaRevizii(const ParcAuto& parc) const;
};

#endif // ADMIN_H

