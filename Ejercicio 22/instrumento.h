#ifndef INSTRUMENTO_H
#define INSTRUMENTO_H

#include <QString>
#include <iostream>

class instrumento {
public:
    instrumento() : marca("Yamaha") {}
    virtual ~instrumento() {}

    virtual QString obtenerNombre() const = 0;
    virtual void tocar() const = 0;
    virtual void sonar() const = 0;  // Nueva función virtual pura
    virtual void verlo() const {
        std::cout << "Marca: " << marca.toStdString() << std::endl;
    }

protected:
    QString marca;
};

#endif // INSTRUMENTO_H
