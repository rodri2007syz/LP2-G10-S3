#ifndef GESTIONPEDIDOS_H
#define GESTIONPEDIDOS_H

#include <iostream>
#include <string>
using namespace std;

class Producto {
public:
    string nombre;
    int cantidad;
    double precio;

    Producto(string nom = "", int cant = 0, double prec = 0.0);
};

class Pedido {
public:
    string cliente;
    Producto* productos; // Puntero a un arreglo de productos
    int numProductos;
    double total;

    Pedido(); // Constructor por defecto
    Pedido(string cli); // Constructor con parametro

    ~Pedido();
    void agregarProducto(Producto* prod, int cantidad);
    void mostrarPedido() const;
};

class GestionPedidos {
private:
    Producto* productosDisponibles; // Puntero a un arreglo de productos disponibles
    int numProductosDisponibles;
    Pedido* pedidos;                // Puntero a un arreglo de pedidos
    int numPedidos;

public:
    GestionPedidos();
    ~GestionPedidos();
    void agregarProducto(string nombre, int cantidad, double precio);
    void realizarPedido(string cliente);
    void mostrarProductosDisponibles() const;
    void mostrarPedidos() const;
};

#endif
