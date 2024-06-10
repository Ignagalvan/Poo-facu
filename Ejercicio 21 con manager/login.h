#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QtSql/QtSql>

class QLabel;
class QLineEdit;
class QPushButton;

class Login : public QWidget
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
      void clearFields();  // Método para limpiar los campos de usuario y clave

signals:
    void loginSuccess();  // Señal que se emite cuando el login es exitoso

private slots:
    void validarUsuarioSlot();  // Slot para validar el usuario

private:
    QLabel *lUsuario;
    QLabel *lClave;
    QLineEdit *leUsuario;
    QLineEdit *leClave;
    QPushButton *pbValidar;
};

#endif // LOGIN_H
