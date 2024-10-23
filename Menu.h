#ifndef MENU_H
#define MENU_H

#include <string>

class Menu {
private:
    std::string opcion1;
    std::string opcion2;

public:
    Menu(const std::string& opcion1, const std::string& opcion2);

    void print(const std::string& opcion1) const;
    void printOpcion2(const std::string& opcion2) const;
};

#endif
