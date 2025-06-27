#include <iostream>
#include <string>
#include <list>
#include <algorithm>
#include <cctype>    
#include <limits>   
void clearInputBuffer() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main() {
    std::cout << "--- USO DE ALGORITMOS (std::list) ---" << std::endl;
    std::list<std::string> palabras;
    std::string palabra;

    std::cout << "Ingrese una secuencia de palabras (ingrese 'fin' para terminar):" << std::endl;
    while (std::getline(std::cin, palabra) && palabra != "fin") {
        if (!palabra.empty()) {
            palabras.push_back(palabra);
        }
    }

    if (palabras.empty()) {
        std::cout << "No se ingresaron palabras. Saliendo." << std::endl;
        return 0;
    }

    std::cout << "\nPalabras ingresadas: ";
    for (const std::string& p : palabras) {
        std::cout << p << " ";
    }
    std::cout << std::endl;


    palabras.sort();
    std::cout << "Palabras ordenadas alfabeticamente: ";
    for (const std::string& p : palabras) {
        std::cout << p << " ";
    }
    std::cout << std::endl;


    std::cout << "\nIngrese una palabra para contar su ocurrencia: ";
    std::string palabra_a_contar;
    std::getline(std::cin, palabra_a_contar);
    int count = std::count(palabras.begin(), palabras.end(), palabra_a_contar);
    std::cout << "La palabra '" << palabra_a_contar << "' aparece " << count << " vez(veces)." << std::endl;


    std::transform(palabras.begin(), palabras.end(), palabras.begin(),
                   [](std::string s) {
                       std::transform(s.begin(), s.end(), s.begin(),
                                      [](unsigned char c) { return std::toupper(c); });
                       return s;
                   });


    std::cout << "\nLista de palabras despues de convertirlas a mayusculas: ";
    for (const std::string& p : palabras) {
        std::cout << p << " ";
    }
    std::cout << std::endl;

}