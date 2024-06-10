#include "ventanausuarios.h"
#include "admindb.h"
#include <QVBoxLayout>
#include <QHeaderView>
#include <QSqlError>
#include <QMessageBox>

VentanaUsuarios::VentanaUsuarios(QWidget *parent) : QWidget(parent)
{
    QVBoxLayout *layout = new QVBoxLayout(this);
    treeWidgetUsuarios = new QTreeWidget(this);
    treeWidgetUsuarios->setColumnCount(2);
    treeWidgetUsuarios->setHeaderLabels(QStringList() << "Usuario" << "Clave");

    treeWidgetUsuarios->header()->setSectionResizeMode(QHeaderView::Stretch);

    layout->addWidget(treeWidgetUsuarios);

    pbBorrar = new QPushButton("Borrar", this);
    pbGuardar = new QPushButton("Guardar", this);
    pbVolverLogin = new QPushButton("Volver al Login", this);

    layout->addWidget(pbBorrar);
    layout->addWidget(pbGuardar);
    layout->addWidget(pbVolverLogin);

    connect(pbBorrar, SIGNAL(clicked()), this, SLOT(borrarUsuario()));
    connect(pbGuardar, SIGNAL(clicked()), this, SLOT(guardarCambios()));
    connect(pbVolverLogin, SIGNAL(clicked()), this, SLOT(volverAlLogin()));

    connect(treeWidgetUsuarios, &QTreeWidget::itemDoubleClicked, this, &VentanaUsuarios::handleItemDoubleClicked);

    cargarUsuarios();
}

void VentanaUsuarios::handleItemDoubleClicked(QTreeWidgetItem *item, int column)
{
    treeWidgetUsuarios->setEditTriggers(QAbstractItemView::DoubleClicked);
}

void VentanaUsuarios::cargarUsuarios()
{
    QSqlDatabase db = AdminDB::getInstance().getDatabase();
    QSqlQuery query(db);
    query.prepare("SELECT * FROM usuarios");

    if (query.exec())
    {
        while (query.next())
        {
            QTreeWidgetItem *item = new QTreeWidgetItem(treeWidgetUsuarios);
            QString usuario = query.value("usuario").toString();
            QString clave = query.value("clave").toString();

            item->setText(0, usuario);
            item->setText(1, clave);

            // Guardar el usuario original en datos adicionales del elemento
            item->setData(0, Qt::UserRole, usuario);
            item->setFlags(item->flags() | Qt::ItemIsEditable);
        }
    }
    else
    {
        QMessageBox::critical(this, "Error", "No se pudo obtener la lista de usuarios: " + query.lastError().text());
    }
}

void VentanaUsuarios::borrarUsuario()
{
    QTreeWidgetItem *currentItem = treeWidgetUsuarios->currentItem();
    if (!currentItem) return;

    QString usuario = currentItem->text(0);

    QSqlDatabase db = AdminDB::getInstance().getDatabase();
    QSqlQuery query(db);
    query.prepare("DELETE FROM usuarios WHERE usuario = :usuario");
    query.bindValue(":usuario", usuario);

    if (query.exec())
    {
        delete currentItem; // Eliminar el elemento del árbol
    }
    else
    {
        QMessageBox::critical(this, "Error", "Error al borrar el usuario: " + query.lastError().text());
    }
}

void VentanaUsuarios::guardarCambios()
{
    QTreeWidgetItem *itemUpdate = treeWidgetUsuarios->currentItem();
    if (!itemUpdate) return;

    QString usuarioOriginal = itemUpdate->data(0, Qt::UserRole).toString();
    QString nuevoUsuario = itemUpdate->text(0);
    QString nuevaClave = itemUpdate->text(1);

    QSqlDatabase db = AdminDB::getInstance().getDatabase();
    QSqlQuery query(db);

    // Si el nombre de usuario ha cambiado, necesitamos actualizar tanto el nombre de usuario como la clave
    if (usuarioOriginal != nuevoUsuario) {
        query.prepare("UPDATE usuarios SET usuario = :nuevoUsuario, clave = :nuevaClave WHERE usuario = :usuarioOriginal");
        query.bindValue(":usuarioOriginal", usuarioOriginal);
        query.bindValue(":nuevoUsuario", nuevoUsuario);
    } else {
        // Si el nombre de usuario no ha cambiado, solo actualizamos la clave
        query.prepare("UPDATE usuarios SET clave = :nuevaClave WHERE usuario = :usuarioOriginal");
        query.bindValue(":nuevoUsuario", nuevoUsuario); // Necesario para setear el nuevo valor
    }
    query.bindValue(":nuevaClave", nuevaClave);

    if (!query.exec())
    {
        QMessageBox::critical(this, "Error", "Error al actualizar el usuario: " + query.lastError().text());
    }
    else
    {
        // Actualizar el valor original almacenado
        itemUpdate->setData(0, Qt::UserRole, nuevoUsuario);
    }
}

void VentanaUsuarios::volverAlLogin()
{
    emit volverALogin();
    close();
}
