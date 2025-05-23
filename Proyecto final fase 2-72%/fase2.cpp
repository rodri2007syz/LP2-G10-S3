#include <iostream>
#include <string>
#include <vector>
#include <limits>

using namespace std;

const int MAX_PRODUCTOS = 100;


// Clase Producto

class Producto {
public:
    int id;
    string nombre;
    double precio;

    Producto(int id = 0, string nombre = "", double precio = 0.0)
        : id(id), nombre(nombre), precio(precio) {}

    void mostrar() const {
        cout << "ID: " << id << " - " << nombre << " - S/" << precio << endl;
    }
};

//  Clase Carrito
class Carrito {
private:

    Producto productos[MAX_PRODUCTOS]; // almacenar los productos en el carrito
    int cantidades[MAX_PRODUCTOS];     // almacenar la cantidad de cada producto
    int cantidadProductos;             // Contador de cuantos tipos de productos diferentes hay en el carrito

public:
    Carrito() : cantidadProductos(0) {}

    void agregarProducto(const Producto& p, int cantidad = 1) {
        for (int i = 0; i < cantidadProductos; i++) {
            if (productos[i].id == p.id) {
                cantidades[i] += cantidad;
                return;
            }
        }
        if (cantidadProductos < MAX_PRODUCTOS) { // Referencia directa al tamaño del array
            productos[cantidadProductos] = p;
            cantidades[cantidadProductos] = cantidad;
            cantidadProductos++;
        } else {
            cout << "Error: Carrito lleno\n";
        }
    }

    void mostrarContenido() const {
        if (cantidadProductos == 0) {
            cout << "Carrito vacio\n";
            return;
        }
        cout << "\n--- CONTENIDO DEL CARRITO ---\n";
        for (int i = 0; i < cantidadProductos; i++) {
            cout << productos[i].nombre << " x" << cantidades[i] << " = S/" << productos[i].precio * cantidades[i] << endl;
        }
    }

    double calcularTotal() const {
        double total = 0.0;
        for (int i = 0; i < cantidadProductos; i++) {
            total += productos[i].precio * cantidades[i];
        }
        return total;
    }

    void vaciar() {
        cantidadProductos = 0;
    }
};

// Clase Abstracta Persona
class Persona {
protected:
    string nombre;
    string dni;
    string celular;

public:
    Persona(string nombre = "", string dni = "", string celular = "")
        : nombre(nombre), dni(dni), celular(celular) {}

    virtual ~Persona() {}

    string getDni() const { return dni; }
    string getNombre() const { return nombre; }
    string getCelular() const { return celular; }

    virtual void mostrarMenu() = 0;
};


class Cliente : public Persona {
public:
    Carrito carrito;

    Cliente(string nombre = "", string dni = "", string celular = "")
        : Persona(nombre, dni, celular) {}

    void mostrarMenu() override { //menu cliente
        cout << "\n--- MENU CLIENTE ---\n";
        cout << "1. Ver productos disponibles\n";
        cout << "2. Agregar producto al carrito\n";
        cout << "3. Ver carrito\n";
        cout << "4. Confirmar compra\n";
        cout << "5. Salir\n";
        cout << "Opcion: ";
    }
};

class Administrador : public Persona {
public:
    Administrador(string nombre = "", string dni = "", string celular = "")
        : Persona(nombre, dni, celular) {}

    void mostrarMenu() override { //menu de admin
        cout << "\n--- MENU ADMINISTRADOR ---\n";
        cout << "1. Ver productos disponibles\n";
        cout << "2. Agregar producto al catalogo\n";
        cout << "3. Eliminar producto del catalogo\n";
        cout << "4. Salir\n";
        cout << "Opcion: ";
    }
};


// vector Producto---<<<
vector<Producto> catalogo = {
    Producto(1, "Laptop", 3500.0),
    Producto(2, "Mouse", 50.0),
    Producto(3, "Teclado", 120.0)
};

//v Persona
vector<Persona*> usuarios;

Persona* buscarUsuario(const string& dni) {
    for (Persona* p : usuarios) {
        if (p->getDni() == dni) return p;
    }
    return nullptr;
}

// registrar un nuevo usuario en el sistema.
void registrarUsuario() {
    string nombre, dni, celular;
    int tipo;
    cout << "Nombre: ";
    getline(cin >> ws, nombre); //ws elimina espacios
    cout << "DNI: ";
    getline(cin, dni);
    cout << "Celular: ";
    getline(cin, celular);
    do {
        cout << "Tipo de usuario (1. Cliente / 2. Administrador): ";
        cin >> tipo;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    } while (tipo != 1 && tipo != 2);

    if (tipo == 1) {
        usuarios.push_back(new Cliente(nombre, dni, celular));
    } else {
        usuarios.push_back(new Administrador(nombre, dni, celular));
    }
    cout << "Usuario registrado correctamente.\n";
}

