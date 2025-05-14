#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

class Cliente {
protected:
    string Nombre;
    int DNI;
    double Saldo;
    vector<string> historialTransacciones;
    
    string protegerDato(string dato) {
        string copia = dato;
        reverse(copia.begin(), copia.end());
        return copia;
    }

public:

    Cliente(string nom, int dni, double sald) : Nombre(nom), DNI(dni), Saldo(sald) {
        cout << "Cliente registrado" << endl;
    }

    ~Cliente() {
        cout << "Recursos de Cliente liberados" << endl;
    }

    void infGeneral() {
        cout << "Nombre: " << Nombre << endl;
        cout << "DNI: " << DNI << endl;
        cout << "Saldo: " << Saldo << endl;
    }
    
    void agregarTransaccion(string transaccion) {
        historialTransacciones.push_back(protegerDato(transaccion));
    }
};

// herencia publica requi g
class ClientePublico : public Cliente {
public:
    ClientePublico(string nom, int dni, double sald) : Cliente(nom, dni, sald) {}
    
    void mostrarInfoPublica() {
        cout << "Informacion publica del cliente:" << endl;
        infGeneral(); // puede acceder a metodos publicos de la base
    }
};

// herencia protegida h
class ClienteSeguro : protected Cliente {
private:
    string claveEncriptada;
    
public:
    ClienteSeguro(string clv, string nom, int dni, double sald) 
        : Cliente(nom, dni, sald) {
        claveEncriptada = protegerDato(clv);
    }
    
    // Destructor req f
    ~ClienteSeguro() {
        cout << "Recursos de ClienteSeguro liberados" << endl;
    }
    
    void verificarAutenticidad(string contrasena) {
        if (claveEncriptada == protegerDato(contrasena)) {
            cout << "Autenticacion exitosa" << endl;
        } else {
            cout << "Autenticacion fallida" << endl;
        }
    }
    
    void mostrarInfoSegura() {
        cout << "Informacion segura del cliente:" << endl;
        infGeneral(); // puede acceder porque es herencia protegida
    }
};

// herencia privada requiere i
class ClientePrivado : private Cliente {
private:
    string tokenAcceso;
    
public:
    ClientePrivado(string tok, string nom, int dni, double sald) 
        : Cliente(nom, dni, sald), tokenAcceso(tok) {}
    
    ~ClientePrivado() {
        cout << "Recursos de ClientePrivado liberados" << endl;
    }
    
    void accesoRestringido() {
        cout << "Acceso con token: " << tokenAcceso << endl;
    }
};

int main() {
    //herencia publica
    ClientePublico publico("Ana", 987654321, 5000.0);
    publico.mostrarInfoPublica();
    
    cout << "----------------------------" << endl;
    
    // protegida
    ClienteSeguro seguro("clave123", "Juan", 123456789, 10000.0);
    seguro.mostrarInfoSegura();
    seguro.verificarAutenticidad("clave123");
    seguro.verificarAutenticidad("incorrecta");
    
    cout << "----------------------------" << endl;
    
    //privada
    ClientePrivado privado("tokenXYZ", "Carlos", 555555555, 7500.0);
    privado.accesoRestringido();
    
    return 0;
}