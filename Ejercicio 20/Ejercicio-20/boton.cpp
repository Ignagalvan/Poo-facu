#include "boton.h"
#include <QPainter>
#include <QVBoxLayout>

Boton::Boton(QWidget *parent) : QWidget(parent)
{
    QVBoxLayout *layout = new QVBoxLayout(this);
    m_label = new QLabel;
    layout->addWidget(m_label);

   // layout->setAlignment(m_label, Qt::AlignCenter);// lo pone en el centro
   // m_label->setAlignment(Qt::AlignCenter);// Asegura que el texto dentro del QLabel esté centrado

    layout->setAlignment(m_label, Qt::AlignLeft); // Alinea el QLabel a la izquierda
    m_label->setAlignment(Qt::AlignCenter); // Asegura que el texto dentro del QLabel esté centrado
   // m_label->setAlignment(Qt::AlignLeft); // Alinea el texto dentro del QLabel a la izquierda
   // m_label->setAlignment(Qt::AlignRight); // Alinea el texto dentro del QLabel a la derecha
}

void Boton::mousePressEvent(QMouseEvent *)
{
    emit signal_click();
}

void Boton::paintEvent(QPaintEvent *)
{
    QPainter painter( this );
  //  painter.fillRect(0,0,this->width(), this->height(),m_color);

    // Establecer un color con transparencia (canal alfa)
        QColor colorTransparente(m_color.red(), m_color.green(), m_color.blue(), 220); // 128 es un valor de opacidad, puedes ajustarlo según necesites
        painter.fillRect(0, 0, this->width(), this->height(), colorTransparente);
}

void Boton::colorear(Boton::Color color)
{
    switch(color) {
    case Azul:
        m_color = QColor(0, 0, 255);
        break;
    case Verde:
        m_color = QColor(0, 255, 0);
        break;
    case Magenta:
        m_color = QColor(255, 0, 255);
        break;
    case Rojo:
        m_color = QColor(255, 0, 0);
        break;
    case Violeta:
        m_color = QColor(148, 0, 211);
        break;

    }

    //update(); // Redibujar el botón con el nuevo color
}

void Boton::setText(const QString &text)
{
    m_label->setText(text);  // Usa el texto proporcionado
    m_label->setStyleSheet("QLabel { font-size: 12px; }"); // Tamaño de fuente inicial
}

void Boton::resizeEvent(QResizeEvent *event)
{
    // Ajustar el tamaño de la fuente basado en la altura del botón
    int fontSize = this->height() * 0.2; // Puedes ajustar el factor de escala según tus necesidades
    m_label->setStyleSheet(QString("QLabel { font-size: %1px; }").arg(fontSize));
    QWidget::resizeEvent(event);
}
