#include <QApplication>
#include <QLabel>
#include <QWidget>
#include <QPushButton>
#include <QLineEdit>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // Crear objetos de las clases QLabel, QWidget, QPushButton y QLineEdit
    QLabel label("QLabel");
    QWidget widget;
    QPushButton button("QPushButton");
    QLineEdit lineEdit("QLineEdit");

    // Mostrar cada objeto utilizando el método show()
    label.show();
    widget.show();
    button.show();
    lineEdit.show();

    return app.exec();
}
