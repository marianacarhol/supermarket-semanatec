#include "Platillo.h"
#include <iostream>
#include <sstream>
#include <string>
#include <vector> 
#include <fstream> 
using namespace std;

// Constructor
Platillo::Platillo(){};

Platillo::Platillo(const std::string& nom, const std::string& tipo, cons std::vector<int>& ingredientes, const std::string& receta)
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
void Platillo::leerArchivo(const string& nombreArchivo, int tipoPlatillo) {
    std::ifstream archivo(nombreArchivo);

    if (archivo.is_open()) {
        std::string linea;
        int numeroLinea = 0;

        // Leer cada línea del archivo CSV
        while (getline(archivo, linea)) {
            if(numeroLinea == tipoPlatillo){
                std::stringstream ss(linea);
                std::string nom, tipo, receta;

                // Separar los valores por comas
                getline(ss, nom, ',');
                getline(ss, tipo, ',');
                getline(ss, receta, ',');

                std::vector<int> ingredientes = leerArchivoIngredientes("ingredientes.csv", tipoPlatillo);

                Platillo p(nom, tipo, ingredientes, receta);

                p.mostrarIngredientes();
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
            if (numeroLinea == tipoPlatillo) {
                std::stringstream ss(linea);
                int numeroDeElementos;
                ss >> numeroDeElementos;

                // Leer los ingredientes
                for (int i = 0; i < numeroDeElementos; i++) {
                    int valor;
                    if (ss >> valor) {
                        ingredientes.push_back(valor);  // Agregar al vector
                    } else {
                        std::cout << "No se pudo leer el valor #" << (i + 1) << std::endl;
                        break; 
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

void Platillo::mostrarIngredientes() const {
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
    os << "Nombre: " << platillo.getNom() << ", Tipo: " << platillo.getTipo()
       << ", Ingredientes: " << platillo.getIngredientes() << ", Receta: " << platillo.getReceta();
    return os;
}