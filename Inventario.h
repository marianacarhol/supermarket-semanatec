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
    std::vector<Ingrediente> leerDesdeArchivo(const std::string& nombreArchivo) const;
    std::vector<Ingrediente> inventarioIngredientes;
    void imprimir(const std::vector<Ingrediente>& inventarioIngredientes) const;
    void actualizar(std::vector<Ingrediente>& ingredientes, const std::vector<int>& ingredientesIDs, int op);
};

#endif
