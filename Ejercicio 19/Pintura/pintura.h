#ifndef PINTURA_H
#define PINTURA_H

#include <QWidget>
#include <QPainter>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QWheelEvent>
#include <QPainterPath>

class PaintWidget : public QWidget {
    Q_OBJECT

public:
    PaintWidget(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void wheelEvent(QWheelEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;

private:
    QPainterPath path;
    QColor penColor;
    int penSize;
    QPoint lastPoint;
};

#endif // PINTURA_H
