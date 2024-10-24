// ingrediente.cpp
#include "Ingrediente.h"

// Constructor
Ingrediente::Ingrediente(const std::string& id, const std::string& nom, const std::string& unidad, int cant)
    : id(id), nom(nom), unidad(unidad), cant(cant) {}

// Getters
std::string Ingrediente::getNom() const {
    return nom;
}

void Ingrediente::setNom(const std::string& nom) {
    this->nom = nom;
}

float Ingrediente::getPeso() const {
    return std::stof(unidad); // Suponiendo que 'unidad' contiene el peso en forma de cadena
}

void Ingrediente::setPeso(const std::string& unidad) {
    this->unidad = unidad;
}

std::string Ingrediente::getId() const {
    return id;
}

int Ingrediente::getCant() const {
    return cant;
}

void Ingrediente::setCant(int cant) {
    this->cant = cant;
}

// Sobrecarga del operador de salida
std::ostream& operator<<(std::ostream& os, const Ingrediente& ingrediente) {
    os << "ID: " << ingrediente.id << ", Nombre: " << ingrediente.nom 
       << ", Unidad: " << ingrediente.unidad << ", Cantidad: " << ingrediente.cant;
    return os;
}
