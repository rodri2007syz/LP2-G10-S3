#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <limits>

void clearInputBuffer() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main() {
    std::cout << "--- MANIPULACION DE CONTENEDORES (std::vector) ---" << std::endl;
    std::vector<int> numeros;
    int numero;

    std::cout << "Ingrese numeros enteros (ingrese 0 para finalizar):" << std::endl;
    while (std::cin >> numero && numero != 0) {
        numeros.push_back(numero);
    }
    clearInputBuffer();

    if (numeros.empty()) {
        std::cout << "No se ingresaron numeros. Saliendo." << std::endl;
        return 0;
    }

    std::cout << "\nNumeros ingresados: ";
    for (int n : numeros) {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    long long suma = std::accumulate(numeros.begin(), numeros.end(), 0LL);
    std::cout << "Suma de los numeros: " << suma << std::endl;


    auto min_it = std::min_element(numeros.begin(), numeros.end());
    auto max_it = std::max_element(numeros.begin(), numeros.end());
    std::cout << "Numero minimo: " << *min_it << std::endl;
    std::cout << "Numero maximo: " << *max_it << std::endl;

    // c) Ordenar los números de forma ascendente
    std::vector<int> numeros_ordenados = numeros; // Crear una copia para ordenar
    std::sort(numeros_ordenados.begin(), numeros_ordenados.end());
    std::cout << "Numeros ordenados (ascendente): ";
    for (int n : numeros_ordenados) {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    numeros.erase(std::remove_if(numeros.begin(), numeros.end(),
                                  [](int n) { return n % 2 == 0; }),
                  numeros.end());

    std::cout << "Numeros despues de eliminar los pares: ";
    if (numeros.empty()) {
        std::cout << "(Contenedor vacio)" << std::endl;
    } else {
        for (int n : numeros) {
            std::cout << n << " ";
        }
        std::cout << std::endl;
    }

}