#include <iostream>
#include <string>
using namespace std;

class Factura {
private:
    string numeroFactura;
    string descripcionArticulo;
    int cantidad;
    double precioUnitario;

public:
    // Constructor
    Factura(string numFactura, string descripcion, int cant, double precio)
        : numeroFactura(numFactura), descripcionArticulo(descripcion), cantidad(cant), precioUnitario(precio) {}

    // Get
    string getNumeroFactura() const {
        return numeroFactura;
    }

    string getDescripcionArticulo() const {
        return descripcionArticulo;
    }

    int getCantidad() const {
        return cantidad;
    }

    double getPrecioUnitario() const {
        return precioUnitario;
    }

    // Set
    void setNumeroFactura(string numFactura) {
        numeroFactura = numFactura;
    }

    void setDescripcionArticulo(string descripcion) {
        descripcionArticulo = descripcion;
    }

    void setCantidad(int cant) {
        if (cant > 0) {
            cantidad = cant;
        } else {
            cantidad = 0;
        }
    }

    void setPrecioUnitario(double precio) {
        if (precio > 0) {
            precioUnitario = precio;
        } else {
            precioUnitario = 0;
        }
    }

    // metodo para calcular el total 
    double getMontoFactura() const {
        return cantidad * precioUnitario;
    }

    //factura
    void mostrarFactura() const {
        cout << "Factura #" << numeroFactura << endl;
        cout << "-----------------------" << endl;
        cout << "Descripcion: " << descripcionArticulo << endl;
        cout << "Cantidad: " << cantidad << endl;
        cout << "Precio unitario: " << precioUnitario << endl;
        cout << "Monto total: " << getMontoFactura() << endl;
        cout << "-----------------------" << endl;
    }
};

