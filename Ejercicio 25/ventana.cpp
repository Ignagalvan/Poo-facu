#include "ventana.h"
#include <QVBoxLayout>

Ventana::Ventana(QWidget *parent)
    : QWidget(parent)
{
    QLabel *lUsuario = new QLabel("Nuevo Usuario:", this);
    leNuevoUsuario = new QLineEdit(this);
    QLabel *lClave = new QLabel("Nueva Clave:", this);
    leNuevaClave = new QLineEdit(this);
    leNuevaClave->setEchoMode(QLineEdit::Password); // Mostrar asteriscos para la clave
    QPushButton *pbRegistrar = new QPushButton("Registrar", this);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(lUsuario);
    layout->addWidget(leNuevoUsuario);
    layout->addWidget(lClave);
    layout->addWidget(leNuevaClave);
    layout->addWidget(pbRegistrar);

    connect(pbRegistrar, SIGNAL(clicked()), this, SLOT(registrarNuevoUsuario()));
}

void Ventana::registrarNuevoUsuario()
{
    QString nuevoUsuario = leNuevoUsuario->text();
    QString nuevaClave = leNuevaClave->text();

    // Conexión a la base de datos
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/ignad/Documents/POO/Ejercicios/Ejercicio 25/db.sqlite");

    if (!db.open()) {
        QMessageBox::critical(this, "Error", "No se pudo abrir la base de datos");
        return;
    }

    // Consulta SQL para insertar el nuevo usuario en la base de datos
    QSqlQuery query;
    query.prepare("INSERT INTO usuarios (usuario, clave) VALUES (:usuario, :clave)");
    query.bindValue(":usuario", nuevoUsuario);
    query.bindValue(":clave", nuevaClave);

    if (query.exec()) {
        QMessageBox::information(this, "Éxito", "Nuevo usuario registrado correctamente");
        // Emitir la señal para volver al login y cerrar la ventana actual
        emit volverALogin();
        this->close();
    } else {
        QMessageBox::critical(this, "Error", "Error al registrar nuevo usuario: " + query.lastError().text());
    }
}
