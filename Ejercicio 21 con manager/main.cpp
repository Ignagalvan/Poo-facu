#include <QApplication>
#include "manager.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Manager manager;  // Crear una instancia de Manager

    return a.exec();  // Ejecutar la aplicación
}
