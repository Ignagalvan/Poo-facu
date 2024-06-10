#include "formulario.h"

Formulario::Formulario(QWidget *parent) : QWidget(parent)
{
    lLegajo = new QLabel("Legajo:");
    lNombre = new QLabel("Nombre:");
    lApellido = new QLabel("Apellido:");
    leLegajo = new QLineEdit;
    leNombre = new QLineEdit;
    leApellido = new QLineEdit;
    pbGuardar = new QPushButton("Guardar");

    layout = new QVBoxLayout(this);
    layout->addWidget(lLegajo);
    layout->addWidget(leLegajo);
    layout->addWidget(lNombre);
    layout->addWidget(leNombre);
    layout->addWidget(lApellido);
    layout->addWidget(leApellido);
    layout->addWidget(pbGuardar);
}
