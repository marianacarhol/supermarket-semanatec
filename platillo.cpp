//platillo.cpp
#include "Platillo.h"
#include <iostream>
#include <sstream>
#include <string>
#include <vector> 
#include <fstream> 
using namespace std;

// Constructor
Platillo::Platillo(){};

Platillo::Platillo(const std::string& nom, const std::string& tipo, const std::vector<int>& ingredientes, const std::string& receta)
    : tipo(tipo), nom(nom), ingredientes(ingredientes), receta(receta) {}

// Getters
std::string Platillo::getNom() const {
    return nom;
}

std::string Platillo::getTipo() const {
    return tipo;
}

std::vector<int> Platillo::getIngredientes() const {
    return ingredientes;
}

std::string Platillo::getReceta() const {
    return receta;
}

// Agregar ingrediente
void Platillo::leerArchivo(const string& nombreArchivo, const Inventario& inventario, int tipoPlatillo) {
    std::ifstream archivo(nombreArchivo);

    if (archivo.is_open()) {
        std::string linea;
        int numeroLinea = 0;

        // Leer cada línea del archivo CSV
        while (getline(archivo, linea)) {
            if(numeroLinea == tipoPlatillo-1){
                std::stringstream ss(linea);
                std::string nom, tipo, receta;

                // Separar los valores por comas
                getline(ss, nom, ',');
                getline(ss, tipo, ',');
                getline(ss, receta, ',');

                std::vector<int> ingredientes = leerArchivoIngredientes("ingredientes.csv", tipoPlatillo);

                Platillo p(nom, tipo, ingredientes, receta);

                p.mostrarIngredientes();

                std::vector<Ingrediente> baseDatos = inventario.leerDesdeArchivo("ingredientes.csv");
 
                p.compararIngredientes(baseDatos);
            }
            numeroLinea++;
        }
        archivo.close();  // Cerrar el archivo
    } else {
        std::cerr << "No se pudo abrir el archivo" << std::endl;
    }
}

// Hacer vector
std::vector<int> Platillo::leerArchivoIngredientes(const string& nombreArchivo, int tipoPlatillo) {
    std::ifstream archivo(nombreArchivo);
    std::vector<int> ingredientes;

    if (archivo.is_open()) {
        std::string linea;
        int numeroLinea = 0;

        // Leer cada línea del archivo
        while (getline(archivo, linea)) {
            if (numeroLinea == tipoPlatillo-1) {
                std::stringstream ss(linea);
                std::string valor;

                // Leer ingredientes separados por comas
                while (getline(ss, valor, ',')) {
                    try {
                        int ingrediente = std::stoi(valor); // Convertir de string a int
                        ingredientes.push_back(ingrediente);  // Agregar al vector
                    } catch (const std::invalid_argument& e) {
                        std::cout << "No se pudo leer el valor: " << valor << std::endl;
                    } catch (const std::out_of_range& e) {
                        std::cout << "Valor fuera de rango: " << valor << std::endl;
                    }
                }
                break; // Salir del bucle después de encontrar la línea correcta
            }
            numeroLinea++;
        }
    } else {
        std::cerr << "No se pudo abrir el archivo de ingredientes" << std::endl;
    }
    return ingredientes;
}

void Platillo::compararIngredientes(const std::vector<Ingrediente>& baseDatos) const {
    std::vector<std::string> ingredientesFaltantes;

    for (const auto& id : ingredientes) {
        bool encontrado = false;
        std::string ID = std::to_string(id);
        for (const auto& ingrediente : baseDatos) {
            if (ingrediente.getId() == ID) {
                encontrado = true;
                std::cout << "Ingrediente disponible: " << ingrediente.getNom() << std::endl;
                break;
            }
        }
        if (!encontrado) {
            ingredientesFaltantes.push_back(ID);
        }
    }

    // Mostrar ingredientes que faltan
    if (!ingredientesFaltantes.empty()) {
        std::cout << "Faltan los siguientes ingredientes:" << std::endl;
        for (const auto& id : ingredientesFaltantes) {
            std::cout << "ID: " << id << std::endl; // Puedes agregar lógica para mostrar el nombre si lo tienes
        }
    }
}



void Platillo::mostrarIngredientes() const {
    if (ingredientes.empty()) {
        std::cout << "No hay ingredientes para mostrar." << std::endl;
        return;
    }

    std::cout << "Ingredientes:" << std::endl;
    for (const auto& ingrediente : ingredientes) {
        std::cout << ingrediente << std::endl;
    }
}


void Platillo::imp(const std::vector<Platillo>& platillos) const {
    for (const auto& p : platillos) {
        std::cout << p << std::endl; 
    }
}

// Sobrecarga del operador de salida
std::ostream& operator<<(std::ostream& os, const Platillo& platillo) {
    os << "Nombre: " << platillo.getNom() << ", Tipo: " << platillo.getTipo() << ", Ingredientes: [";
    
    // Recorremos el vector de ingredientes
    const std::vector<int>& ingredientes = platillo.getIngredientes();
    for (size_t i = 0; i < ingredientes.size(); ++i) {
        os << ingredientes[i];
        if (i != ingredientes.size() - 1) {
            os << ", ";  // Separador entre ingredientes
        }
    }
    
    os << "], Receta: " << platillo.getReceta();
    return os;
}
