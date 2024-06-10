#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QMessageBox>
#include <QtSql>
#include "admindb.h"

class Login : public QWidget
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    void resetFields();

signals:
    void loginSuccessful();
    void goToRegistro();

private slots:
    void validarUsuario();
    void registrarUsuario();
    void mostrarVentanaUsuarios();  // Agregar esta ranura

private:
    QGridLayout *layout;
    QLabel *lUsuario;
    QLabel *lClave;
    QLineEdit *leUsuario;
    QLineEdit *leClave;
    QPushButton *pbValidarUsuario;
    QLabel *lRegistrarUsuario;
};

#endif // LOGIN_H
