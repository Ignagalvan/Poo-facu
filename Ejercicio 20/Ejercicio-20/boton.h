#ifndef BOTON_H
#define BOTON_H

#include <QWidget>
#include <QLabel>

class Boton : public QWidget
{
    Q_OBJECT
public:
    explicit Boton(QWidget *parent = nullptr);

    enum Color {
            Rojo,
            Magenta,
            Violeta,
            Azul,
            Verde

        };

     void colorear(Color color);

     void setText(const QString &text); // Declaración del método setText
     void setTransparent(bool transparent); // Declaración de setTransparent


protected:

    void mousePressEvent(QMouseEvent *)override;
    void paintEvent(QPaintEvent *event) override;
    void resizeEvent(QResizeEvent *event) override; // Declaración de resizeEvent


signals:
    void signal_click();// senal del click en el boton

private:
    QColor m_color;
    QLabel * m_label;


};

#endif // BOTON_H
