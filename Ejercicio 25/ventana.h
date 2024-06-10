#ifndef VENTANA_H
#define VENTANA_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QtSql>

class Ventana : public QWidget
{
    Q_OBJECT

public:
    explicit Ventana(QWidget *parent = nullptr);

signals:
    void volverALogin();

private slots:
    void registrarNuevoUsuario();

private:
    QLineEdit *leNuevoUsuario;
    QLineEdit *leNuevaClave;
};

#endif // VENTANA_H
