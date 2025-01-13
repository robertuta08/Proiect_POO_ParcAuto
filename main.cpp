#include "admin.h"
#include "client.h"
#include "parc_auto.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>


void incarcaMasiniDinFisier(ParcAuto& parc, const std::string& caleFisier) {
    std::ifstream fisier(caleFisier);
    if (!fisier.is_open()) {
        std::cerr << "Nu s-a putut deschide fișierul: " << caleFisier << "\n";
        return;
    }

    int id;
    std::string marca, model, status;
    while (fisier >> id >> marca >> model >> status) {
        parc.adaugaMasina(Masina(id, marca, model, status));
    }
    fisier.close();
}


void incarcaUtilizatori(std::vector<Utilizator*>& utilizatori, const std::string& caleFisier) {
    std::ifstream fisier(caleFisier);
    if (!fisier.is_open()) {
        std::cerr << "Nu s-a putut deschide fișierul: " << caleFisier << "\n";
        return;
    }

    int id;
    std::string nume, rol;
    while (fisier >> id >> nume >> rol) {
        if (rol == "admin") {
            utilizatori.push_back(new Admin(id, nume));
        }
        else if (rol == "client") {
            utilizatori.push_back(new Client(id, nume));
        }
    }
    fisier.close();
}


void incarcaReviziiDinFisier(ParcAuto& parc, const std::string& caleFisier) {
    std::ifstream fisier(caleFisier);
    if (!fisier.is_open()) {
        std::cerr << "Nu s-a putut deschide fișierul: " << caleFisier << "\n";
        return;
    }

    int idRevizie, idMasina;
    std::string dataProgramare, detalii;
    while (fisier >> idRevizie >> idMasina >> dataProgramare) {
        fisier.ignore(); 
        std::getline(fisier, detalii);
        parc.adaugaRevizie(Revizie(idRevizie, idMasina, dataProgramare, detalii));
    }
    fisier.close();
}


void meniuAdmin(Admin* admin, ParcAuto& parc) {
    int optiune;
    do {
        std::cout << "\n=== Meniu Admin ===\n";
        std::cout << "1. Adauga masina\n";
        std::cout << "2. Afiseaza masini\n";
        std::cout << "3. Adauga revizie\n";
        std::cout << "4. Afiseaza revizii\n";
        std::cout << "5. Iesi\n";
        std::cout << "Optiunea: ";
        std::cin >> optiune;

        switch (optiune) {
        case 1:
            admin->adaugaMasina(parc);
            break;
        case 2:
            admin->afiseazaMasini(parc);
            break;
        case 3:
            admin->adaugaRevizie(parc);
            break;
        case 4:
            admin->afiseazaRevizii(parc);
            break;
        }
    } while (optiune != 5);
}


void meniuClient(Client* client, ParcAuto& parc) {
    int optiune;
    do {
        std::cout << "\n=== Meniu Client ===\n";
        std::cout << "1. Afiseaza masini disponibile\n";
        std::cout << "2. Inchiriaza masina\n";
        std::cout << "3. Iesi\n";
        std::cout << "Optiunea: ";
        std::cin >> optiune;

        switch (optiune) {
        case 1:
            client->afiseazaMasiniDisponibile(parc);
            break;
        case 2:
            client->inchiriazaMasina(parc);
            break;
        }
    } while (optiune != 3);
}

int main() {
    ParcAuto parc;
    std::vector<Utilizator*> utilizatori;

    
    incarcaMasiniDinFisier(parc, "../date/masini.txt");
    incarcaUtilizatori(utilizatori, "../date/utilizatori.txt");
    incarcaReviziiDinFisier(parc, "../date/revizii.txt");

    
    Admin* admin = nullptr;
    Client* client = nullptr;

    for (auto utilizator : utilizatori) {
        if (utilizator->getRol() == "admin" && admin == nullptr) {
            admin = dynamic_cast<Admin*>(utilizator);
        }
        else if (utilizator->getRol() == "client" && client == nullptr) {
            client = dynamic_cast<Client*>(utilizator);
        }
    }

    if (admin == nullptr || client == nullptr) {
        std::cerr << "Nu au fost găsiți utilizatori corespunzători pentru testare!\n";
        return 1;
    }

   
    int optiune;
    do {
        std::cout << "\n=== Sistem de Gestionare Parc Auto ===\n";
        std::cout << "1. Admin\n";
        std::cout << "2. Client\n";
        std::cout << "3. Iesi\n";
        std::cout << "Optiunea: ";
        std::cin >> optiune;

        switch (optiune) {
        case 1:
            meniuAdmin(admin, parc);
            break;
        case 2:
            meniuClient(client, parc);
            break;
        }
    } while (optiune != 3);

    
    for (auto utilizator : utilizatori) {
        delete utilizator;
    }

    return 0;
}