#include "login.h"

#include <QJsonDocument>
#include <QJsonObject>
#include <QPainter>

Login::Login(QWidget *parent) : QWidget(parent)
{
    setMaximumSize(750,500);
    setMinimumSize(250,250);
    //setMaximumWidth(100);
    //setMinimumWidth(50);
    //setMaximumHeight(100);
    //setMinimumHeight(50);
    setWindowTitle("Ejercicio 14"); // Establecer título de la ventana

    lUsuario = new QLabel("Usuario:");
    lClave = new QLabel("Clave:");
    lClima = new QLabel("");
    leUsuario = new QLineEdit;
    leClave = new QLineEdit;
    leClave->setEchoMode(QLineEdit::Password);//clave con asteriscos *
    pbValidar = new QPushButton("Validar");
    pbAlternarTemperatura = new QPushButton("mostar u ocultar Temperatura"); // Botón para alternar la temperatura

    layout = new QGridLayout(this);
    layout->addWidget(lUsuario, 0, 0);
    layout->addWidget(leUsuario, 0, 1);
    layout->addWidget(lClave, 1, 0);
    layout->addWidget(leClave, 1, 1);
    layout->addWidget(pbValidar, 2, 1, 1, 2);
    layout->addWidget(pbAlternarTemperatura, 3, 0, 1, 2); // Agregar el botón de alternar temperatura

    connect(pbValidar, SIGNAL(pressed()), this, SLOT(slot_ValidarUsuario()));
    connect(leClave, SIGNAL(returnPressed()), this, SLOT(slot_ValidarUsuario()));
    connect(pbAlternarTemperatura, SIGNAL(pressed()), this, SLOT(slot_alternarTemperatura())); // Conectar el botón de alternar temperatura

    manager = new QNetworkAccessManager( this );
    managerClima = new QNetworkAccessManager( this );

    connect( manager, SIGNAL(finished(QNetworkReply*)),
             this, SLOT(slot_descargafinalizada(QNetworkReply*)));

    connect( managerClima, SIGNAL(finished(QNetworkReply*)),
             this, SLOT(slot_descargafinalizadaClima(QNetworkReply*)));

    connect( managerClima, SIGNAL(finished(QNetworkReply*)),
             this, SLOT(slot_descargafinalizada(QNetworkReply*)));//para imagen

    QNetworkRequest requestClima( QUrl("https://api.weatherapi.com/v1/current.json?key=6ebf146961d24c06b6a02801241104&q=Cordoba&aqi=no"));

    managerClima->get( requestClima );

   QNetworkRequest request( QUrl( "https://blogger.googleusercontent.com/img/b/R29vZ2xl/AVvXsEjqKFbXPLmoTaXmgvFDJxcT2L3KWCdLrwI4FIi8rLxVAYBkmofOvzIpPXEAkU9Oba4OD2VF1zWVGQPMPnBcwojztewxcevaalMMEFWrFPq7UrEVsL-PmzGHbNgbUPipCmk2LUraHmBjNBg/s1600/Captura+de+pantalla+de+2016-07-19+23-58-04.png") );
    manager->get( request );
}

void Login::paintEvent(QPaintEvent *)
{

    QPainter painter(this);
    painter.drawImage(0, 0,im.scaled( this->width(), this->height())); // Dibujar la imagen de fondo
}

void Login::slot_ValidarUsuario()
{
    QString usuario = leUsuario->text();
    QString clave = leClave->text();

    if (usuario == "admin" && clave == "1111")
    {
        qDebug() << "Usuario Valido";
        qDebug("Usuario valido");
        hide(); // Cerrar la ventana de login
        mostrarTemperatura(true); // Mostrar la temperatura
    }
    else
    {
        qDebug() << "Usuario no valido";
        leClave->clear(); // Borrar el texto del QLineEdit de la clave
    }
}

void Login::slot_descargafinalizadaClima(QNetworkReply *reply)
{
    QByteArray jsonDevuelto = reply->readAll();
    qDebug() << jsonDevuelto;

    // Parse the JSON string
    QJsonDocument doc = QJsonDocument::fromJson(jsonDevuelto);

    // Check if parsing was successful
    if (doc.isObject()) {
        // Get the "current" object
        QJsonObject currentObject = doc.object()["current"].toObject();

        // Check if the "current" object exists
        if (currentObject.contains("temp_c")) {
            // Extract the temperature in Celsius
            double temperatureC = currentObject["temp_c"].toDouble();
            qDebug() << "Temperature (Celsius):" << temperatureC;

            // Mostrar la temperatura al lado izquierdo del botón de validar
            lClima->setText(QString("%1°C").arg(temperatureC));
            lClima->setVisible(true); // Asegúrate de que la etiqueta sea visible

            // Ajustar el layout para colocar la etiqueta a la izquierda del botón
            layout->addWidget(lClima, 2, 0, 1, 1);
            layout->addWidget(pbValidar, 2, 1, 1, 2);
        } else {
            qDebug() << "Error: 'temp_c' key not found in 'current' object";
        }
    } else {
        qDebug() << "Error: Invalid JSON format";
    }
}

void Login::mostrarTemperatura(bool mostrar)
{
    lClima->setVisible(mostrar);
}

void Login::slot_alternarTemperatura()
{
    mostrarTemperatura(!lClima->isVisible()); // Alternar la visibilidad de la temperatura
}

void Login::slot_descargafinalizada(QNetworkReply *reply)
{
    im=QImage::fromData(reply->readAll());
    this->repaint();
}
