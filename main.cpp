#include "inventario.cpp"
#include "platillo.cpp"
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int main() {
    Inventario inv;

    inv.leerDesdeArchivo("ingredientes.csv"); // Asegúrate de tener este método implementado

    // Definir el nombre del archivo de platillos
    std::string nombreArchivoPlatillos = "platillos.csv"; // Cambia el nombre según tu archivo

    // Crear una instancia de Platillo
    Platillo platillo;

    // Llamar a la función leerArchivo de Platillo
    int tipoPlatillo = 1; // Suponiendo que estás buscando el primer platillo (ajusta según sea necesario)
    platillo.leerArchivo(nombreArchivoPlatillos, inv, tipoPlatillo);

    return 0;
}

/*
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
*/

//g++ -o pro main.cpp && ./pro