// mostrar la lista de productos en el catalogo.
void mostrarProductosDisponibles() {
    cout << "\n--- PRODUCTOS DISPONIBLES ---\n";
    if (catalogo.empty()) {
        cout << "No hay productos en el catalogo.\n";
        return;
    }
    for (const auto& p : catalogo) {
        p.mostrar();
    }
}

//  nuevo producto al catalogo .
void agregarProductoAlCatalogo() {
    int id;
    string nombre;
    double precio;

    cout << "ID del nuevo producto: ";
    cin >> id;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Nombre: ";
    getline(cin >> ws, nombre);
    cout << "Precio: S/";
    cin >> precio;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    catalogo.push_back(Producto(id, nombre, precio));
    cout << "Producto agregado exitosamente.\n";
}

// Funcion para eliminar un producto
void eliminarProductoDelCatalogo() {
    int id;
    cout << "ID del producto a eliminar: ";
    cin >> id;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (auto it = catalogo.begin(); it != catalogo.end(); ++it) {
        if (it->id == id) {
            catalogo.erase(it);
            cout << "Producto eliminado exitosamente.\n";
            return;
        }
    }
    cout << "Producto no encontrado.\n";
}


void menuPrincipalUsuario(Persona* p) {

    Cliente* cliente = dynamic_cast<Cliente*>(p);
    Administrador* admin = dynamic_cast<Administrador*>(p);

    if (cliente) { // Si 'p' es realmente un Cliente
        int opcion;
        do {
            cliente->mostrarMenu(); //menu del cliente
            cin >> opcion;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            switch (opcion) {
                case 1: mostrarProductosDisponibles(); break;
                case 2: { //productos del cliente
                    mostrarProductosDisponibles();
                    int id, cantidad;
                    cout << "ID del producto: "; cin >> id;
                    cout << "Cantidad: "; cin >> cantidad;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    bool encontrado = false;
                    for (const auto& prod : catalogo) {
                        if (prod.id == id) {
                            cliente->carrito.agregarProducto(prod, cantidad);
                            cout << "Producto agregado.\n";
                            encontrado = true;
                            break;
                        }
                    }
                    if (!encontrado) cout << "Producto no encontrado en el catalogo.\n";
                    break;
                }
                case 3: cliente->carrito.mostrarContenido(); break;
                case 4:
                    cout << "\nTotal a pagar: S/" << cliente->carrito.calcularTotal() << endl;
                    cliente->carrito.vaciar();
                    cout << "Compra realizada con exito.\n";
                    break;
                case 5: cout << "Saliendo del menu...\n"; break;
                default: cout << "Opcion invalida.\n";
            }
        } while (opcion != 5);
    } else if (admin) { //si p es admin
        int opcion;
        do {
            admin->mostrarMenu();
            cin >> opcion;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            switch (opcion) {
                case 1: mostrarProductosDisponibles(); break;
                case 2: agregarProductoAlCatalogo(); break;
                case 3: eliminarProductoDelCatalogo(); break;
                case 4: cout << "Saliendo del menu...\n"; break;
                default: cout << "Opcion invalida.\n";
            }
        } while (opcion != 4);
    }
}


//funcion de inicio de sesion
void iniciarSesion() {
    string dni;
    cout << "Ingrese su DNI: ";
    getline(cin >> ws, dni);
    Persona* p = buscarUsuario(dni);
    if (p) {
        cout << "\nBienvenido/a " << p->getNombre() << " (" << p->getCelular() << ")\n";//p es el this
        menuPrincipalUsuario(p); // Llama al menu especifico del usuario logeado.
    } else {
        cout << "Usuario no encontrado.\n";
    }
}


int main() {//<---------------------------------------main

    //usuarios pre registrados

    usuarios.push_back(new Cliente("Juan Perez", "12345678", "987654321"));
    usuarios.push_back(new Administrador("Maria Lopez", "87654321", "912345678"));

    int opcion;
    do {
        cout << "\n--- SISTEMA DE TIENDA ---\n"
            << "1. Iniciar sesion\n"
            << "2. Registrarse\n"
            << "3. Salir\n"
            << "Opcion: ";
        cin >> opcion;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (opcion) {
            case 1: iniciarSesion(); break;
            case 2: registrarUsuario(); break;
            case 3: cout << "Saliendo del sistema...\n"; break;
            default: cout << "Opcion invalida.\n";
        }
    } while (opcion != 3);

    for (Persona* p : usuarios) {
        delete p;
    }
    usuarios.clear();

    return 0;
}