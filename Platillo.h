#ifndef PLATILLO_H
#define PLATILLO_H

#include "Ingrediente.h"
#include "Gastronomia.h"
#include <string>
#include <vector>

class Platillo : public Gastronomia {
private:
    std::string nom;
    std::vector<Ingrediente> ingredientes;
    std::string receta;

public:
    Platillo(const std::string& nom, const std::string& tipo, const std::string& receta);

    // Getters
    std::string getNom() const;
    std::string getTipo() const;
    std::vector<Ingrediente> getIngredientes() const;
    std::string getReceta() const;

    // Agregar ingredientes
    void agregarIngrediente(const Ingrediente& ingrediente);
};

#endif
