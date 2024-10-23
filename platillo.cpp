#include "Platillo.h"

// Constructor
Platillo::Platillo(const std::string& nom, const std::string& tipo, const std::string& receta)
    : Gastronomia(tipo), nom(nom), receta(receta) {}

// Getters
std::string Platillo::getNom() const {
    return nom;
}

std::string Platillo::getTipo() const {
    return Gastronomia::getTipo();
}

std::vector<Ingrediente> Platillo::getIngredientes() const {
    return ingredientes;
}

std::string Platillo::getReceta() const {
    return receta;
}

// Agregar ingrediente
void Platillo::agregarIngrediente(const Ingrediente& ingrediente) {
    ingredientes.push_back(ingrediente);
}
