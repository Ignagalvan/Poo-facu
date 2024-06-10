// En ventana.cpp
#include "ventana.h"
#include <QPushButton>
#include <QVBoxLayout>

Ventana::Ventana(QWidget *parent) : QWidget(parent)
{
    pbVolver = new QPushButton("Volver");

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(pbVolver);
    setLayout(layout);

  //  pbVolver->hide(); // Inicialmente ocultamos el botón "Volver"
    connect(pbVolver, SIGNAL(clicked()), this, SLOT(volverAlLogin()));
}

void Ventana::mostrarVentana()
{
    // Mostrar la ventana y el botón "Volver"
    show();
    pbVolver->show();
     close();
}

void Ventana::volverAlLogin()
{
    // Ocultar la ventana principal
    hide();
    // Ocultar el botón "Volver"
    pbVolver->hide();
}

