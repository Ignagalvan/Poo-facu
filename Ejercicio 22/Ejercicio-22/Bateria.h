#ifndef BATERIA_H
#define BATERIA_H

#include "instrumento.h"

class Bateria : public instrumento {
public:
    Bateria() : tambores(5) {}

    QString obtenerNombre() const override {
        return "Bateria";
    }

    void tocar() const override {
        std::cout << "Tocando la bateria" << std::endl;
    }

    void sonar() const override {
        std::cout << obtenerNombre().toStdString() << " suena..." << std::endl;

    }

    void verlo() const override {
        instrumento::verlo();
        std::cout << "Tambores: " << getTambores() << std::endl;
    }

    // Métodos get y set para tambores
    int getTambores() const {
        return tambores;
    }

    void setTambores(int nuevosTambores) {
        tambores = nuevosTambores;
    }

private:
    int tambores;
};

#endif // BATERIA_H
