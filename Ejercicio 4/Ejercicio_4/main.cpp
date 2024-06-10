#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm> // Esta es la biblioteca que utilizamos para ordenar el vector

int main() {
    // Semilla para la generación de números aleatorios
    std::srand(std::time(nullptr));

    // Crear un vector para almacenar los números
    std::vector<int> numbers;

    // Cargar 30 valores pseudoaleatorios entre 1 y 15
    for (int i = 0; i < 30; ++i) {
        numbers.push_back(1 + std::rand() % 15);
    }

    // Ordenar el vector para facilitar el cálculo de la moda
    std::sort(numbers.begin(), numbers.end()); // Aquí utilizamos la función sort para ordenar el vector

    // Encontrar la moda
    int moda = numbers[0];
    int modaFrecuencia = 1;
    int current = numbers[0];
    int currentFrequency = 1;

    for (size_t i = 1; i < numbers.size(); ++i) {
        if (numbers[i] == current) {
            ++currentFrequency;
        } else {
            if (currentFrequency > modaFrecuencia) {
                modaFrecuencia = currentFrequency;
                moda = current;
            }
            current = numbers[i];
            currentFrequency = 1;
        }
    }

    // Comprobar la última secuencia
    if (currentFrequency > modaFrecuencia) {
        modaFrecuencia = currentFrequency;
        moda = current;
    }

    // Imprimir la moda
    std::cout << "La moda de los 30 numeros es: " << moda << std::endl;

    return 0;
}
