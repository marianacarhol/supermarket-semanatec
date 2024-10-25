#ifndef INGREDIENTE_H
#define INGREDIENTE_H

#include <string>
#include <iostream>
using namespace std;

class Ingrediente {
private:
    std::string nom;
    std::string unidad;
    int id;
    int cant;

public:
    // Constructor
    Ingrediente(int id, const std::string& nom, const std::string& unidad, int cant);

    // Getters and Setters
    std::string getNom() const;
    void setNom(const std::string& nom);

    std::string getUnidad() const;
    void setUnidad(const std::string& unidad);

    int getId() const;

    int getCant() const;
    void setCant(int cant);

    friend std::ostream& operator<<(std::ostream& os, const Ingrediente& ingrediente);
};

#endif
