#include "clase.h"
#include <iostream>
#include <string>
using namespace std;

int main() {
    int opcion;
    const int MAX_PROD = 100;
    producto inventario[MAX_PROD];
    int numProductos = 0;

    const int MAX_PEDIDOS = 100;
    Pedido* pedidos[MAX_PEDIDOS];
    int numPedidos = 0;
    int contadorPedidos = 1;//asignar el numero del pedido

    cout << "MENU: \n 1. Agregar producto \n 2. Agregar stock \n 3. Inventario \n 4. Registrar pedido \n 5. Mostrar pedidos \n 6. Salir" << endl;
    cout << "Ingrese una opción: ";
    cin >> opcion;

    while (opcion != 6) {
        if (opcion == 1) {
            if (numProductos < MAX_PROD) {
                string nombre, estado;
                int codigo, stock;
                cout << "Ingrese el nombre del producto: ";
                cin.ignore();
                getline(cin, nombre);
                cout << "Ingrese el estado del producto (Nuevo/Usado): ";
                getline(cin, estado);
                cout << "Ingrese el código del producto: ";
                cin >> codigo;
                cout << "Ingrese el stock disponible: ";
                cin >> stock;

                inventario[numProductos] = producto(nombre, estado, codigo, stock);
                numProductos++;
                cout << "Producto agregado exitosamente.\n";
            } else {
                cout << "Inventario lleno, no se pueden agregar más productos.\n";
            }
        } else if (opcion == 2) {
            int cod, cantidad;
            cout << "Ingrese el código del producto para agregar stock: ";
            cin >> cod;
            cout << "Ingrese la cantidad a agregar: ";
            cin >> cantidad;

            bool encontrado = false;
            for (int i = 0; i < numProductos; i++) {
                if (inventario[i].getCodigo() == cod) {
                    inventario[i].setStock(inventario[i].getStock() + cantidad);
                    cout << "Stock actualizado correctamente.\n";
                    encontrado = true;
                    break;
                }
            }
            if (!encontrado) {
                cout << "Producto no encontrado.\n";
            }
        } else if (opcion == 3) {
            cout << "\nInventario de productos:\n";
            if (numProductos == 0) {
                cout << "El inventario está vacío." << endl;
            } else {
                for (int i = 0; i < numProductos; i++) {
                    inventario[i].mostrarProducto();
                }
            }
        } else if (opcion == 4) {
            if (numPedidos < MAX_PEDIDOS) {
                string nombreCliente, nombreProducto;
                int codigoProducto, cantidad;

                cout << "Ingrese el nombre del cliente: ";
                cin.ignore();
                getline(cin, nombreCliente);
                cout << "Ingrese el nombre del producto: ";
                getline(cin, nombreProducto);
                cout << "Ingrese el código del producto: ";
                cin >> codigoProducto;
                cout << "Ingrese la cantidad: ";
                cin >> cantidad;

                // Registrar el pedido
                pedidos[numPedidos] = new Pedido(contadorPedidos, nombreCliente, nombreProducto, cantidad, "pendiente");
                numPedidos++;
                contadorPedidos++;
                cout << "Pedido registrado exitosamente.\n";
            } else {
                cout << "No se pueden registrar más pedidos. Límite alcanzado.\n";
            }
        } else if (opcion == 5) {
            cout << "\n--- Lista de pedidos registrados ---\n";
            if (numPedidos == 0) {
                cout << "No hay pedidos registrados.\n";
            } else {
                for (int i = 0; i < numPedidos; i++) {
                    pedidos[i]->mostrarPedido();
                }
            }
        } else {
            cout << "Opción inválida. Intente nuevamente.\n";
        }

        cout << "\nMENU: \n 1. Agregar producto \n 2. Agregar stock \n 3. Inventario \n 4. Registrar pedido \n 5. Mostrar pedidos \n 6. Salir" << endl;
        cout << "Ingrese una opción: ";
        cin >> opcion;
    }

    // Liberar meria
    for (int i = 0; i < numPedidos; i++) {
        delete pedidos[i];
    }

    cout << "Saliendo del programa..." << endl;
    return 0;
}