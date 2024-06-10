#include <iostream>

// Función genérica para ordenar e imprimir un array
template <class T>
void imprimir(T* v, int cantidad, bool mayor_a_menor) {
    // Ordenamiento por inserción
    for (int i = 1; i < cantidad; ++i) {
        T key = v[i];
        int j = i - 1;

        // Ordenar de mayor a menor
        if (mayor_a_menor) {
            while (j >= 0 && v[j] < key) {
                v[j + 1] = v[j];
                --j;
            }
        }
        // Ordenar de menor a mayor
        else {
            while (j >= 0 && v[j] > key) {
                v[j + 1] = v[j];
                --j;
            }
        }
        v[j + 1] = key;
    }

    // Imprimir el array ordenado
    for (int i = 0; i < cantidad; ++i) {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    // Definición de arrays de prueba
    int intArray[] = { 5, 2, 9, 1, 5, 6 };
    float floatArray[] = { 4.5, 2.2, 5.1, 3.3, 1.8 };

    // Obtener el tamaño de los arrays
    int intArraySize = sizeof(intArray) / sizeof(intArray[0]);
    int floatArraySize = sizeof(floatArray) / sizeof(floatArray[0]);

    // Probar la función genérica para ordenar e imprimir arrays
    std::cout << "Array de enteros ordenado de mayor a menor: ";
    imprimir(intArray, intArraySize, true);

    std::cout << "Array de flotantes ordenado de menor a mayor: ";
    imprimir(floatArray, floatArraySize, false);

    return 0;
}
