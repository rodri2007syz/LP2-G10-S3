#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <map> // Necesario para std::map

using namespace std;

// --- Clase Producto ---
class Producto {
private:
    string nombre;
    double precio;
    int cantidad;

public:
    // Constructor
    Producto(string nom, double pre, int cant) : nombre(nom), precio(pre), cantidad(cant) {}

    // Getters
    string getNombre() const { return nombre; }
    double getPrecio() const { return precio; }
    int getCantidad() const { return cantidad; }

    // Método para mostrar información del producto
    void infoDelProducto() const {
        cout << "|Nombre: " << nombre << " | Precio: S/. " << precio << " | Cantidad: " << cantidad << endl;
    }
};

map<string, long> guardarInventarioYCrearIndice(const vector<Producto>& inventario, const string& filename) {
    ofstream archivoEs(filename);
    map<string, long> productIndex; 

    if (!archivoEs.is_open()) {
        cout << "Error: No se pudo abrir el archivo para escritura: " << filename << endl;
        return productIndex; 
    }

    for (const auto& producto : inventario) {
        long currentPos = archivoEs.tellp();
        productIndex[producto.getNombre()] = currentPos;

        archivoEs << producto.getNombre() << ","<< producto.getPrecio() << ","<< producto.getCantidad() << endl;
    }
    archivoEs.close();
    cout << "Inventario guardado en '" << filename << "' y índice creado." << endl;
    return productIndex;
}


Producto* buscarProductoPorNombre(const string& nombreProducto, const map<string, long>& index, const string& filename) {

    auto it = index.find(nombreProducto);
    if (it == index.end()) {
        cout << "Producto '" << nombreProducto << "' no encontrado en el índice." << endl;
        return nullptr;
    }

    long offset = it->second;


    ifstream archivoLec(filename);
    if (!archivoLec.is_open()) {
        cout << "Error: No se pudo abrir el archivo para lectura aleatoria: " << filename << endl;
        return nullptr;
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
            } catch (const std::invalid_argument& e) {
                cout << "Error de conversión de datos para '" << nombreProducto << "': " << e.what() << endl;
            } catch (const std::out_of_range& e) {
                cout << "Valor fuera de rango para '" << nombreProducto << "': " << e.what() << endl;
            }
        } else {
            cout << "Error de formato de línea para el producto '" << nombreProducto << "': " << line << endl;
        }
    } else {
        cout << "Error al leer la línea desde el offset para el producto '" << nombreProducto << "'." << endl;
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

    map<string, long> indiceProductos = guardarInventarioYCrearIndice(inventario, nombreArchivo);

    cout << "\n--- Realizando Búsquedas Aleatorias ---" << endl;

    string productoABuscar1 = "queso";
    Producto* productoEncontrado1 = buscarProductoPorNombre(productoABuscar1, indiceProductos, nombreArchivo);
    if (productoEncontrado1) {
        cout << "Producto encontrado: ";
        productoEncontrado1->infoDelProducto();
        delete productoEncontrado1; 
    }

    string productoABuscar2 = "cafe";
    Producto* productoEncontrado2 = buscarProductoPorNombre(productoABuscar2, indiceProductos, nombreArchivo);
    if (productoEncontrado2) {
        cout << "Producto encontrado: ";
        productoEncontrado2->infoDelProducto();
        delete productoEncontrado2;
    }

    string productoABuscar3 = "pizza";
    Producto* productoEncontrado3 = buscarProductoPorNombre(productoABuscar3, indiceProductos, nombreArchivo);
    if (!productoEncontrado3) {
        cout << "El producto '" << productoABuscar3 << "' no se encontró como se esperaba." << endl;
    }

    return 0;
}