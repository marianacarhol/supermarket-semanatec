#ifndef INVENTARIO_H
#define INVENTARIO_H

#include "Ingrediente.h"

class Inventario {
public:
    int getCantidad(const Ingrediente& ingrediente) const;
    void setCantidad(Ingrediente& ingrediente, int cantidad);
    std::string getNom(const Ingrediente& ingrediente) const;
};

#endif
