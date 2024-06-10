#ifndef TECLADO_H
#define TECLADO_H

#include "instrumento.h"
#include "Electrico.h"

class Teclado : public instrumento, public Electrico {
public:
    Teclado() : teclas(61) {}

    QString obtenerNombre() const override {
        return "Teclado";
    }

    void tocar() const override {
        std::cout << "Tocando el teclado" << std::endl;
    }

    void sonar() const override {
        std::cout << obtenerNombre().toStdString() << " suena..." << std::endl;
    }

    void verlo() const override {
        instrumento::verlo();
        std::cout << "Teclas: " << getTeclas() << std::endl;
        std::cout << "Voltaje: " << obtenerVoltaje() << " voltios" << std::endl;
    }

    // Métodos get y set para teclas
    inline int getTeclas() const {
        return teclas;
    }

    inline void setTeclas(int nuevasTeclas) {
        teclas = nuevasTeclas;
    }

private:
    int teclas;
};

#endif // TECLADO_H
