#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <map>
#include <stdexcept>

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
        cout << "|Nombre: " << nombre << " | Precio: S/. " << precio << " | Cantidad: " << cantidad << endl;
    }
};

map<string, long> guardarInventarioYCrearIndice(const vector<Producto>& inventario, const string& filename) {
    ofstream archivoEs(filename);
    map<string, long> productIndex;

    if (!archivoEs.is_open()) {
        throw runtime_error("No se pudo abrir el archivo para escritura: " + filename + ". Verifique permisos o ruta.");
    }

    for (const auto& producto : inventario) {
        long currentPos = archivoEs.tellp();
        productIndex[producto.getNombre()] = currentPos;

        archivoEs << producto.getNombre() << ","<< producto.getPrecio() << ","<< producto.getCantidad() << endl;
    }
    archivoEs.close();
    cout << "Inventario guardado en '" << filename << "' y índice creado exitosamente." << endl;
    return productIndex;
}

Producto* buscarProductoPorNombre(const string& nombreProducto, const map<string, long>& index, const string& filename) {

    auto it = index.find(nombreProducto);
    if (it == index.end()) {

        return nullptr;
    }

    long offset = it->second;

    ifstream archivoLec(filename);
    if (!archivoLec.is_open()) {
        throw runtime_error("No se pudo abrir el archivo para lectura aleatoria: " + filename + ". Verifique permisos o ruta.");
    }


    archivoLec.seekg(offset);


    string line;
    if (getline(archivoLec, line)) {

        stringstream ss(line);
        string nom, preStr, cantStr;

        if (getline(ss, nom, ',') &&
            getline(ss, preStr, ',') &&
            getline(ss, cantStr)) {
            try {
                double pre = stod(preStr);
                int cant = stoi(cantStr);
                archivoLec.close();
                return new Producto(nom, pre, cant);
            } catch (const invalid_argument& e) {

                throw runtime_error("Error de formato de datos (valor no numérico) para '" + nombreProducto + "' en línea: '" + line + "'. Detalle: " + e.what());
            } catch (const out_of_range& e) {
                throw runtime_error("Error de formato de datos (valor fuera de rango) para '" + nombreProducto + "' en línea: '" + line + "'. Detalle: " + e.what());
            }
        } else {

            throw runtime_error("Error de formato de línea (valores incompletos) para el producto '" + nombreProducto + "' en línea: '" + line + "'");
        }
    } else {

        throw runtime_error("Error al leer la línea desde el offset para el producto '" + nombreProducto + "' en el archivo: " + filename);
    }

    archivoLec.close();
    return nullptr;
}

int main() {
    vector<Producto> inventario;

    inventario.emplace_back("pan", 12.32, 12);
    inventario.emplace_back("queso", 13.30, 5);
    inventario.emplace_back("soda", 11.10, 10);
    inventario.emplace_back("leche", 5.50, 20);
    inventario.emplace_back("cafe", 25.00, 7);

    string nombreArchivo = "InformeDeProductos.txt";
    map<string, long> indiceProductos;


    try {
        indiceProductos = guardarInventarioYCrearIndice(inventario, nombreArchivo);
    } catch (const runtime_error& e) {
        cerr << "Error al inicializar el inventario: " << e.what() << endl;
        return 1;
    } catch (const exception& e) {
        cerr << "Un error inesperado ocurrió durante la escritura del archivo: " << e.what() << endl;
        return 1;
    }

    cout << "\n--- Realizando Búsquedas Aleatorias con Gestión de Excepciones ---" << endl;

    vector<string> productosABuscar = {"queso", "cafe", "pizza", "azucar", "12.5,4"};
    for (const string& productoNombre : productosABuscar) {
        try {
            Producto* productoEncontrado = buscarProductoPorNombre(productoNombre, indiceProductos, nombreArchivo);
            if (productoEncontrado) {
                cout << "Producto encontrado: ";
                productoEncontrado->infoDelProducto();
                delete productoEncontrado;
            } else {

                cout << "Búsqueda exitosa, pero el producto '" << productoNombre << "' no existe en el inventario." << endl;
            }
        } catch (const runtime_error& e) {

            cerr << "Error al buscar el producto '" << productoNombre << "': " << e.what() << endl;
        } catch (const exception& e) {

            cerr << "Un error inesperado ocurrió al buscar el producto '" << productoNombre << "': " << e.what() << endl;
        }
        cout << "------------------------------------------" << endl;
    }

    return 0;
}