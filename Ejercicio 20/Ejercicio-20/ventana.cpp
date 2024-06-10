#include "ventana.h"
#include "ui_ventana.h"
#include <QPainter>
#include <QPaintEvent>
#include <QNetworkReply>
#include <QNetworkAccessManager>


Ventana::Ventana(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Ventana)
{
    ui->setupUi(this);

    ui->boton1->colorear(Boton::Rojo);
    ui->boton2->colorear(Boton::Magenta);
    ui->boton3->colorear(Boton::Violeta);
    ui->boton4->colorear(Boton::Azul);
    ui->boton5->colorear(Boton::Verde);



    connect(ui->boton1, SIGNAL(signal_click()), this, SLOT(close()));
    connect(ui->boton2, SIGNAL(signal_click()), this, SLOT(close()));
    connect(ui->boton3, SIGNAL(signal_click()), this, SLOT(close()));
    connect(ui->boton4, SIGNAL(signal_click()), this, SLOT(close()));
    connect(ui->boton5, SIGNAL(signal_click()), this, SLOT(close()));


     ui->boton1->setText("Mi dentista");
     ui->boton2->setText("Vistas");
     ui->boton3->setText("Tecnicas de higiene");
     ui->boton4->setText("Mi boca");
     ui->boton5->setText("Hora de cepillarse");



    // Cargar la imagen de fondo desde la URL
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(imageDownloaded(QNetworkReply*)));
    manager->get(QNetworkRequest(QUrl("https://img.freepik.com/foto-gratis/burbuja-aceite-fondo-pantalla-iphone-degradado-fondo-agua_53876-176849.jpg")));

}

Ventana::~Ventana()
{
    delete ui;
}

void Ventana::imageDownloaded(QNetworkReply *reply)
{
    if (reply->error() == QNetworkReply::NoError)
    {
        QByteArray imageData = reply->readAll();
        backgroundImage.loadFromData(imageData);

        // Redibujar el widget para mostrar la imagen de fondo
        update();
    }
    else
    {
        qDebug() << "Error al descargar la imagen:" << reply->errorString();
    }
    reply->deleteLater();
}

void Ventana::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    // Dibujar la imagen de fondo escalada al tamaño del widget
    if (!backgroundImage.isNull())
        painter.drawImage(0, 0, backgroundImage.scaled(this->size()));
}
