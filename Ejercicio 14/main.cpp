#include <QApplication>
#include "login.h"
#include "formulario.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Login login;
    Formulario formulario;

    // Conexión entre la señal usuarioValido() de Login y la apertura del formulario
    QObject::connect(&login, &Login::usuarioValido, [&]() {
        formulario.show();
    });

    login.show(); // Mostrar la ventana de inicio de sesión

    return a.exec();
}
