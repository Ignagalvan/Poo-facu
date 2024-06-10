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

private slots:
    void validarUsuarioSlot();

private:
    QLabel *lUsuario;
    QLabel *lClave;
    QLineEdit *leUsuario;
    QLineEdit *leClave;
    QPushButton *pbValidar;



};

#endif // LOGIN_H
