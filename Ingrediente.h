#ifndef INGREDIENTE_H
#define INGREDIENTE_H

#include <string>
#include <iostream>
using namespace std;

class Ingrediente {
private:
    std::string nom;
    std::string unidad;
    std::string id;
    int cant;

public:
    // Constructor
    Ingrediente(const std::string& id, const std::string& nom, const std::string& unidad, int cant);

    // Getters and Setters
    std::string getNom() const;
    void setNom(const std::string& nom);

    float getPeso() const;
    void setPeso(const std::string& unidad);

    string getId() const;

    int getCant() const;
    void setCant(int cant);

    friend std::ostream& operator<<(std::ostream& os, const Ingrediente& ingrediente);
};

#endif
