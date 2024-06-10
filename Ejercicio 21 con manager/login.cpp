#include "login.h"
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
    leClave->setEchoMode(QLineEdit::Password);  // Ocultar el texto del campo de la clave
    pbValidar = new QPushButton("Validar");

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(lUsuario, 0, 0);
    layout->addWidget(leUsuario, 0, 1);
    layout->addWidget(lClave, 1, 0);
    layout->addWidget(leClave, 1, 1);
    layout->addWidget(pbValidar, 2, 0, 1, 2);

    setLayout(layout);
    connect(pbValidar, SIGNAL(clicked()), this, SLOT(validarUsuarioSlot()));  // Conectar el botón validar al slot validarUsuarioSlot
    connect(leClave, SIGNAL(returnPressed()), this, SLOT(validarUsuarioSlot()));  // Conectar el botón validar al slot validarUsuarioSlot

}


void Login::validarUsuarioSlot()
{
    QString usuario = leUsuario->text();
    QString clave = leClave->text();

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/ignad/Documents/POO/Ejercicios/Ejercicio 21/db.sqlite");

    if (!db.open()) {
        qDebug() << "Error al abrir la base de datos";
        return;
    }

    QSqlQuery query;
    query.prepare("SELECT * FROM usuarios WHERE usuario = :usuario AND clave = :clave");
    query.bindValue(":usuario", usuario);
    query.bindValue(":clave", clave);

    if (query.exec() && query.next()) {
        qDebug() << "Inicio de sesión exitoso";
        emit loginSuccess();  // Emitir la señal loginSuccess después de un login exitoso
    } else {
        qDebug() << "Credenciales incorrectas";
    }

    db.close();
}

void Login::clearFields()
{
    leUsuario->clear();  // Limpiar el campo de usuario
    leClave->clear();  // Limpiar el campo de clave
}
