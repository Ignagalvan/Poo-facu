#include "login.h"
#include <QDebug>
#include <QPainter>
#include <QResizeEvent>
#include <QMouseEvent>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QApplication>

Login::Login(QWidget *parent) : QWidget(parent) {
    setWindowTitle("Login");
    setFixedSize(600, 400); // Establecer tamaño fijo inicial

    // Crear los elementos de la interfaz
    lUsuario = new QLabel("Usuario:");
    lClave = new QLabel("Clave:");
    leUsuario = new QLineEdit();
    leClave = new QLineEdit();
    leClave->setEchoMode(QLineEdit::Password);
    pbIngresar = new QPushButton("Ingresar");

    // Crear el layout y añadir los elementos
    QGridLayout *gridLayout = new QGridLayout(this);
    gridLayout->addWidget(lUsuario, 0, 0);
    gridLayout->addWidget(leUsuario, 0, 1, 1, 2);
    gridLayout->addWidget(lClave, 1, 0);
    gridLayout->addWidget(leClave, 1, 1, 1, 2);
    gridLayout->addWidget(pbIngresar, 2, 1, 1, 1);

    // Conectar el clic del botón al slot_validarUsuario
    connect(pbIngresar, SIGNAL(pressed()), this, SLOT(slot_validarUsuario()));

    manager = new QNetworkAccessManager(this);

    connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(slot_descargaFinalizada(QNetworkReply*)));

    QNetworkRequest request(QUrl("https://previews.123rf.com/images/forplayday/forplayday1601/forplayday160100020/50430098-im%C3%A1genes-de-alta-resoluci%C3%B3n-presenta-planetas-del-sistema-solar.jpg"));
    manager->get(request);

    // Permitir redimensionamiento desde las esquinas
    setMouseTracking(true);
}

void Login::paintEvent(QPaintEvent *)  {
    QPainter painter(this);
    if (!im.isNull()) {
        // Escalar la imagen para que se ajuste al tamaño del widget manteniendo su relación de aspecto
        painter.drawImage(0, 0, im.scaled(size(), Qt::KeepAspectRatio));
    }
}

void Login::slot_validarUsuario() {
    if (leUsuario->text() == "admin" && leClave->text() == "1234") {
        // Enviar señal de autenticación exitosa
        emit autenticacionExitosa();
    } else {
        leClave->clear();
    }
}

void Login::slot_descargaFinalizada(QNetworkReply *reply)  {
    im = QImage::fromData(reply->readAll());
    // Forzar el repintado del widget para mostrar la imagen descargada
    repaint();
}

void Login::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        // Guardar la posición del ratón al hacer clic
        mousePressPos = event->globalPos();
        widgetPos = this->frameGeometry().topLeft();
        resize = true;
    }
}

void Login::mouseMoveEvent(QMouseEvent *event) {
    if (event->buttons() & Qt::LeftButton && resize) {
        // Calcular la diferencia entre la posición actual del ratón y la posición del clic inicial
        QPoint delta = event->globalPos() - mousePressPos;
        // Si la diferencia es significativa, permitir el redimensionamiento
        if (delta.manhattanLength() > QApplication::startDragDistance()) {
            QPoint new_pos = widgetPos + delta;
            this->resize(this->width() + delta.x(), this->height() + delta.y());
            this->move(new_pos);
        }
    }
}

void Login::mouseReleaseEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        resize = false;
    }
}
