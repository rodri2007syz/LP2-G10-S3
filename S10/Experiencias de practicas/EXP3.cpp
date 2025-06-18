#include <vector>
#include <string>
#include <iostream>
#include <stdexcept>
#include <algorithm>  // IMPORTANTE: para std::find

using namespace std;

// Template de clase para un sistema de gestion de inventario generico
template <typename T>
class InventarioRutas {
private:
    vector<T> elementos;
    string nombre;

public:
    InventarioRutas(const string& nombre) : nombre(nombre) {}

    void agregarElemento(const T& elemento) {
        elementos.push_back(elemento);
    }

    void eliminarElemento(const T& elemento) {
        auto it = find(elementos.begin(), elementos.end(), elemento);
        if (it != elementos.end()) {
            elementos.erase(it);
        } else {
            throw runtime_error("Elemento no encontrado en el inventario");
        }
    }

    void mostrarInventario() const {
        cout << "Inventario de " << nombre << ":\n";
        for (const auto& elemento : elementos) {
            cout << "- " << elemento << "\n";
        }
    }

    size_t cantidadElementos() const {
        return elementos.size();
    }

    const T& obtenerElemento(size_t indice) const {
        if (indice >= elementos.size()) {
            throw out_of_range("Indice fuera de rango");
        }
        return elementos[indice];
    }
};

// Clase para representar una ruta de entrega
class RutaEntrega {
private:
    string id;
    string descripcion;

public:
    RutaEntrega(const string& id, const string& descripcion)
        : id(id), descripcion(descripcion) {}

    friend ostream& operator<<(ostream& os, const RutaEntrega& ruta) {
        os << "Ruta " << ruta.id << ": " << ruta.descripcion;
        return os;
    }

    bool operator==(const RutaEntrega& otra) const {
        return id == otra.id;
    }
};

void probarTemplatesClase() {
    InventarioRutas<string> inventarioNombres("Nombres de Rutas");
    inventarioNombres.agregarElemento("Ruta Norte");
    inventarioNombres.agregarElemento("Ruta Sur");
    inventarioNombres.agregarElemento("Ruta Este");
    inventarioNombres.mostrarInventario();
    
    // Uso con objetos RutaEntrega
    InventarioRutas<RutaEntrega> inventarioRutas("Rutas de Entrega");
    inventarioRutas.agregarElemento(RutaEntrega("R001", "Zona industrial a centro"));
    inventarioRutas.agregarElemento(RutaEntrega("R002", "Centro a residencial"));
    inventarioRutas.mostrarInventario();
    
    try {
        inventarioRutas.eliminarElemento(RutaEntrega("R001", ""));
        cout << "Despues de eliminar R001, cantidad: "<< inventarioRutas.cantidadElementos() << "\n";
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << "\n";
    }
}

// Funcion principal
int main() {
    probarTemplatesClase();
    return 0;
}
