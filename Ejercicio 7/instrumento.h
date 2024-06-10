#ifndef INSTRUMENTO_H
#define INSTRUMENTO_H

#include <QString>
#include <QDebug>


class Instrumento {
public:
    // Atributos
    QString tipo;
    int precio;


    Instrumento();


    Instrumento(QString t, int p);


    void mostrarInfo() const;
};

#endif // INSTRUMENTO_H
