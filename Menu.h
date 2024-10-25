#ifndef MENU_H
#define MENU_H

#include <string>

class Menu {
private:
    int opcion1;
    int opcion2;
    int opcion3;

public:
    Menu(int opcion1, int opcion2, int opcion3);

    void printOpcion1(int opcion1);
    void printOpcion2(int opcion2);
    void printOpcion3(int opcion3);
};

#endif
