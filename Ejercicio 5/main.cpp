#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {

    std::vector<std::string> expresionesIdiomaticas;

    // Cargar 5 expresiones idiomáticas en el vector
    expresionesIdiomaticas.push_back("pan comido");
    expresionesIdiomaticas.push_back("encontrar a tu media naranja");
    expresionesIdiomaticas.push_back("dar en el clavo");
    expresionesIdiomaticas.push_back("darle la vuelta a la tortilla");
    expresionesIdiomaticas.push_back("un clavo saca otro clavo");


    std::sort(expresionesIdiomaticas.begin(), expresionesIdiomaticas.end());


    std::cout << "Expresiones ideomaticas ordenadas alfabeticamente:" << std::endl;
    for (const std::string& expresion : expresionesIdiomaticas) {
        std::cout << expresion << std::endl;
    }

    return 0;
}
