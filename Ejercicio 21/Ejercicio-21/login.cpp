#include "login.h"
#include "ventana.h"
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QDebug>

Login::Login(QWidget *parent) : QWidget(parent)
{
    lUsuario = new QLabel("Usuario:");
    lClave = new QLabel("Clave:");
    leUsuario = new QLineEdit;
    leClave = new QLineEdit;
    pbValidar = new QPushButton("Validar");

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(lUsuario, 0, 0);
    layout->addWidget(leUsuario, 0, 1);
    layout->addWidget(lClave, 1, 0);
    layout->addWidget(leClave, 1, 1);
    layout->addWidget(pbValidar, 2, 0, 1, 2);

    setLayout(layout);
    connect(pbValidar, SIGNAL(clicked()), this, SLOT(validarUsuarioSlot()));
}

void Login::validarUsuarioSlot()
{
    // El resto del método sigue siendo el mismo
    QString usuario = leUsuario->text();
    QString clave = leClave->text();

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/ignad/Documents/POO/Ejercicios/Ejercicio 21/db.sqlite"); //direccion de la base en archivos

    if (!db.open()) {
        qDebug() << "Error al abrir la base de datos";
        return;
    }

    QSqlQuery query;
    query.prepare("SELECT * FROM usuarios WHERE usuario = :usuario AND clave = :clave");
    query.bindValue(":usuario", usuario);
    query.bindValue(":clave", clave);

    if (query.exec() && query.next()) {

        qDebug()<< "Inicio de sesión exitoso";     // Aquí puedes emitir una señal para notificar al resto de la aplicación

       Ventana *ventana = new Ventana;
         ventana->show();

    } else {
        qDebug() << "Credenciales incorrectas";
        // Aquí puedes mostrar un mensaje de error al usuario
         qDebug()<< "No se pudo abrir exitosamente";
    }

    db.close();
}
