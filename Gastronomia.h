#ifndef GASTRONOMIA_H
#define GASTRONOMIA_H

#include <string>

class Gastronomia {
private:
    std::string tipo;

public:
    Gastronomia(const std::string& tipo);
    std::string getTipo() const;
};

#endif
