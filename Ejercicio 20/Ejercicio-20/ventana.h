#ifndef VENTANA_H
#define VENTANA_H


#include<QUrl>
#include <QWidget>
#include <QNetworkReply>

QT_BEGIN_NAMESPACE
namespace Ui { class Ventana; }
QT_END_NAMESPACE

class Ventana : public QWidget
{
    Q_OBJECT

public:
    Ventana(QWidget *parent = nullptr);
    ~Ventana();

private:
    Ui::Ventana *ui;

     QImage backgroundImage;

private slots:
     void imageDownloaded(QNetworkReply *reply);

protected:
     void paintEvent(QPaintEvent *event) override;

};
#endif // VENTANA_H
