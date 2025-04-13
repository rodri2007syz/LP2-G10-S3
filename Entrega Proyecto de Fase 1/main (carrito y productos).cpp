#include <iostream>
#include <string>
#include "usuario.h"

using namespace std;

int main() {
    // Crear productos
    Producto laptop(1, "Laptop", 999.99);
    Producto celular(2, "Celular", 499.99);
    Producto tablet(3, "Tablet", 299.99);
    
    // Crear carrito
    Carrito carrito;

    // Mostrar carrito vacío
    carrito.mostrarContenido();
    
    // Agregar productos al carrito
    carrito.agregarProducto(laptop, 2); // 2 laptops
    carrito.agregarProducto(celular, 1); // 1 celular
    carrito.agregarProducto(tablet, 3); // 3 tablets

    // carrito inicial
    carrito.mostrarContenido();

    // Eliminar un producto celular
    carrito.eliminarProducto(2); // Eliminar el celular
    
    // Mostrar  después de eliminar un producto
    carrito.mostrarContenido();

    // Agregar laptop
    carrito.agregarProducto(laptop, 1); // 1 laptop adicional

    //contenido final del carrito
    carrito.mostrarContenido();


    cout << "Total del carrito: $" << carrito.calcularTotal() << endl;

    return 0;
}