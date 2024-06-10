#include <QApplication>
#include "login.h"
#include "ventanausuarios.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    Login login;

    QObject::connect(&login, SIGNAL(loginSuccessful()), &login, SLOT(mostrarVentanaUsuarios()));

    login.show();
    return a.exec();
}
