#include <QCoreApplication>
#include <iostream>
#include <QString>

namespace ignacio {

QString getVersion() {
    return "v0.0.1 - 20240610";
}

} // namespace ignacio

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString versionInfo = ignacio::getVersion();
    std::cout << "Library Version: " << versionInfo.toStdString() << std::endl;

    return 0;
}
