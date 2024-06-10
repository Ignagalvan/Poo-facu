#ifndef VENTANA_H
#define VENTANA_H

#include <QWidget>

class QPushButton;

class Ventana : public QWidget
{
    Q_OBJECT

public:
    explicit Ventana(QWidget *parent = nullptr);

signals:
    void returnToLogin();  // Señal que se emite para volver al login

private slots:
    void volverAlLogin();  // Slot para manejar el botón de volver al login

private:
    QPushButton *pbVolver;
};

#endif // VENTANA_H
