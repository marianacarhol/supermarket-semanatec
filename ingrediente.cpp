#include "Ingrediente.h"

// Constructor
Ingrediente::Ingrediente(const std::string& nom, float peso, int id, int cant)
    : nom(nom), peso(peso), id(id), cant(cant) {}

// Getters and Setters
std::string Ingrediente::getNom() const {
    return nom;
}

void Ingrediente::setNom(const std::string& nom) {
    this->nom = nom;
}

float Ingrediente::getPeso() const {
    return peso;
}

void Ingrediente::setPeso(float peso) {
    this->peso = peso;
}

int Ingrediente::getId() const {
    return id;
}

void Ingrediente::setId(int id) {
    this->id = id;
}

int Ingrediente::getCant() const {
    return cant;
}

void Ingrediente::setCant(int cant) {
    this->cant = cant;
}
