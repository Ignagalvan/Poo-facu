#include <QApplication>
#include "ventana.h"
#include "login.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Crear una instancia de la clase Login
    Login login;

    // Mostrar la ventana de login
    login.show();


    return a.exec();
}
