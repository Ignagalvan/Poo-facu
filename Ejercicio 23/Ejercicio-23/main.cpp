#include <QCoreApplication>
#include <vector>
#include "Guitarra.h"
#include "Bateria.h"
#include "Teclado.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    std::vector<instrumento*> instrumentos;

    // Instanciar 5 objetos
    instrumentos.push_back(new Guitarra());
    instrumentos.push_back(new Bateria());
    instrumentos.push_back(new Teclado());
    instrumentos.push_back(new Guitarra());
    instrumentos.push_back(new Bateria());

    // Recorrer el vector y llamar a los métodos de los instrumentos
    for (auto* inst : instrumentos) {
        inst->tocar();
        inst->sonar();
        inst->verlo(); // Publicar la marca del instrumento y sus atributos específicos
    }

    // Cambiar el voltaje de un objeto Electrico mediante la función amiga
    Electrico electrico;
    std::cout << "Voltaje antes de cambiar: " << electrico.obtenerVoltaje() << std::endl;
    cambiarVoltaje(electrico, 110);
    std::cout << "Voltaje después de cambiar: " << electrico.obtenerVoltaje() << std::endl;

    // Liberar la memoria asignada
    for (auto* inst : instrumentos) {
        delete inst;
    }

    return a.exec();
}
