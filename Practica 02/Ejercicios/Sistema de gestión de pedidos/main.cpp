#include "GestionPedidos.h"

int main() {
    GestionPedidos sistema;

    // inventario
    sistema.agregarProducto("audifonos", 34, 89);
    sistema.agregarProducto("Mouse", 50, 25);
    sistema.agregarProducto("Teclado", 30, 45);

    // info
    sistema.mostrarProductosDisponibles();

    // realizar pedido
    sistema.realizarPedido("Juan Perez");
    sistema.realizarPedido("Maria Lopez");

    // mostrar pedido
    sistema.mostrarPedidos();

    // mostrar productos
    sistema.mostrarProductosDisponibles();

    return 0;
}