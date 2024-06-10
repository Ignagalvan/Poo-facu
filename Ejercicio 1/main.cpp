#include <QCoreApplication>
#include <iostream>
#include <cstdlib>
#include <ctime>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    std::srand(std::time(0));

    std::cout << "10 numeros aleatorios en el intervalo [2, 20]: " << std::endl;

    for (int i = 0; i < 10; ++i) {
        int num = std::rand() % 19 + 2;
        std::cout << num << " ";
    }

    std::cout << std::endl;

    return 0;
}
