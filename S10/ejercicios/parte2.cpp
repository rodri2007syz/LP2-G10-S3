#include <iostream>
#include <algorithm>
using namespace std;

template <typename T>
class OrdenadorSimple {
protected:
    T* arreglo;
    size_t tamaño;

public:
    OrdenadorSimple(T arr[], size_t tam) : arreglo(arr), tamaño(tam) {}

    void procesarOrdenamiento() {
        mostrarTipo();
        mostrarOriginal();
        ordenar();
        mostrarOrdenado();
    }

protected:
    // Metodos virtuales
    virtual void mostrarTipo() = 0;

    virtual void mostrarOriginal() {
        cout << "Datos originales: [";
        for (size_t i = 0; i < tamaño; ++i) {
            cout << arreglo[i];
            if (i < tamaño - 1) cout << ", ";
        }
        cout << "]" << endl;
    }

    void ordenar() {
        sort(arreglo, arreglo + tamaño);
    }

    virtual void mostrarOrdenado() {
        cout << "Arreglo ordenado: [";
        for (size_t i = 0; i < tamaño; ++i) {
            cout << arreglo[i];
            if (i < tamaño - 1) cout << ", ";
        }
        cout << "]" << endl;
    }
};

// Clase para ordenar enteros
class OrdenadorEnteros : public OrdenadorSimple<int> {
public:
    OrdenadorEnteros(int arr[], size_t tam) : OrdenadorSimple<int>(arr, tam) {}

protected:
    void mostrarTipo() override {
        cout << "Ordenando enteros..." << endl;
    }
};

// Clase para ordenar doubles
class OrdenadorDoubles : public OrdenadorSimple<double> {
public:
    OrdenadorDoubles(double arr[], size_t tam) : OrdenadorSimple<double>(arr, tam) {}

protected:
    void mostrarTipo() override {
        cout << "\nOrdenando doubles..." << endl;
    }
};

// Clase para ordenar caracteres
class OrdenadorCaracteres : public OrdenadorSimple<char> {
public:
    OrdenadorCaracteres(char arr[], size_t tam) : OrdenadorSimple<char>(arr, tam) {}

protected:
    void mostrarTipo() override {
        cout << "\nOrdenando caracteres..." << endl;
    }
};

// funcion para probar las plantillas de metodos
void probarPlantillaMetodos() {
    // Arreglo de enteros
    int enteros[] = {5, 2, 9, 1, 5, 6};
    const size_t tamEnteros = sizeof(enteros) / sizeof(enteros[0]);
    OrdenadorEnteros ordEnt(enteros, tamEnteros);
    ordEnt.procesarOrdenamiento();

    // Arreglo de doubles
    double doubles[] = {3.14, 1.41, 2.71, 1.61, 0.99};
    const size_t tamDoubles = sizeof(doubles) / sizeof(doubles[0]);
    OrdenadorDoubles ordDouble(doubles, tamDoubles);
    ordDouble.procesarOrdenamiento();

    // Arreglo de caracteres
    char caracteres[] = {'z', 'a', 'm', 'b', 'k'};
    const size_t tamCaracteres = sizeof(caracteres) / sizeof(caracteres[0]);
    OrdenadorCaracteres ordChar(caracteres, tamCaracteres);
    ordChar.procesarOrdenamiento();
}

int main() {
    probarPlantillaMetodos();
    return 0;
}