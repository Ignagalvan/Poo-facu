#include "pintura.h"

PaintWidget::PaintWidget(QWidget *parent) : QWidget(parent), penColor(Qt::black), penSize(2) {
    setWindowTitle("Paint Widget");
    setFixedSize(800, 600);
    setFocusPolicy(Qt::StrongFocus);
    path = QPainterPath();
}

void PaintWidget::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setPen(QPen(penColor, penSize, Qt::SolidLine));
    painter.drawPath(path);
}

void PaintWidget::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        lastPoint = event->pos();
        path.moveTo(lastPoint);
        update();
    }
}

void PaintWidget::mouseMoveEvent(QMouseEvent *event) {
    if (event->buttons() & Qt::LeftButton) {
        path.lineTo(event->pos());
        update();
        lastPoint = event->pos();
    }
}

void PaintWidget::wheelEvent(QWheelEvent *event) {
    if (event->angleDelta().y() > 0) {
        penSize += 1;
    } else {
        penSize -= 1;
        if (penSize < 1) {
            penSize = 1;
        }
    }
    update();
}

void PaintWidget::keyPressEvent(QKeyEvent *event) {
    switch (event->key()) {
        case Qt::Key_R:
            penColor = Qt::red;
            break;
        case Qt::Key_G:
            penColor = Qt::green;
            break;
        case Qt::Key_B:
            penColor = Qt::blue;
            break;
        case Qt::Key_Escape:
            path = QPainterPath();
            update();
            break;
        default:
            QWidget::keyPressEvent(event);
    }
}
