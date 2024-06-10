#include <QCoreApplication>
#include <QDebug>
#include <vector>
#include <algorithm> // Para std::sort
#include "instrumento.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // Creamos objetos de la clase Instrumento
    Instrumento instrumento1("Guitarra", 500);
    Instrumento instrumento2("Piano", 1000);
    Instrumento instrumento3("Batería", 800);

    // Creamos un vector para almacenar los instrumentos
    std::vector<Instrumento> instrumentos;

    // Agregamos los instrumentos al vector
    instrumentos.push_back(instrumento1);
    instrumentos.push_back(instrumento2);
    instrumentos.push_back(instrumento3);


    auto compararPorPrecio = [](const Instrumento &a, const Instrumento &b) {
        return a.precio < b.precio;
    };


    std::sort(instrumentos.begin(), instrumentos.end(), compararPorPrecio);

    // Mostramos los instrumentos ordenados
    qDebug() << "Instrumentos ordenados por precio (de menor a mayor):";
    for(const auto &instrumento : instrumentos) {
        instrumento.mostrarInfo();
    }

    return a.exec();
}
