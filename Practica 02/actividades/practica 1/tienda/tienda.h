#include <iostream>
#include <string>
using namespace std;

class Tienda {
private:
    string nombre;
    string direccion;
    string tipoDeTienda;
    int stock; // Variable para llevar un conteo basico de stock

public:
    // Constructor
    Tienda(string nom, string dir, string tipo)
        : nombre(nom), direccion(dir), tipoDeTienda(tipo), stock(0) {}

    // Metodo para vender un producto
    void venderProducto() {
        if (stock > 0) {
            stock--;
            cout << "Se ha vendido un producto en " << nombre << ". Stock restante: " << stock << endl;
        } else {
            cout << "No hay productos en stock en " << nombre << "." << endl;
        }
    }

    // Metodo para agregar un producto al stock
    void agregarProducto(int cantidad) {
        if (cantidad > 0) {
            stock += cantidad;
            cout << "Se han agregado " << cantidad << " productos al stock de " << nombre << ". Stock total: " << stock << endl;
        } else {
            cout << "Error: La cantidad debe ser mayor que 0." << endl;
        }
    }

    // Metodo para mostrar la informacion de la tienda
    void mostrarInformacion() const {
        cout << "Informacion de la tienda:" << endl;
        cout << "Nombre: " << nombre << endl;
        cout << "Direccion: " << direccion << endl;
        cout << "Tipo de tienda: " << tipoDeTienda << endl;
        cout << "Stock actual: " << stock << endl;
        cout << "-----------------------" << endl;
    }
};
