#ifndef PLATILLO_H
#define PLATILLO_H

#include <string>
#include <vector>

class Platillo {
private:
    std::string nom;
    std::string tipo;
    std::vector<int> ingredientes;
    std::string receta;

public:
    // Constructor
    Platillo();
    
    Platillo(const std::string& nom, const std::string& tipo, const std::vector<int>& ingredientes, const std::string& receta);

    // Getters
    std::string getNom() const;
    std::string getTipo() const;
    std::string getIngredientes() const;
    std::string getReceta() const;

    // Agregar ingredientes
    void leerArchivo(const string& nombreArchivo);
    void imp(const std::vector<Platillo>& platillos) const;
    void mostrarIngredientes()const;

    friend std::ostream& operator<<(std::ostream& os, const Platillo& platillo);

    std::vector<int> leerArchivoIngredientes(const std::string& nombreArchivo, int tipoPlatillo);

    
};

#endif
