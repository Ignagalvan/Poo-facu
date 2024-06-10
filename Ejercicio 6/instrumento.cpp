#include "instrumento.h"


Instrumento::Instrumento() {
    tipo = "cuerda";
    precio = 501;
}


Instrumento::Instrumento(QString t, int p) {
    tipo = t;
    precio = p;
}


void Instrumento::mostrarInfo() {
    qDebug() << "Tipo:" << tipo << ", Precio:" << precio;
}
