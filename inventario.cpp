#include "Inventario.h"
#include <iostream>
#include <sstream>
#include <string>
#include <vector> 
#include <fstream> 
using namespace std;

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

void Inventario::leerDesdeArchivo(const string& nombreArchivo) {
    ifstream archivo(nombreArchivo);

    if (archivo.is_open()) {
        std::string linea;
        // Leer cada línea del archivo CSV
        while (getline(archivo, linea)) {
            std::stringstream ss(linea);
            std::string unidad, nom, id, cant_str;
            int cant;

            // Separar los valores por comas
            getline(ss, id, ',');
            getline(ss, nom, ',');
            getline(ss, unidad, ',');
            getline(ss, cant_str, ',');
 
            cant = std::stoi(cant_str);

            Ingrediente i(id, nom, unidad, cant);
            inventarioIngredientes.push_back(i);
        }
        archivo.close();  // Cerrar el archivo
    } else {
        std::cerr << "No se pudo abrir el archivo" << std::endl;
    }
}

void Inventario::imprimir(const std::vector<Ingrediente>& ingredientes) const {
    for (const auto& i : ingredientes) {
        std::cout << i << std::endl; 
    }
}

