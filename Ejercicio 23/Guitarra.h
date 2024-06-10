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
    inline int getCuerdas() const {
        return cuerdas;
    }

    inline void setCuerdas(int nuevasCuerdas) {
        cuerdas = nuevasCuerdas;
    }

    // Declaración de función amiga
    friend void ajustarCuerdas(Guitarra& guitarra, int nuevasCuerdas);

private:
    int cuerdas;
};

// Definición de función amiga
void ajustarCuerdas(Guitarra& guitarra, int nuevasCuerdas) {
    guitarra.cuerdas = nuevasCuerdas;
}

#endif // GUITARRA_H
