#ifndef MANAGER_H
#define MANAGER_H

#include <QObject>
#include <QWidget>

// Forward declarations to avoid circular dependencies
class Login;
class Ventana;

class Manager : public QObject
{
    Q_OBJECT

public:
    explicit Manager(QObject *parent = nullptr);  // Constructor de la clase Manager
    void showLogin();  // Método para mostrar la ventana de login
    void showVentana();  // Método para mostrar la ventana principal

private slots:
    void handleLoginSuccess();  // Slot para manejar el éxito del login
    void handleReturnToLogin();  // Slot para manejar el retorno al login


private:
    Login *login;  // Puntero a la instancia de la ventana de login
    Ventana *ventana;  // Puntero a la instancia de la ventana principal
};

#endif // MANAGER_H
