#include "inventario.cpp"
#include "platillo.cpp"
#include "menu.cpp"
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int main() {
    Menu m;
    Inventario inv;
    Platillo platillo;

    int op1 = m.printOpcion1();
    int op2 = m.printOpcion2(op1);

    vector<Ingrediente> base = inv.leerDesdeArchivo("inventario.csv");
    
    platillo.leerArchivo("platillo.csv", inv, op2, base);
    std::vector<int> ingredientes = platillo.leerArchivoIngredientes("ingredientes.csv", op2);
    
    int op3 = m.printOpcion3();

    inv.actualizar(base, ingredientes, op3);

    return 0;
}

//g++ -o pro main.cpp && ./pro