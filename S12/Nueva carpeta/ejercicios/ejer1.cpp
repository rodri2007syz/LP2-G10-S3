#include <iostream>
#include <map>
#include <string>
#include <limits>
#include <algorithm>
#include <vector>

using namespace std;

struct Producto {
    string descripcion;
    int cantidad;

    Producto(string desc = "", int cant = 0) : descripcion(std::move(desc)), cantidad(cant) {}
};

void clearInputBuffer() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void mostrarMenuInventario() {
    cout << "\n--- GESTION DE INVENTARIO ---" << endl;
    cout << "1. Agregar producto" << endl;
    cout << "2. Actualizar cantidad de producto" << endl;
    cout << "3. Buscar producto por codigo" << endl;
    cout << "4. Mostrar todos los productos (por descripcion)" << endl;
    cout << "5. Salir" << endl;
    cout << "Seleccione una opcion: ";
}

int main() {
    map<int, Producto> inventario;
    int opcion;
    int proximoCodigo = 1;

    do {
        mostrarMenuInventario();
        cin >> opcion;
        clearInputBuffer();

        switch (opcion) {
            case 1: {
                cout << "\n--- AGREGAR PRODUCTO ---" << endl;
                cout << "Ingrese descripcion del producto: ";
                string desc;
                getline(cin, desc);

                cout << "Ingrese cantidad disponible: ";
                int cant;
                cin >> cant;
                clearInputBuffer();

                inventario[proximoCodigo] = Producto(desc, cant);
                cout << "Producto '" << desc << "' agregado con codigo: " << proximoCodigo << endl;
                proximoCodigo++;
                break;
            }
            case 2: {
                cout << "\n--- ACTUALIZAR CANTIDAD ---" << endl;
                cout << "Ingrese el codigo del producto a actualizar: ";
                int codigoActualizar;
                cin >> codigoActualizar;
                clearInputBuffer();

                auto it = inventario.find(codigoActualizar);
                if (it != inventario.end()) {
                    cout << "Producto encontrado: " << it->second.descripcion << " (Cantidad actual: " << it->second.cantidad << ")" << endl;
                    cout << "Ingrese la nueva cantidad: ";
                    int nuevaCantidad;
                    cin >> nuevaCantidad;
                    clearInputBuffer();
                    it->second.cantidad = nuevaCantidad;
                    cout << "Cantidad actualizada correctamente." << endl;
                } else {
                    cout << "Producto con codigo " << codigoActualizar << " no encontrado." << endl;
                }
                break;
            }
            case 3: {
                cout << "\n--- BUSCAR PRODUCTO ---" << endl;
                cout << "Ingrese el codigo del producto a buscar: ";
                int codigoBuscar;
                cin >> codigoBuscar;
                clearInputBuffer();

                auto it = inventario.find(codigoBuscar);
                if (it != inventario.end()) {
                    cout << "--- PRODUCTO ENCONTRADO ---" << endl;
                    cout << "Codigo: " << it->first << endl;
                    cout << "Descripcion: " << it->second.descripcion << endl;
                    cout << "Cantidad: " << it->second.cantidad << endl;
                } else {
                    cout << "Producto con codigo " << codigoBuscar << " no encontrado." << endl;
                }
                break;
            }
            case 4: {
                cout << "\n--- LISTA DE PRODUCTOS ---" << endl;
                if (inventario.empty()) {
                    cout << "El inventario esta vacio." << endl;
                } else {
                    vector<pair<int, Producto>> productosOrdenados;
                    for (const auto& par : inventario) {
                        productosOrdenados.push_back(par);
                    }

                    sort(productosOrdenados.begin(), productosOrdenados.end(),
                              [](const pair<int, Producto>& a, const pair<int, Producto>& b) {
                        return a.second.descripcion < b.second.descripcion;
                    });

                    for (const auto& par : productosOrdenados) {
                        cout << "Codigo: " << par.first
                                 << ", Descripcion: " << par.second.descripcion
                                 << ", Cantidad: " << par.second.cantidad << endl;
                    }
                }
                break;
            }
            case 5: {
                cout << "Saliendo del programa. ¡Hasta luego!" << endl;
                break;
            }
            default: {
                cout << "Opcion no valida. Por favor, intente de nuevo." << endl;
                break;
            }
        }
        cout << endl;
    } while (opcion != 5);

    return 0;
}