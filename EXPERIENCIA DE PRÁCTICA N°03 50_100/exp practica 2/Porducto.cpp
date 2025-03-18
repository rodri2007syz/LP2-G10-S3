#include <iostream>
#include <string>
using namespace std;


const int MAXPR = 10;


class Producto {
private:
    string nombre;
    double precio;
    int cantidadEnInventario;

public:
    //constructor
    Producto(string n = "", double p = 0.0, int c = 0) {
        nombre = n;
        precio = p;
        cantidadEnInventario = c;
    }

    // Get
    string getNombre() {
        return nombre;
    }
    double getPrecio() {
        return precio;
    }
    int getCantidadEnInventario() {
        return cantidadEnInventario;
    }


    // Set
    void setNombre(string n) {
        nombre = n;
    }
    void setPrecio(double p) {
        precio = p;
    }
    void setCantidadEnInventario(int c) {
        cantidadEnInventario = c;
    }

    void mostrarProducto() {
        cout << "Nombre: " << nombre << endl;
        cout << "Precio: " << precio << endl;
        cout << "Cantidad en inventario: " << cantidadEnInventario << endl;
    }
};

// Clase Pedido
class Pedido {
private:
    Producto listaDeProductos[MAXPR];
    int canPr;
    string estadoDelPedido;

public:

    Pedido() {
        canPr = 0; 
        estadoDelPedido = "Pendiente";
    }


    void agregarProducto(Producto p) {
        if (canPr < MAXPR) {
            listaDeProductos[canPr] = p;
            canPr ++;
        } else {
            cout << "No se pueden agregar más productos. Límite alcanzado." << endl;
        }
    }


    void mostrarPedido() {
        cout << "Estado del pedido: " << estadoDelPedido << endl;
        cout << "Productos en el pedido:" << endl;
        for (int i = 0; i < canPr; i++) {
            listaDeProductos[i].mostrarProducto();
            cout << "-------------------" << endl;
        }
    }
};


class Cuentabancaria {
    private:
        int cuenta = 0;
    public:
        int depositar = 0;
        int retirar = 0;

        Cuentabancaria();
        void depositar(int cuenta){
            cuenta = cuenta + depositar;
        };
};


int main() {

    Producto p1("Camisa" , 10);
    Producto p2("Pantalones", 14, 5);
    Producto p3("relog", 40, 5);
    Producto p4("polo", 12, 38);


    Pedido pedido;


    pedido.agregarProducto(p1);
    pedido.agregarProducto(p2);
    pedido.agregarProducto(p3);


    pedido.mostrarPedido();

    return 0;
}