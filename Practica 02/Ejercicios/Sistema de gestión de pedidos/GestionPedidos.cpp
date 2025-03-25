#include "GestionPedidos.h"

// nombre - cantidad - precio 
Producto::Producto(string nom, int cant, double prec)
    : nombre(nom), cantidad(cant), precio(prec) {}

Pedido::Pedido() : cliente(""), numProductos(0), total(0) {
    productos = new Producto[100]; // capacidad maxima de 100 productos por pedido
}

Pedido::Pedido(string cli) : cliente(cli), numProductos(0), total(0) {
    productos = new Producto[100];
}

Pedido::~Pedido() {
    delete[] productos; //destruios el pedido para liberar memoria
}

void Pedido::agregarProducto(Producto* prod, int cantidad) {
    if (prod->cantidad >= cantidad) {
        productos[numProductos] = *prod;
        productos[numProductos].cantidad = cantidad;
        total += prod->precio * cantidad;
        prod->cantidad -= cantidad;
        numProductos++;
    } else {
        cout << "No hay suficiente stock de " << prod->nombre << "." << endl;
    }
}

void Pedido::mostrarPedido() const {
    cout << "Pedido para " << cliente << ":" << endl;
    for (int i = 0; i < numProductos; i++) {
        cout << "- " << productos[i].nombre << " (" << productos[i].precio << " x " << productos[i].cantidad << ")" << endl;
    }
    cout << "Total: " << total << endl;
    cout << "-----------------------" << endl;
}

// clase gestion de pedidos 
GestionPedidos::GestionPedidos() : numProductosDisponibles(0), numPedidos(0) {
    productosDisponibles = new Producto[100]; // max 100 productos
    pedidos = new Pedido[100];               // max100 pedidos
}

GestionPedidos::~GestionPedidos() {
    delete[] productosDisponibles; 
    delete[] pedidos;
}

void GestionPedidos::agregarProducto(string nombre, int cantidad, double precio) {
    productosDisponibles[numProductosDisponibles] = Producto(nombre, cantidad, precio);
    numProductosDisponibles++;
    cout << "Producto agregado: " << nombre << " (" << cantidad << " unidades)" << endl;  //info 
}

void GestionPedidos::realizarPedido(string cliente) {
    Pedido nuevoPedido(cliente);
    string nombreProducto;
    int cantidad;

    while (true) {
        cout << "Ingrese el nombre del producto (o 'fin' para terminar): ";
        cin >> nombreProducto;
        if (nombreProducto == "fin") break;

        cout << "Ingrese la cantidad: ";
        cin >> cantidad;

        bool productoEncontrado = false;
        for (int i = 0; i < numProductosDisponibles; i++) {
            if (productosDisponibles[i].nombre == nombreProducto) {
                nuevoPedido.agregarProducto(&productosDisponibles[i], cantidad);
                productoEncontrado = true;
                break;
            }
        }

        if (!productoEncontrado) {
            cout << "Producto no encontrado." << endl;
        }
    }

    pedidos[numPedidos] = nuevoPedido;
    numPedidos++;
    cout << "Pedido realizado para " << cliente << "." << endl;
}

void GestionPedidos::mostrarProductosDisponibles() const {
    cout << "Productos disponibles:" << endl;
    for (int i = 0; i < numProductosDisponibles; i++) {
        cout << "- " << productosDisponibles[i].nombre << " (" << productosDisponibles[i].cantidad << " unidades)" << endl;
    }
    cout << "-----------------------" << endl;
}

void GestionPedidos::mostrarPedidos() const {
    cout << "Pedidos realizados:" << endl;
    for (int i = 0; i < numPedidos; i++) {
        pedidos[i].mostrarPedido();
    }
}