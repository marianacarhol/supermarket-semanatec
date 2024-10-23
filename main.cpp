
#include "Ingrediente.h"
#include "Platillo.h"
#include "Inventario.h"
#include "Menu.h"
#include <iostream>

int main() {
    // Crear ingredientes
    Ingrediente ing1("Tomate", 0.2, 1, 10);
    Ingrediente ing2("Cebolla", 0.15, 2, 5);

    // Crear platillo
    Platillo platillo("Ensalada", "Mediterránea", "Cortar y mezclar todos los ingredientes.");
    platillo.agregarIngrediente(ing1);
    platillo.agregarIngrediente(ing2);

    // Crear inventario
    Inventario inventario;
    std::cout << "Cantidad de tomates: " << inventario.getCantidad(ing1) << std::endl;

    // Crear menú
    Menu menu("Ensalada", "Sopa");
    menu.print("Ensalada");
    menu.printOpcion2("Sopa");

    return 0;
}
