#ifndef INVENTARIO_H
#define INVENTARIO_H

#include "ingrediente.cpp"
#include <string>
#include <vector>
using namespace std;

class Inventario {
public:
    int getCantidad(const Ingrediente& ingrediente) const;
    void setCantidad(Ingrediente& ingrediente, int cantidad);
    std::string getNom(const Ingrediente& ingrediente) const;
    void leerDesdeArchivo(const std::string& nombreArchivo);
    std::vector<Ingrediente> inventarioIngredientes;
    void imprimir(const std::vector<Ingrediente>& inventarioIngredientes) const;
};

#endif
