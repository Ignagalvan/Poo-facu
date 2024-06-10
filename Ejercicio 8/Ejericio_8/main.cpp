#include <iostream>
#include <QString>


class Comida {
private:
    QString nombre;
    QString tipo;

public:
    Comida(QString nombre, QString tipo) : nombre(nombre), tipo(tipo) {}

    QString getNombre() const {
        return nombre;
    }

    QString getTipo() const {
        return tipo;
    }
};

class Poste {
private:
    int altura;
    int diametro;

public:
    Poste(int altura, int diametro) : altura(altura), diametro(diametro) {}

    int getAltura() const {
        return altura;
    }

    int getDiametro() const {
        return diametro;
    }
};


template <class T>
void imprimirDescripcion(const T& objeto) {
    std::cout << "Descripcion del objeto: ";
    std::cout << objeto << std::endl;
}


std::ostream& operator<<(std::ostream& os, const Comida& comida) {
    os << "Comida: " << comida.getNombre().toStdString() << ", Tipo: " << comida.getTipo().toStdString();
    return os;
}

// Sobrecarga del operador << para imprimir objetos Poste
std::ostream& operator<<(std::ostream& os, const Poste& poste) {
    os << "Poste con altura de " << poste.getAltura() << " metros y " << poste.getDiametro() << " cm de diametro";
    return os;
}

int main() {

    Comida comida1("Pizza", "Italiana");
    Comida comida2("Sushi", "Japones");

    Poste poste1(8, 15);
    Poste poste2(10, 20);


    imprimirDescripcion(comida1);
    imprimirDescripcion(comida2);
    imprimirDescripcion(poste1);
    imprimirDescripcion(poste2);

    return 0;
}
