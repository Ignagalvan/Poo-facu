#ifndef INSTRUMENTO_H
#define INSTRUMENTO_H

#include <QString>
#include <QDebug>

// Definimos nuestra clase Instrumento
class Instrumento {
public:

    // Atributos
    QString tipo;
    int precio;
    Instrumento();


    Instrumento(QString t, int p);


    void mostrarInfo();
};

#endif // INSTRUMENTO_H
