#ifndef VENTANAUSUARIOS_H
#define VENTANAUSUARIOS_H

#include <QWidget>
#include <QTreeWidget>
#include <QVBoxLayout>
#include <QtSql>
#include <QPushButton>

class VentanaUsuarios : public QWidget
{
    Q_OBJECT

public:
    explicit VentanaUsuarios(QWidget *parent = nullptr);

signals:
    void volverALogin();

private:
    QTreeWidget *treeWidgetUsuarios;
    QPushButton *pbBorrar;
    QPushButton *pbGuardar;
    QPushButton *pbVolverLogin;
    void cargarUsuarios();

private slots:

    void borrarUsuario();
    void guardarCambios();
    void volverAlLogin();
    void handleItemDoubleClicked(QTreeWidgetItem *item, int column);
};

#endif // VENTANAUSUARIOS_H
