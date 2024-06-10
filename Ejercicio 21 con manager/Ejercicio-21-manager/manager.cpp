#include "manager.h"
#include "login.h"
#include "ventana.h"

Manager::Manager(QObject *parent) : QObject(parent), login(nullptr), ventana(nullptr)
{
    showLogin();  // Mostrar la ventana de login al iniciar la aplicación
}

void Manager::showLogin()
{
    if (ventana) {
        ventana->hide();  // Ocultar la ventana principal si está visible
    }
    if (!login) {
        login = new Login;  // Crear una nueva instancia de la ventana de login si no está creada
        connect(login, SIGNAL(loginSuccess()), this, SLOT(handleLoginSuccess()));  // Conectar la señal loginSuccess al slot handleLoginSuccess
    }
    login->show();  // Mostrar la ventana de login
}

void Manager::showVentana()
{
    if (login) {
        login->hide();  // Ocultar la ventana de login si está visible
    }
    if (!ventana) {
        ventana = new Ventana;  // Crear una nueva instancia de la ventana principal si no está creada
        connect(ventana, SIGNAL(returnToLogin()), this, SLOT(handleReturnToLogin()));  // Conectar la señal returnToLogin al slot handleReturnToLogin
    }
    ventana->show();  // Mostrar la ventana principal
}

void Manager::handleLoginSuccess()
{
    showVentana();  // Mostrar la ventana principal después de un login exitoso
}

void Manager::handleReturnToLogin()
{
    if (login) {
        login->clearFields();  // Limpiar los campos de usuario y clave
    }
    showLogin();  // Volver a la ventana de login desde la ventana principal
}

