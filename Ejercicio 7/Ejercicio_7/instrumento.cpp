#include "instrumento.h"

Instrumento::Instrumento() {
    tipo = "Desconocido";
    precio = 0;
}


Instrumento::Instrumento(QString t, int p) {
    tipo = t;
    precio = p;
}


void Instrumento::mostrarInfo() const {
    qDebug() << "Tipo:" << tipo << ", Precio:" << precio;
}
