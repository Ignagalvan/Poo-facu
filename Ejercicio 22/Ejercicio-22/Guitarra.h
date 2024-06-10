#ifndef GUITARRA_H
#define GUITARRA_H

#include "instrumento.h"

class Guitarra : public instrumento {
public:
    Guitarra() : cuerdas(6) {}

    QString obtenerNombre() const override {
        return "Guitarra";
    }

    void tocar() const override {
        std::cout << "Tocando la guitarra" << std::endl;
    }

    void sonar() const override {
        std::cout << obtenerNombre().toStdString() << " suena..." << std::endl;

    }

    void verlo() const override {
        instrumento::verlo();
        std::cout << "Cuerdas: " << getCuerdas() << std::endl;
    }

    // Métodos get y set para cuerdas
    int getCuerdas() const {
        return cuerdas;
    }

    void setCuerdas(int nuevasCuerdas) {
        cuerdas = nuevasCuerdas;
    }

private:
    int cuerdas;
};

#endif // GUITARRA_H
