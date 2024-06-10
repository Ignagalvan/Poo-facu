#include "ventana.h"
#include <QPushButton>
#include <QVBoxLayout>

Ventana::Ventana(QWidget *parent) : QWidget(parent)
{
    pbVolver = new QPushButton("Volver");

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(pbVolver);
    setLayout(layout);

    connect(pbVolver, SIGNAL(clicked()), this, SLOT(volverAlLogin()));  // Conectar el botón volver al slot volverAlLogin
}

void Ventana::volverAlLogin()
{
    emit returnToLogin();  // Emitir la señal returnToLogin para volver a la ventana de login
}
