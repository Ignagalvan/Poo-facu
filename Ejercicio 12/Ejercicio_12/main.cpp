#include <QApplication>
#include <QLabel>
#include <QTimer>
#include <QImage>
#include <QDesktopWidget> // Para obtener el tamaño de la pantalla

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // Cargar la imagen desde el disco duro usando QImage
    QImage image("C:/Users/ignad/Documents/POO/Ejercicios/Ejercicio 12/imagen/50430098-imágenes-de-alta-resolución-presenta-planetas-del-sistema-solar.jpg");

    // Comprobar si la carga de la imagen fue exitosa
    if (image.isNull()) {
        qWarning("No se pudo cargar la imagen.");
        return 1;
    }

    // Crear un QLabel con la imagen
    QLabel label;
    label.setPixmap(QPixmap::fromImage(image));

    // Configurar el QLabel para ajustarse al tamaño de la imagen y centrarlo en la pantalla
    label.setScaledContents(true);
    label.setAlignment(Qt::AlignCenter);

    // Obtener el tamaño de la pantalla
    QSize screenSize = qApp->desktop()->availableGeometry().size();
    // Establecer el tamaño del QLabel al tamaño de la pantalla
    label.resize(screenSize);

    // Mostrar el QLabel
    label.show();

    // Configurar un temporizador para cerrar la aplicación después de 3 segundos
    QTimer::singleShot(3000, &app, &QApplication::quit);

    return app.exec();
}
