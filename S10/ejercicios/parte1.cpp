#include <iostream>
#include <algorithm>

using namespace std;

// Plantilla de función para imprimir un arreglo
template <typename T>
void imprimirArreglo(const T arreglo[], size_t tamaño) {
    cout << "Arreglo ordenado: [";
    for (size_t i = 0; i < tamaño; ++i) {
        cout << arreglo[i];
        if (i < tamaño - 1) cout << ", ";
    }
    cout << "]" << endl;
}

// Plantilla de función para ordenar e imprimir un arreglo
template <typename T>
void ordenarEImprimir(T arreglo[], size_t tamaño) {
    sort(arreglo, arreglo + tamaño);
    imprimirArreglo(arreglo, tamaño);
}

// Función para probar la plantilla de función
void probarPlantillaFuncion() {
    // Arreglo de enteros
    int enteros[] = {5, 2, 9, 1, 5, 6};
    const size_t tamEnteros = sizeof(enteros) / sizeof(enteros[0]);
    cout << "Ordenando enteros..." << endl;
    ordenarEImprimir(enteros, tamEnteros);

    // Arreglo de doubles
    double doubles[] = {3.14, 1.41, 2.71, 1.61, 0.99};
    const size_t tamDoubles = sizeof(doubles) / sizeof(doubles[0]);
    cout << "\nOrdenando doubles..." << endl;
    ordenarEImprimir(doubles, tamDoubles);

    // Arreglo de caracteres
    char caracteres[] = {'z', 'a', 'm', 'b', 'k'};
    const size_t tamCaracteres = sizeof(caracteres) / sizeof(caracteres[0]);
    cout << "\nOrdenando caracteres..." << endl;
    ordenarEImprimir(caracteres, tamCaracteres);
}

int main() {
    probarPlantillaFuncion();
    return 0;
}