#include "Menu.h"
#include <iostream>

// Constructor
Menu::Menu(const std::string& opcion1, const std::string& opcion2)
    : opcion1(opcion1), opcion2(opcion2) {}

// Imprimir opción 1
void Menu::print(const std::string& opcion1) const {
    std::cout << "Opción 1: " << opcion1 << std::endl;
}

// Imprimir opción 2
void Menu::printOpcion2(const std::string& opcion2) const {
    std::cout << "Opción 2: " << opcion2 << std::endl;
}
