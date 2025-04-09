#include <iostream>
#include <vector>
#include <string>
using namespace std;


class Proveedor {
private:
    string nombre;
    string contacto;
public:
    Proveedor(string n, string c) : nombre(n), contacto(c) {}
    string getNombre() { return nombre; }
    string getContacto() { return contacto; }
};


class Producto {
private:
    string codigo;
    string descripcion;
    double precio;
    Proveedor* proveedor;  
public:
    Producto(string cod, string desc, double prec, Proveedor* prov)
        : codigo(cod), descripcion(desc), precio(prec), proveedor(prov) {}
    
    string getCodigo() { return codigo; }
    string getDescripcion() { return descripcion; }
    double getPrecio() { return precio; }
    Proveedor* getProveedor() { return proveedor; }
    
    void setPrecio(double nuevoPrecio) { precio = nuevoPrecio; }
};


class Pago {
private:
    string metodo;
    double monto;
    string fecha;
public:
    Pago(string met, double mon, string fec)
        : metodo(met), monto(mon), fecha(fec) {}
    
    string getMetodo() { return metodo; }
    double getMonto() { return monto; }
    string getFecha() { return fecha; }
};

// Clase Cliente
class Cliente {
private:
    string nombre;
    string direccion;
    string telefono;
    vector<Pago*> pagos; 
public:
    Cliente(string nom, string dir, string tel)
        : nombre(nom), direccion(dir), telefono(tel) {}
    
    void agregarPago(Pago* pago) {
        pagos.push_back(pago);
    }
    
    void mostrarHistorialPagos() {
        cout << "Historial de pagos de " << nombre << ":\n";
        for (auto pago : pagos) {
            cout << "- " << pago->getFecha() << ": " 
                 << pago->getMonto() << " (" << pago->getMetodo() << ")\n";
        }
    }
    
    string getNombre() { return nombre; }
    string getInfo() {
        return nombre + " - " + direccion + " - Tel: " + telefono;
    }
};


class Venta {
private:
    string numeroFactura;
    string fecha;
    Cliente* cliente; 
    vector<Producto*> productos; 
    vector<int> cantidades;
public:
    Venta(string numFac, string fec, Cliente* cli)
        : numeroFactura(numFac), fecha(fec), cliente(cli) {}
    
    void agregarProducto(Producto* prod, int cantidad) {
        productos.push_back(prod);
        cantidades.push_back(cantidad);
    }
    
    double calcularTotal() {
        double total = 0;
        for (int i = 0; i < productos.size(); i++) {
            total += productos[i]->getPrecio() * cantidades[i];
        }
        return total;
    }
    
    void mostrarDetalle() {
        cout << "Factura #" << numeroFactura << " - " << fecha << "\n";
        cout << "Cliente: " << cliente->getInfo() << "\n";
        cout << "Productos:\n";
        
        for (int i = 0; i < productos.size(); i++) {
            cout << cantidades[i] << "x " 
                 << productos[i]->getDescripcion() 
                 << " (" << productos[i]->getCodigo() << ") - "
                 << productos[i]->getPrecio() << " c/u\n";
        }
        
        cout << "TOTAL: " << calcularTotal() << "\n";
    }
    
    string getNumeroFactura() { return numeroFactura; }
};

