#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

class Producto {
private:
    string nombre;
    double precio;
    int cantidad;

public:

    Producto(string nom, double pre, int cant) : nombre(nom), precio(pre), cantidad(cant) {}

    string getNombre() const { return nombre; }
    double getPrecio() const { return precio; }
    int getCantidad() const { return cantidad; }

    void infoDelProducto() const {
        cout << "|Nombre " << nombre << "| Precio S/. " << precio << "| Cantidad " << cantidad << endl;
    }
};


int main() {
    vector<Producto> inventario;


    Producto obj1("pan", 12.32, 12);
    Producto obj2("queso", 13.30, 5);
    Producto obj3("soda", 11.10, 10);
    inventario.push_back(obj1);
    inventario.push_back(obj2);
    inventario.push_back(obj3);


    ofstream archivoEs("InformeDeProductos.txt");


    if (archivoEs.is_open()) {

        for (size_t i = 0; i < inventario.size(); ++i) {
            inventario[i].infoDelProducto();
            archivoEs << inventario[i].getNombre() << ","<< inventario[i].getPrecio() << "," << inventario[i].getCantidad() << endl;
        }
        archivoEs.close();

    } else {
        cout << "No se pudo abrir" << endl;
    }

    string linea;
    string texto = "";

    ifstream archivoLec("InformeDeProductos.txt");

    if (archivoLec.is_open()) {
        while (getline(archivoLec, linea)) {
            texto = texto + linea + "\n";
        }
        archivoLec.close();
        cout << "----------Inventario---------" << endl;
        cout << texto << endl;
    } else {
        cout << "No se pudo abrir para lectura." << endl;
    }

    return 0;
}