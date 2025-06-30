#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <map>
#include <algorithm>
#include <stdexcept>
#include <fstream>
#include <sstream>

using namespace std;

// Clase Producto
class Producto {
public:
    int id;
    string nombre;
    double precio;

    Producto(int id = 0, string nombre = "Desconocido", double precio = 0.0)
        : id(id), nombre(nombre), precio(precio) {}

    void mostrar() const {
        cout << "ID: " << id << " - " << nombre << " - S/" << precio << endl;
    }
};

// Clase Carrito
class Carrito {
private:
    map<int, pair<Producto, int>> items_carrito;

public:
    Carrito() {}

    void agregarProducto(const Producto& p, int cantidad = 1) {
        auto it = items_carrito.find(p.id);
        if (it != items_carrito.end()) {
            it->second.second += cantidad;
        } else {
            items_carrito[p.id] = {p, cantidad};
        }
    }

    void mostrarContenido() const {
        if (items_carrito.empty()) {
            cout << "Carrito vacio\n";
            return;
        }
        cout << "\n--- CONTENIDO DEL CARRITO ---\n";
        for (const auto& par : items_carrito) {
            const Producto& p = par.second.first;
            int cantidad = par.second.second;
            cout << p.nombre << " x" << cantidad << " = S/" << p.precio * cantidad << endl;
        }
    }

    double calcularTotal() const {
        double total = 0.0;
        for (const auto& par : items_carrito) {
            const Producto& p = par.second.first;
            int cantidad = par.second.second;
            total += p.precio * cantidad;
        }
        return total;
    }

    void vaciar() {
        items_carrito.clear();
    }
};

// Clase abstracta Persona
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
    virtual string getTipoUsuario() const = 0;
};

// Clase Cliente
class Cliente : public Persona {
public:
    Carrito carrito;

    Cliente(string nombre = "", string dni = "", string celular = "")
        : Persona(nombre, dni, celular) {}

    void mostrarMenu() override {
        cout << "\n--- MENU CLIENTE ---\n";
        cout << "1. Ver productos disponibles\n";
        cout << "2. Agregar producto al carrito\n";
        cout << "3. Ver carrito\n";
        cout << "4. Confirmar compra\n";
        cout << "5. Salir\n";
        cout << "Opcion: ";
    }

    string getTipoUsuario() const override { return "Cliente"; }
};

// Clase Administrador
class Administrador : public Persona {
public:
    Administrador(string nombre = "", string dni = "", string celular = "")
        : Persona(nombre, dni, celular) {}

    void mostrarMenu() override {
        cout << "\n--- MENU ADMINISTRADOR ---\n";
        cout << "1. Ver productos disponibles\n";
        cout << "2. Agregar producto al catalogo\n";
        cout << "3. Eliminar producto del catalogo\n";
        cout << "4. Salir\n";
        cout << "Opcion: ";
    }

    string getTipoUsuario() const override { return "Administrador"; }
};

// Variables globales
vector<Producto> catalogo;
vector<Persona*> usuarios;

