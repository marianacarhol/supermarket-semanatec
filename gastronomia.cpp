#include "Gastronomia.h"
using namespace std;

// Constructor
Gastronomia::Gastronomia(const std::string& tipo) : tipo(tipo) {}

// Getter
std::string Gastronomia::getTipo() const {
    return tipo;
}
