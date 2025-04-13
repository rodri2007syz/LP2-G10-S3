#ifndef USUARIO_H
#define USUARIO_H

#include <iostream>
#include <string>

using namespace std;
const int maxp = 100;


class Usuario { // Clase Padre
protected:
    string nombreUsuario;
    string correo;
    string contrasena;
    int numero;
    
public:
    // Constructor
    Usuario(string nombre, string correo, string contrasena, int numero)
        : nombreUsuario(nombre), correo(correo), contrasena(contrasena), numero(numero) {}
    
    // Metodos
    virtual void mostrarInfo() const {
        cout << "Usuario: " << nombreUsuario << endl;
        cout << "Correo: " << correo << endl;
        cout << "Numero telefonico: " << numero << endl;
    }
    
    void recuperarContrasena() const {
        cout << "Correo: " << correo << endl;
        cout << "Contrasena: " << contrasena << endl;
    }
    
    virtual ~Usuario() {} // Destructor virtual
};

class UsuarioRegular : public Usuario {  // Clase Hija 1
private:
    int puntosUser;
    static const float descuentoUserRegular;
    
public:
    // Constructor
    UsuarioRegular(string nombre, string correo, string contrasena, int numero, int puntos)
        : Usuario(nombre, correo, contrasena, numero), puntosUser(puntos) {}
    
    // Metodos
    void mostrarInfo() const override {
        Usuario::mostrarInfo();
        cout << "Tipo: Cliente regular" << endl;
        cout << "Puntos en cuenta: " << puntosUser << endl;
        cout << "Descuento aplicado: " << descuentoUserRegular << "%" << endl;
    }
    
    void acumularPuntos(int nuevosPuntos) {
        puntosUser += nuevosPuntos;
    }
};

class UsuarioPremium : public Usuario {  // Clase Hija 2
private:
    string nivelMembresia;
    float descuentoPers;
    
public:
    // Constructor
    UsuarioPremium(string nombre, string correo, string contrasena, int numero, 
                  string nivel, float descuento)
        : Usuario(nombre, correo, contrasena, numero), 
          nivelMembresia(nivel), descuentoPers(descuento) {}
    
    // Metodos
    void mostrarInfo() const override {
        Usuario::mostrarInfo();
        cout << "Tipo: Cliente Premium | Nivel de membresia: " << nivelMembresia << endl;
        cout << "Descuento aplicado: " << descuentoPers << "%" << endl;
    }
    
    //actualizar la membresia
    void actMembresia(string nuevoNivel, float nuevoDescuento) {
        nivelMembresia = nuevoNivel;
        descuentoPers = nuevoDescuento;
    }
    
    float getDescuento() const {
        return descuentoPers;
    }
};
class Producto {
private:
    int id;
    string nombre;
    double precio;
public:
    Producto(int id=0, string nombre=" ", double precio=0.0)
        : id(id), nombre(nombre), precio(precio) {}
    void mostrar() const {
        cout << "ID : " << id << "- Nombre: " << nombre << " - $ " << precio;
    }
    int getId() const { return id; }
    string getNombre() const { return nombre; }
    double getPrecio() const { return precio; }
};
class Carrito {
    Producto productos[maxp];
    int cantidades[maxp];
    int cantidadProductos;
public:
    Carrito() : cantidadProductos(0) {}

    void agregarProducto(const Producto& p, int cantidad = 1) {
        for (int i = 0; i < cantidadProductos; i++) {
            if (productos[i].getId() == p.getId()) {
                cantidades[i] += cantidad;
                return;
            }
        }
        if (cantidadProductos < maxp) {
            productos[cantidadProductos] = p;
            cantidades[cantidadProductos] = cantidad;
            cantidadProductos++;
        }
        else {
            cout << "El carrito esta lleno!" << endl;
        }
    }

    void eliminarProducto(int idProducto) {
        for (int i = 0; i < cantidadProductos; i++) {
            if (productos[i].getId() == idProducto) {
                for (int j = i; j < cantidadProductos - 1; j++) {
                    productos[j] = productos[j + 1];
                    cantidades[j] = cantidades[j + 1];
                }
                cantidadProductos--;
                return;
            }
        }
        cout << "Producto no encontrado en el carrito" << endl;
    }

    double calcularTotal() const {
        double total = 0.0;
        for (int i = 0; i < cantidadProductos; i++) {
            total += productos[i].getPrecio() * cantidades[i];
        }
        return total;
    }

    void mostrarContenido() const {
        if (cantidadProductos == 0) {
            cout << "El carrito está vacio" << endl;
            return;
        }

        cout << "Contenido del carrito:" << endl;
        for (int i = 0; i < cantidadProductos; i++) {
            cout << "  ";
            productos[i].mostrar();
            cout << " - Cantidad: " << cantidades[i] << endl;
        }
        cout << "Total: $" << calcularTotal() << endl;
    }
};

const float UsuarioRegular::descuentoUserRegular = 6.0f;

#endif // USUARIO_H