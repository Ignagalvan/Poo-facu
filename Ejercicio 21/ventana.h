// En ventana.h
#ifndef VENTANA_H
#define VENTANA_H

#include <QWidget>

class QPushButton;
class Login;

class Ventana : public QWidget
{
    Q_OBJECT

public:
    explicit Ventana(QWidget *parent = nullptr);

public slots:
    void mostrarVentana(); // Slot para mostrar la ventana

private slots:
    void volverAlLogin(); // Slot para volver al login

private:
    QPushButton *pbVolver;
};

#endif // VENTANA_H
