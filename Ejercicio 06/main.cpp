#include <QCoreApplication>
#include "instrumento.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);


    Instrumento instrumento1;
    Instrumento instrumento2("Guitarra", 500);


    qDebug() << "Instrumento 1:";
    instrumento1.mostrarInfo();

    qDebug() << "\nInstrumento 2:";
    instrumento2.mostrarInfo();

    return a.exec();
}
