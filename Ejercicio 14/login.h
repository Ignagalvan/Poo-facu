#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QDebug>

#include<QNetworkRequest>
#include<QNetworkReply>

#include<QUrl>
#include<QByteArray>

class Login : public QWidget
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    void mostrarTemperatura(bool mostrar); // Método para mostrar u ocultar la temperatura

signals:
    void usuarioValido();

protected:
    void paintEvent(QPaintEvent *); // Método para dibujar el fondo

private slots:
    void slot_ValidarUsuario();
    void slot_descargafinalizadaClima(QNetworkReply * reply);
    void slot_alternarTemperatura(); // Slot para alternar la visibilidad de la temperatura
    void slot_descargafinalizada(QNetworkReply * reply);

private:
    QLabel *lUsuario;
    QLabel *lClave;
    QLabel *lClima;
    QLineEdit *leUsuario;
    QLineEdit *leClave;
    QPushButton *pbValidar;
    QPushButton *pbAlternarTemperatura; // Botón para alternar la visibilidad de la temperatura
    QGridLayout *layout;

    QNetworkAccessManager * manager;
    QNetworkAccessManager * managerClima;
    QImage im;
};

#endif // LOGIN_H
