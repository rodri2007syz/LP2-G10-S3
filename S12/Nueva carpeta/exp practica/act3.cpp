#include <iostream>
#include <string>
#include <deque>
#include <algorithm>
#include <cctype>
#include <limits>


bool esVocal(char c) {
    c = std::tolower(c);
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

void clearInputBuffer() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main() {
    std::cout << "--- MANIPULACION DE ITERADORES (std::deque) ---" << std::endl;
    std::string cadena_str;
    std::cout << "Ingrese una cadena de caracteres: ";
    std::getline(std::cin, cadena_str);

    if (cadena_str.empty()) {
        std::cout << "Cadena vacia. Saliendo." << std::endl;
        return 0;
    }

    // Almacenar la cadena en un contenedor deque
    std::deque<char> caracteres(cadena_str.begin(), cadena_str.end());

    std::cout << "\nCadena original en deque: ";
    for (char c : caracteres) {
        std::cout << c;
    }
    std::cout << std::endl;

    // a) Utilizar un iterador para recorrer el contenedor y mostrar los caracteres uno por uno
    std::cout << "Recorriendo con iterador (caracter por caracter): ";
    for (std::deque<char>::iterator it = caracteres.begin(); it != caracteres.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // b) Reemplazar todas las vocales en el contenedor con el carácter '*' utilizando un iterador
    std::cout << "Reemplazando vocales con '*':" << std::endl;
    for (std::deque<char>::iterator it = caracteres.begin(); it != caracteres.end(); ++it) {
        if (esVocal(*it)) {
            it = '';
        }
    }

    std::cout << "Cadena despues de reemplazar vocales: ";
    for (char c : caracteres) {
        std::cout << c;
    }
    std::cout << std::endl;

    std::cout << "Cadena en orden inverso (con iterador inverso): ";
    for (std::deque<char>::reverse_iterator rit = caracteres.rbegin(); rit != caracteres.rend(); ++rit) {
        std::cout << *rit;
    }
    std::cout << std::endl;

}