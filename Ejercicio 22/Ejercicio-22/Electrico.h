#ifndef ELECTRICO_H
#define ELECTRICO_H

#include <iostream>

class Electrico {
public:
    Electrico() : voltaje(220) {}
    ~Electrico() {
        std::cout << "Desenchufado" << std::endl;
    }

    int obtenerVoltaje() const {
        return voltaje;
    }

private:
    int voltaje;
};

#endif // ELECTRICO_H
