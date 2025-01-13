#ifndef MASINA_H
#define MASINA_H

#include <string>
#include <iostream>

class Masina {
private:
    int id;
    std::string marca;
    std::string model;
    std::string status;

public:
    Masina(int id, const std::string& marca, const std::string& model, const std::string& status);

    int getId() const;
    std::string getStatus() const;
    void setStatus(const std::string& status);

    void afisare() const;
};

#endif 
