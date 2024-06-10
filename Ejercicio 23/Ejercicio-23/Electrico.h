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

    // Declaración de función amiga
    friend void cambiarVoltaje(Electrico& electrico, int nuevoVoltaje);

private:
    int voltaje;
};

// Definición de función amiga
void cambiarVoltaje(Electrico& electrico, int nuevoVoltaje) {
    electrico.voltaje = nuevoVoltaje;
}

#endif // ELECTRICO_H