int main() {
    vector<Proveedor*> proveedores;
    vector<Producto*> productos;
    vector<Cliente*> clientes;
    vector<Venta*> ventas;
    
    int opc = -1;
    while (opc != 0) {
        cout << "\n SISTEMA DE TIENDA DE ROPA \n";
        cout << "1. Registrar Proveedor\n";
        cout << "2. Registrar Producto\n";
        cout << "3. Registrar Cliente\n";
        cout << "4. Crear Venta\n";
        cout << "5. Registrar Pago\n";
        cout << "6. Mostrar Reportes\n";
        cout << "0. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opc;
        cin.ignore(); // Limpiar buffer
        
        switch(opc) {
            case 1: {
                string nombre, contacto;
                cout << "Nombre del proveedor: ";
                getline(cin, nombre);
                cout << "Contacto del proveedor: ";
                getline(cin, contacto);
                
                proveedores.push_back(new Proveedor(nombre, contacto));
                cout << "Proveedor registrado con exito!\n";
                break;
            }
            
            case 2: {
                if (proveedores.empty()) {
                    cout << "Primero debe registrar al menos un proveedor.\n";
                    break;
                }
                
                cout << "Proveedores disponibles:\n";
                for (int i = 0; i < proveedores.size(); i++) {
                    cout << i+1 << ". " << proveedores[i]->getNombre() << "\n";
                }
                
                int seleccion;
                cout << "Seleccione el proveedor: ";
                cin >> seleccion;
                cin.ignore();
                
                if (seleccion < 1 || seleccion > proveedores.size()) {
                    cout << "Seleccion invalida.\n";
                    break;
                }
                
                string codigo, descripcion;
                double precio;
                
                cout << "Codigo del producto: ";
                getline(cin, codigo);
                cout << "Descripcion: ";
                getline(cin, descripcion);
                cout << "Precio: ";
                cin >> precio;
                cin.ignore();
                
                productos.push_back(new Producto(codigo, descripcion, precio, proveedores[seleccion-1]));
                cout << "Producto registrado con exito!\n";
                break;
            }
            
            case 3: {
                string nombre, direccion, telefono;
                cout << "Nombre del cliente: ";
                getline(cin, nombre);
                cout << "Direccion: ";
                getline(cin, direccion);
                cout << "Telefono: ";
                getline(cin, telefono);
                
                clientes.push_back(new Cliente(nombre, direccion, telefono));
                cout << "Cliente registrado con exito!\n";
                break;
            }
            
            case 4: {
                if (clientes.empty() || productos.empty()) {
                    cout << "Debe haber al menos un cliente y un producto registrado.\n";
                    break;
                }
                
               
                cout << "Clientes disponibles:\n";
                for (int i = 0; i < clientes.size(); i++) {
                    cout << i+1 << ". " << clientes[i]->getNombre() << "\n";
                }
                int clienteSel;
                cout << "Seleccione el cliente: ";
                cin >> clienteSel;
                cin.ignore();
                
                if (clienteSel < 1 || clienteSel > clientes.size()) {
                    cout << "Seleccion invalida.\n";
                    break;
                }
                
               
                string numFactura = "FAC-" + to_string(ventas.size() + 1000);
                string fecha = "2023-11-15"; // Fecha fija por simplicidad
                Venta* nuevaVenta = new Venta(numFactura, fecha, clientes[clienteSel-1]);
                
               
                char continuar;
                do {
                    cout << "Productos disponibles:\n";
                    for (int i = 0; i < productos.size(); i++) {
                        cout << i+1 << ". " << productos[i]->getDescripcion() 
                             << " - $" << productos[i]->getPrecio() << "\n";
                    }
                    
                    int prodSel, cantidad;
                    cout << "Seleccione el producto: ";
                    cin >> prodSel;
                    cout << "Cantidad: ";
                    cin >> cantidad;
                    cin.ignore();
                    
                    if (prodSel >= 1 && prodSel <= productos.size() && cantidad > 0) {
                        nuevaVenta->agregarProducto(productos[prodSel-1], cantidad);
                    } else {
                        cout << "Seleccion invalida.\n";
                    }
                    
                    cout << "Desea agregar otro producto? (s/n): ";
                    cin >> continuar;
                    cin.ignore();
                } while (continuar == 's' || continuar == 'S');
                
                ventas.push_back(nuevaVenta);
                cout << "Venta registrada con exito!\n";
                nuevaVenta->mostrarDetalle();
                break;
            }
            
            case 5: {
                if (clientes.empty()) {
                    cout << "No hay clientes registrados.\n";
                    break;
                }
                
                cout << "Clientes disponibles:\n";
                for (int i = 0; i < clientes.size(); i++) {
                    cout << i+1 << ". " << clientes[i]->getNombre() << "\n";
                }
                
                int clienteSel;
                cout << "Seleccione el cliente: ";
                cin >> clienteSel;
                cin.ignore();
                
                if (clienteSel < 1 || clienteSel > clientes.size()) {
                    cout << "Seleccion invalida.\n";
                    break;
                }
                
                string metodo, fecha = "2023-11-15"; // Fecha fija por simplicidad
                double monto;
                
                cout << "Metodo de pago: ";
                getline(cin, metodo);
                cout << "Monto: ";
                cin >> monto;
                cin.ignore();
                
                clientes[clienteSel-1]->agregarPago(new Pago(metodo, monto, fecha));
                cout << "Pago registrado con exito!\n";
                break;
            }
            
            case 6: {
                cout << "\n REPORTES \n";
                
                cout << "\nProveedores (" << proveedores.size() << "):\n";
                for (auto prov : proveedores) {
                    cout << "- " << prov->getNombre() << " (" << prov->getContacto() << ")\n";
                }
                
                cout << "\nProductos (" << productos.size() << "):\n";
                for (auto prod : productos) {
                    cout << "- " << prod->getDescripcion() << " (" << prod->getCodigo() 
                         << ") - $" << prod->getPrecio() 
                         << " - Prov: " << prod->getProveedor()->getNombre() << "\n";
                }
                
                cout << "\nClientes (" << clientes.size() << "):\n";
                for (auto cli : clientes) {
                    cout << "- " << cli->getInfo() << "\n";
                    cli->mostrarHistorialPagos();
                }
                
                cout << "\nVentas (" << ventas.size() << "):\n";
                for (auto venta : ventas) {
                    venta->mostrarDetalle();
                    cout << "----------------\n";
                }
                break;
            }
            
            case 0:
                cout << "Saliendo del sistema...\n";
                break;
                
            default:
                cout << "Opcion no valida. Intente nuevamente.\n";
        }
    }
    
   
    return 0;
}