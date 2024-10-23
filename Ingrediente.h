#ifndef INGREDIENTE_H
#define INGREDIENTE_H

#include <string>

class Ingrediente {
private:
    std::string nom;
    float peso;
    int id;
    int cant;

public:
    // Constructor
    Ingrediente(const std::string& nom, float peso, int id, int cant);

    // Getters and Setters
    std::string getNom() const;
    void setNom(const std::string& nom);

    float getPeso() const;
    void setPeso(float peso);

    int getId() const;
    void setId(int id);

    int getCant() const;
    void setCant(int cant);
};

#endif
