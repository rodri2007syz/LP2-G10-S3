#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <typeinfo>
#include <string>
using namespace std;

// Ejercicio 1: Templates de funcion
template <typename T>
void imprimirArreglo(const T arreglo[], size_t tamano) {
    cout << "[";
    for (size_t i = 0; i < tamano; ++i) {
        cout << arreglo[i];
        if (i < tamano - 1) cout << ", ";
    }
    cout << "]";
}

template <typename T>
void ordenarEImprimirFuncion(T arreglo[], size_t tamano) {
    cout << "Template funcion - Tipo: " << typeid(T).name() << endl;
    cout << "Original: ";
    imprimirArreglo(arreglo, tamano);
    cout << endl;
    
    sort(arreglo, arreglo + tamano);
    
    cout << "Ordenado: ";
    imprimirArreglo(arreglo, tamano);
    cout << endl << "--------------------------------" << endl;
}

void probarTemplatesFuncion() {
    cout << "\n=== TESTING TEMPLATES DE FUNCION ===" << endl;
    
    int enteros[] = {5, 2, 9, 1, 5, 6};
    ordenarEImprimirFuncion(enteros, sizeof(enteros)/sizeof(enteros[0]));
    
    double doubles[] = {3.14, 1.41, 2.71, 1.61, 0.99};
    ordenarEImprimirFuncion(doubles, sizeof(doubles)/sizeof(doubles[0]));
    
    char caracteres[] = {'z', 'a', 'm', 'b', 'k'};
    ordenarEImprimirFuncion(caracteres, sizeof(caracteres)/sizeof(caracteres[0]));
}

// Ejercicio 2: Templates de metodo
template <typename T>
class OrdenadorSimple {
protected:
    T* arreglo;
    size_t tamano;

public:
    OrdenadorSimple(T arr[], size_t tam) : arreglo(arr), tamano(tam) {}

    void procesarOrdenamiento() {
        mostrarTipo();
        mostrarOriginal();
        ordenar();
        mostrarOrdenado();
    }

protected:
    virtual void mostrarTipo() {
        cout << "Template metodo - Ordenando tipo: " << typeid(T).name() << endl;
    }

    virtual void mostrarOriginal() {
        cout << "Original: ";
        imprimirArreglo(arreglo, tamano);
        cout << endl;
    }

    void ordenar() {
        sort(arreglo, arreglo + tamano);
    }

    virtual void mostrarOrdenado() {
        cout << "Ordenado: ";
        imprimirArreglo(arreglo, tamano);
        cout << endl << "--------------------------------" << endl;
    }
};

void probarTemplatesMetodo() {
    cout << "\n=== PRUEBA TEMPLATES DE METODO ===" << endl;

    int enteros[] = {7, 3, 9, 2, 6};
    OrdenadorSimple<int> ordEnteros(enteros, sizeof(enteros)/sizeof(enteros[0]));
    ordEnteros.procesarOrdenamiento();

    double doubles[] = {2.72, 3.14, 1.61, 0.99};
    OrdenadorSimple<double> ordDoubles(doubles, sizeof(doubles)/sizeof(doubles[0]));
    ordDoubles.procesarOrdenamiento();

    string palabras[] = {"pera", "manzana", "uva", "banana"};
    OrdenadorSimple<string> ordStrings(palabras, sizeof(palabras)/sizeof(palabras[0]));
    ordStrings.procesarOrdenamiento();
}

// Ejercicio 3: Clase recipiente
template <typename T>
class ArregloRecipiente {
    T* elementos;
    size_t capacidad;
    size_t contador;

public:
    ArregloRecipiente(size_t cap = 10) : capacidad(cap), contador(0) {
        elementos = new T[capacidad];
    }

    ~ArregloRecipiente() {
        delete[] elementos;
    }

    void agregar(const T& elemento) {
        if (contador == capacidad) redimensionar();
        elementos[contador++] = elemento;
    }

    void ordenar() {
        sort(elementos, elementos + contador);
    }

    void imprimir() const {
        cout << "Clase recipiente - Tipo: " << typeid(T).name() << endl;
        cout << "Contenido (" << contador << " elementos): ";
        imprimirArreglo(elementos, contador);
        cout << endl;
    }

    void ordenarEImprimir() {
        cout << "\n--- Procesando arreglo recipiente ---" << endl;
        imprimir();
        ordenar();
        cout << "Despues de ordenar: ";
        imprimirArreglo(elementos, contador);
        cout << endl << "--------------------------------" << endl;
    }

private:
    void redimensionar() {
        capacidad *= 2;
        T* nuevo = new T[capacidad];
        copy(elementos, elementos + contador, nuevo);
        delete[] elementos;
        elementos = nuevo;
    }
};

void probarClaseRecipiente() {
    cout << "\n===PRUEBA CLASE RECIPIENTE ===" << endl;

    // Arreglo de enteros
    ArregloRecipiente<int> arrInt;
    arrInt.agregar(10);
    arrInt.agregar(5);
    arrInt.agregar(8);
    arrInt.agregar(3);
    arrInt.ordenarEImprimir();

    // Arreglo de strings
    ArregloRecipiente<string> arrStr;
    arrStr.agregar("gato");
    arrStr.agregar("perro");
    arrStr.agregar("elefante");
    arrStr.agregar("ardilla");
    arrStr.ordenarEImprimir();
    // Arreglo de doubles
    ArregloRecipiente<double> arrDouble;
    arrDouble.agregar(3.1416);
    arrDouble.agregar(2.7182);
    arrDouble.agregar(1.6180);
    arrDouble.agregar(1.4142);
    arrDouble.ordenarEImprimir();
}


int main() {
    cout << "====== PRUEBA DE LOS 3 EJERCICIOS ======" << endl;

    probarTemplatesFuncion();
    probarTemplatesMetodo();
    probarClaseRecipiente();
    cout << "\nTodas las pruebas completadas exitosamente!" << endl;
    return 0;
}
