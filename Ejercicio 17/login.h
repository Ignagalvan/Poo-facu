#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QNetworkAccessManager>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

class Login : public QWidget
{
    Q_OBJECT

public:
    Login(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

private slots:
    void slot_validarUsuario();
    void slot_descargaFinalizada(QNetworkReply *reply);

private:
    QImage im;
    QLabel *lUsuario;
    QLabel *lClave;
    QLineEdit *leUsuario;
    QLineEdit *leClave;
    QPushButton *pbIngresar;
    QNetworkAccessManager *manager;
    QPoint mousePressPos;
    QPoint widgetPos;
    bool resize;
};

#endif // LOGIN_H
