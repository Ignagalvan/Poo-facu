#include "login.h"
#include "ventana.h"
#include "ventanausuarios.h"

Login::Login(QWidget *parent) : QWidget(parent)
{
    layout = new QGridLayout(this);
    lUsuario = new QLabel("Usuario:", this);
    lClave = new QLabel("Clave:", this);
    leUsuario = new QLineEdit(this);
    leClave = new QLineEdit(this);
    leClave->setEchoMode(QLineEdit::Password);
    pbValidarUsuario = new QPushButton("Validar Usuario", this);
    lRegistrarUsuario = new QLabel("<a href=\"#\">Registrar Nuevo Usuario</a>", this);

    layout->addWidget(lUsuario, 0, 0);
    layout->addWidget(leUsuario, 0, 1);
    layout->addWidget(lClave, 1, 0);
    layout->addWidget(leClave, 1, 1);
    layout->addWidget(pbValidarUsuario, 2, 0, 1, 2);
    layout->addWidget(lRegistrarUsuario, 3, 0, 1, 2);

    connect(pbValidarUsuario, SIGNAL(clicked()), this, SLOT(validarUsuario()));
    connect(lRegistrarUsuario, SIGNAL(linkActivated(QString)), this, SLOT(registrarUsuario()));
}

void Login::validarUsuario()
{
    QString usuario = leUsuario->text();
    QString clave = leClave->text();

    QSqlDatabase db = AdminDB::getInstance().getDatabase();
    QSqlQuery query(db);
    query.prepare("SELECT * FROM usuarios WHERE usuario = :usuario AND clave = :clave");
    query.bindValue(":usuario", usuario);
    query.bindValue(":clave", clave);

    if (query.exec() && query.next())
    {
        QMessageBox::information(this, "Éxito", "Inicio de sesión exitoso");
        emit loginSuccessful();
    }
    else
    {
        QMessageBox::warning(this, "Error", "Usuario o clave incorrectos");
        resetFields();
    }
}

void Login::registrarUsuario()
{
    Ventana *ventana = new Ventana();
    connect(ventana, SIGNAL(volverALogin()), this, SLOT(show()));
    connect(ventana, SIGNAL(volverALogin()), this, SLOT(resetFields()));
    ventana->show();
    this->close();
}

void Login::resetFields()
{
    leUsuario->clear();
    leClave->clear();
}

void Login::mostrarVentanaUsuarios()
{
    VentanaUsuarios *ventanaUsuarios = new VentanaUsuarios();
    connect(ventanaUsuarios, SIGNAL(volverALogin()), this, SLOT(show()));
    ventanaUsuarios->show();
    this->close();
}