int obtenerEnteroValido(const string& mensaje) {
    int valor;
    while (true) {
        cout << mensaje;
        if (cin >> valor) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return valor;
        } else {
            cerr << "Entrada invalida. Por favor, ingrese un numero entero.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

double obtenerDobleValido(const string& mensaje) {
    double valor;
    while (true) {
        cout << mensaje;
        if (cin >> valor) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return valor;
        } else {
            cerr << "Entrada invalida. Por favor, ingrese un numero decimal.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

void cargarCatalogo() {
    ifstream archivo("catalogo.txt");
    if (!archivo.is_open()) {
        cout << "No se encontro 'catalogo.txt'. Se iniciara con catalogo vacio o predefinido.\n";
        catalogo.push_back(Producto(1, "Laptop", 3500.0));
        catalogo.push_back(Producto(2, "Mouse", 50.0));
        catalogo.push_back(Producto(3, "Teclado", 120.0));
        return;
    }

    string linea;
    while (getline(archivo, linea)) {
        stringstream ss(linea);
        string id_str, nombre, precio_str;

        getline(ss, id_str, ',');
        getline(ss, nombre, ',');
        getline(ss, precio_str);

        try {
            int id = stoi(id_str);
            double precio = stod(precio_str);
            catalogo.push_back(Producto(id, nombre, precio));
        } catch (...) {
            cerr << "Error al leer una linea del archivo.\n";
        }
    }
    archivo.close();
    cout << "Catalogo cargado desde 'catalogo.txt'.\n";
}

void guardarCatalogo() {
    ofstream archivo("catalogo.txt");
    if (!archivo.is_open()) {
        cerr << "Error: No se pudo abrir 'catalogo.txt' para guardar.\n";
        return;
    }
    for (const auto& p : catalogo) {
        archivo << p.id << "," << p.nombre << "," << p.precio << endl;
    }
    archivo.close();
    cout << "Catalogo guardado en 'catalogo.txt'.\n";
}

void cargarUsuarios() {
    ifstream archivo("usuarios.txt");
    if (!archivo.is_open()) {
        cout << "No se encontro 'usuarios.txt'. Se iniciara con usuarios predefinidos.\n";
        usuarios.push_back(new Cliente("Juan Perez", "12345678", "987654321"));
        usuarios.push_back(new Administrador("Maria Lopez", "87654321", "912345678"));
        return;
    }

    string linea;
    while (getline(archivo, linea)) {
        stringstream ss(linea);
        string nombre, dni, celular, tipo_str;

        getline(ss, nombre, ',');
        getline(ss, dni, ',');
        getline(ss, celular, ',');
        getline(ss, tipo_str);

        if (tipo_str == "Cliente") {
            usuarios.push_back(new Cliente(nombre, dni, celular));
        } else if (tipo_str == "Administrador") {
            usuarios.push_back(new Administrador(nombre, dni, celular));
        }
    }
    archivo.close();
    cout << "Usuarios cargados desde 'usuarios.txt'.\n";
}

void guardarUsuarios() {
    ofstream archivo("usuarios.txt");
    if (!archivo.is_open()) {
        cerr << "Error: No se pudo abrir 'usuarios.txt' para guardar.\n";
        return;
    }
    for (const auto& p : usuarios) {
        archivo << p->getNombre() << "," << p->getDni() << "," << p->getCelular() << "," << p->getTipoUsuario() << endl;
    }
    archivo.close();
    cout << "Usuarios guardados en 'usuarios.txt'.\n";
}

Persona* buscarUsuario(const string& dni) {
    auto it = find_if(usuarios.begin(), usuarios.end(), [&](Persona* p) {
        return p->getDni() == dni;
    });
    if (it != usuarios.end()) {
        return *it;
    }
    return nullptr;
}

void registrarUsuario() {
    string nombre, dni, celular;
    int tipo;

    cout << "Nombre: ";
    getline(cin >> ws, nombre);

    cout << "DNI: ";
    getline(cin, dni);
    if (buscarUsuario(dni) != nullptr) {
        cout << "Error: Ya existe un usuario con ese DNI.\n";
        return;
    }

    cout << "Celular: ";
    getline(cin, celular);

    do {
        tipo = obtenerEnteroValido("Tipo de usuario (1. Cliente / 2. Administrador): ");
        if (tipo != 1 && tipo != 2) {
            cout << "Opcion invalida. Por favor, ingrese 1 o 2.\n";
        }
    } while (tipo != 1 && tipo != 2);

    if (tipo == 1) {
        usuarios.push_back(new Cliente(nombre, dni, celular));
    } else {
        usuarios.push_back(new Administrador(nombre, dni, celular));
    }
    cout << "Usuario registrado correctamente.\n";
}

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

void agregarProductoAlCatalogo() {
    int id;
    string nombre;
    double precio;

    id = obtenerEnteroValido("ID del nuevo producto: ");
    for (const auto& p : catalogo) {
        if (p.id == id) {
            cout << "Error: Ya existe un producto con el ID " << id << ".\n";
            return;
        }
    }

    cout << "Nombre: ";
    getline(cin >> ws, nombre);
    precio = obtenerDobleValido("Precio: S/");

    catalogo.push_back(Producto(id, nombre, precio));
    cout << "Producto agregado exitosamente.\n";
}

void eliminarProductoDelCatalogo() {
    int id = obtenerEnteroValido("ID del producto a eliminar: ");
    auto it = find_if(catalogo.begin(), catalogo.end(), [&](const Producto& p) {
        return p.id == id;
    });

    if (it != catalogo.end()) {
        catalogo.erase(it);
        cout << "Producto eliminado exitosamente.\n";
    } else {
        cout << "Producto con ese ID no encontrado.\n";
    }
}

void menuPrincipalUsuario(Persona* p) {
    Cliente* cliente = dynamic_cast<Cliente*>(p);
    Administrador* admin = dynamic_cast<Administrador*>(p);

    if (cliente) {
        int opcion;
        do {
            cliente->mostrarMenu();
            opcion = obtenerEnteroValido("");

            switch (opcion) {
                case 1:
                    mostrarProductosDisponibles();
                    break;
                case 2: {
                    mostrarProductosDisponibles();
                    int id_prod = obtenerEnteroValido("ID del producto a agregar: ");
                    int cantidad = obtenerEnteroValido("Cantidad: ");
                    auto it = find_if(catalogo.begin(), catalogo.end(), [&](const Producto& prod) {
                        return prod.id == id_prod;
                    });
                    if (it != catalogo.end()) {
                        cliente->carrito.agregarProducto(*it, cantidad);
                        cout << "Producto agregado al carrito.\n";
                    } else {
                        cout << "Producto no encontrado.\n";
                    }
                    break;
                }
                case 3:
                    cliente->carrito.mostrarContenido();
                    break;
                case 4:
                    if (cliente->carrito.calcularTotal() > 0) {
                        cout << "\nTotal a pagar: S/" << cliente->carrito.calcularTotal() << endl;
                        cliente->carrito.vaciar();
                        cout << "Compra realizada con exito.\n";
                    } else {
                        cout << "Carrito vacio.\n";
                    }
                    break;
                case 5:
                    cout << "Saliendo del menu del cliente...\n";
                    break;
                default:
                    cout << "Opcion invalida.\n";
            }
        } while (opcion != 5);
    } else if (admin) {
        int opcion;
        do {
            admin->mostrarMenu();
            opcion = obtenerEnteroValido("");
            switch (opcion) {
                case 1:
                    mostrarProductosDisponibles();
                    break;
                case 2:
                    agregarProductoAlCatalogo();
                    break;
                case 3:
                    eliminarProductoDelCatalogo();
                    break;
                case 4:
                    cout << "Saliendo del menu del administrador...\n";
                    break;
                default:
                    cout << "Opcion invalida.\n";
            }
        } while (opcion != 4);
    }
}

void iniciarSesion() {
    string dni;
    cout << "Ingrese su DNI: ";
    getline(cin >> ws, dni);

    Persona* p = buscarUsuario(dni);
    if (p) {
        cout << "\nBienvenido/a " << p->getNombre() << " (" << p->getCelular() << ")\n";
        menuPrincipalUsuario(p);
    } else {
        cout << "Usuario no encontrado.\n";
    }
}

int main() {
    cin.exceptions(ios::failbit | ios::badbit);
    cargarCatalogo();
    cargarUsuarios();

    int opcion;
    do {
        cout << "\n--- SISTEMA DE TIENDA ---\n"
             << "1. Iniciar sesion\n"
             << "2. Registrarse\n"
             << "3. Salir\n"
             << "Opcion: ";
        try {
            opcion = obtenerEnteroValido("");
        } catch (...) {
            cerr << "Error de entrada. Reinicie el programa.\n";
            opcion = 0;
            continue;
        }

        switch (opcion) {
            case 1:
                iniciarSesion();
                break;
            case 2:
                registrarUsuario();
                break;
            case 3:
                cout << "Saliendo del sistema...\n";
                break;
            default:
                cout << "Opcion invalida.\n";
        }
    } while (opcion != 3);

    guardarCatalogo();
    guardarUsuarios();
    for (Persona* p : usuarios) {
        delete p;
    }
    usuarios.clear();

    return 0;
}
