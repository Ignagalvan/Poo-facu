#include <iostream>
#include <vector>
#include <string>

class Jugador {
private:
    int velocidad;
    int fuerza;
    std::string nombre;

public:
    // Constructor
    Jugador(int vel = 0, int fue = 0, std::string nom = "sin nombre")
        : velocidad(vel), fuerza(fue), nombre(nom) {}

    // Destructor
    ~Jugador() {}

    // Setters
    void setVelocidad(int vel) { velocidad = vel; }
    void setFuerza(int fue) { fuerza = fue; }
    void setNombre(const std::string& nom) { nombre = nom; }

    // Getters
    int getVelocidad() const { return velocidad; }
    int getFuerza() const { return fuerza; }
    std::string getNombre() const { return nombre; }

    // Método para imprimir los datos del jugador
    void imprimirDatos() const {
        std::cout << "Nombre: " << nombre
                  << ", Velocidad: " << velocidad
                  << ", Fuerza: " << fuerza
                  << std::endl;
    }
};

int main() {
    // Crear un vector de Jugador
    std::vector<Jugador> jugadores;

    // Insertar 10 jugadores distintos utilizando un bucle
    for (int i = 1; i <= 10; ++i) {
        Jugador jugador(i * 10, i * 10 + 40, "Jugador" + std::to_string(i));
        jugadores.push_back(jugador);
    }

    // Publicar los datos de cada jugador usando el método imprimirDatos
    for (const auto& jugador : jugadores) {
        jugador.imprimirDatos();
    }

    return 0;
}
