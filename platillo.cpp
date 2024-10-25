#include "Platillo.h"
#include <iostream>
#include <sstream>
#include <string>
#include <vector> 
#include <fstream> 

using namespace std;

// Constructor
Platillo::Platillo() {}

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

// Leer archivo
void Platillo::leerArchivo(const string& nombreArchivo, const Inventario& inventario, int tipoPlatillo, const std::vector<Ingrediente>& baseDatos) {
    std::ifstream archivo(nombreArchivo);
    std::vector<int> ingredientes;

    if (archivo.is_open()) {
        std::string linea;
        int numeroLinea = 0;

        while (getline(archivo, linea)) {
            if (numeroLinea == tipoPlatillo - 1) {
                std::stringstream ss(linea);
                std::string nom, tipo, receta;

                getline(ss, nom, ',');
                getline(ss, tipo, ',');
                getline(ss, receta, ',');

                ingredientes = leerArchivoIngredientes("ingredientes.csv", tipoPlatillo);

                Platillo p(nom, tipo, ingredientes, receta);

                p.compararIngredientes(baseDatos, ingredientes);
            }
            numeroLinea++;
        }
        archivo.close();
    } else {
        std::cerr << "No se pudo abrir el archivo" << std::endl;
    }
}

// Leer ingredientes
std::vector<int> Platillo::leerArchivoIngredientes(const string& nombreArchivo, int tipoPlatillo) {
    std::ifstream archivo(nombreArchivo);
    std::vector<int> ingredientes;

    if (archivo.is_open()) {
        std::string linea;
        int numeroLinea = 0;

        while (getline(archivo, linea)) {
            if (numeroLinea == tipoPlatillo - 1) {
                std::stringstream ss(linea);
                std::string valor;

                while (getline(ss, valor, ',')) {
                    try {
                        int ingrediente = std::stoi(valor);
                        ingredientes.push_back(ingrediente);
                    } catch (const std::invalid_argument& e) {
                        std::cout << "No se pudo leer el valor: " << valor << std::endl;
                    } catch (const std::out_of_range& e) {
                        std::cout << "Valor fuera de rango: " << valor << std::endl;
                    }
                }
                break;
            }
            numeroLinea++;
        }
    } else {
        std::cerr << "No se pudo abrir el archivo de ingredientes" << std::endl;
    }
    return ingredientes;
}

void Platillo::compararIngredientes(const std::vector<Ingrediente>& baseDatos, const std::vector<int>& ingredientesIDs) const {
    std::vector<int> ingredientesFaltantes;

    // Comparar los IDs de los ingredientes del platillo con la base de datos
    for (const auto& idIngrediente : ingredientesIDs) {
        bool encontrado = false;

        for (const auto& ingredienteBD : baseDatos) {
            // Comparar los IDs
            if (idIngrediente == ingredienteBD.getId()) {
                if (ingredienteBD.getCant() > 0) {
                    std::cout << "Ingrediente disponible: " << ingredienteBD.getNom()
                              << " (Cantidad disponible: " << ingredienteBD.getCant() << ")" << std::endl;
                } else {
                    std::cout << "Ingrediente no disponible: " << ingredienteBD.getNom() 
                              << " (Cantidad: " << ingredienteBD.getCant() << ")" << std::endl;
                }
                encontrado = true;
                break;  // Sale del ciclo si encuentra el ingrediente
            }
        }
        if (!encontrado) {
            ingredientesFaltantes.push_back(idIngrediente);  // Agrega el ID del ingrediente faltante
        }
    }

    // Mostrar ingredientes que faltan
    if (!ingredientesFaltantes.empty()) {
        std::cout << "Faltan los siguientes ingredientes:" << std::endl;
        for (const auto& id : ingredientesFaltantes) {
            std::cout << "ID: " << id << std::endl;
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
    
    const std::vector<int>& ingredientes = platillo.getIngredientes();
    for (size_t i = 0; i < ingredientes.size(); ++i) {
        os << ingredientes[i];
        if (i != ingredientes.size() - 1) {
            os << ", ";
        }
    }
    os << "]";
    return os;
}
