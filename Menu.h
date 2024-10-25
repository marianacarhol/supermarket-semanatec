#ifndef MENU_H
#define MENU_H

#include <string>

class Menu {
private:
    int opcion1;
    int opcion2;
    int opcion3;

public:
    Menu();

    Menu(int opcion1, int opcion2, int opcion3);

    int printOpcion1();
    int printOpcion2(int opcion2);
    int printOpcion3();
};

#endif
