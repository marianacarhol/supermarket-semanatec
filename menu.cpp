#include "Menu.h"
#include <iostream>

using namespace std;
Menu::Menu(){}
// Constructor
Menu::Menu(int opcion1, int opcion2, int opcion3)
    : opcion1(opcion1), opcion2(opcion2), opcion3(opcion3) {}

// Imprimir opción 1
// 
int Menu::printOpcion1() {
    std::cout << "Base de Datos (Sabor Local)" << endl << endl;
    std::cout << "¿Qué tipo de comida quieres comer hoy?" << endl;
    std::cout << "1. Asiática" << endl;
    std::cout << "2. Mexicana" << endl;
    std::cout << "3. Italiana" << endl;
    std::cin >> opcion1;
    return opcion1;
}

// Imprimir opción 2
int Menu::printOpcion2(int op){

    if (op == 1){
        std::cout << "¿Qué platillo quieres comer?" << endl;
    std::cout << "1. Pollo a la naranja" << endl;
    std::cout << "2. Carne con brocoli" << endl;
    std::cout << "3. Arroz frito" << endl;
    std::cin >> opcion2;
    return opcion2;
    } else if (op == 2){
        std::cout << "¿Qué platillo quieres comer?" << endl;
    std::cout << "4. Enchiladas suizas" << endl;
    std::cout << "5. Mole" << endl;
    std::cout << "6. Chilaquiles verdes"<< endl;
    std::cin >> opcion2;
    return opcion2;
    } else if (op == 3){
        std::cout << "¿Qué platillo quieres comer?" << endl;
    std::cout << "7. Spaguetti bolognesa" << endl;
    std::cout << "8. Pasta alfredo con pollo" << endl;
    std::cout << "9. Pizza de pepperoni" << endl;
    std::cin >> opcion2;
    return opcion2;
    } else {
        std::cout << "El elemento ingresado no es válido.";
        return -1;
    }   
}
    
// Imprimir opción 3
int Menu::printOpcion3() {
    std::cout << "¿Quieres comprarlo?" << endl;
    std::cout << "1. Sí" << endl;
    std::cout << "2. No" << endl;
    std::cin >> opcion3;
    return opcion3;
}