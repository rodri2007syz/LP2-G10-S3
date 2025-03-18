#include <iostream>
#include <string>
using namespace std;

//
struct Producto {
    string NombreP;
    int Cantidad;
    int Precio;
};


void ListarProductos(Producto productos[], int tamano) {
    cout << "Lista de productos registrados:" << endl;
    for (int i = 0; i < tamano; i++) {
        cout << "Producto " << i + 1 << ":" << endl;
        cout << "  Nombre: " << productos[i].NombreP << endl;
        cout << "  Cantidad: " << productos[i].Cantidad << endl;
        cout << "  Precio: " << productos[i].Precio << endl;
        cout << "-------------------------" << endl;
    }
}

int main() {
    // Variables
    int c;
    int opcion = 0;

    cout << "Sistema de registro de productos" << endl;
    cout << "Ingrese la cantidad de productos a registrar: ";
    cin >> c;
    Producto *productos = new Producto[c];


    for (int i = 0; i < c; i++) {
        cout << "ingrese el nombre del producto (" << i + 1 << "): ";
        cin >> productos[i].NombreP;
        cout << "ingrese la cantidad del producto: ";
        cin >> productos[i].Cantidad;
        cout << "ingrese el precio del producto: ";
        cin >> productos[i].Precio;
    }

    cout << "se ingresaron correctamente " << c << " productos." << endl;

    // Menú de opciones
    while (true) {
        cout << "salir 1 | listar productos 2" << endl;
        cout << "ingrese una ocion: ";
        cin >> opcion;

        if (opcion == 1) {
            cout << "se ha salido del sistema." << endl;
            break;
        } else if (opcion == 2) {
            ListarProductos(productos, c);
        } else {
            cout << "opcion no válida." << endl;
        }
    }

    return 0;
}