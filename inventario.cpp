#include "Inventario.h"

// Obtener la cantidad de un ingrediente
int Inventario::getCantidad(const Ingrediente& ingrediente) const {
    return ingrediente.getCant();
}

// Establecer la cantidad de un ingrediente
void Inventario::setCantidad(Ingrediente& ingrediente, int cantidad) {
    ingrediente.setCant(cantidad);
}

// Obtener el nombre de un ingrediente
std::string Inventario::getNom(const Ingrediente& ingrediente) const {
    return ingrediente.getNom();
}
