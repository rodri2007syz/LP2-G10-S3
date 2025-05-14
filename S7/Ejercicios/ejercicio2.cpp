#include <iostream>
#include <string>
using namespace std;


class Persona {
protected:
    string nombre;
    int edad;
    double salario;
    string email; // protected

public:
    Persona(string n, int e, double s, string em) 
        : nombre(n), edad(e), salario(s), email(em) {}

    virtual void mostrarDatos() const {
        cout << "Nombre: " << nombre << endl;
        cout << "Edad: " << edad << endl;
        cout << "Salario: $" << salario << endl;
        // Email no se muestra por defecto esta protegid
    }

    virtual ~Persona() {}
};

class Empleado : public Persona {
private:
    string puesto;
    string departamento;

public:
    Empleado(string n, int e, double s, string em, string p, string d)
        : Persona(n, e, s, em), puesto(p), departamento(d) {}

    void mostrarDatos() const override {
        Persona::mostrarDatos();
        cout << "Puesto: " << puesto << endl;
        cout << "Departamento: " << departamento << endl;
        cout << "Email corporativo: " << email << endl; // Acceso al email protegido
    }
};

class Cliente : public Persona {
private:
    string categoria;
    double descuento;

public:
    Cliente(string n, int e, double s, string em, string cat, double desc)
        : Persona(n, e, s, em), categoria(cat), descuento(desc) {}

    void mostrarDatos() const override {
        Persona::mostrarDatos();
        cout << "Categoría: " << categoria << endl;
        cout << "Descuento: " << descuento << "%" << endl;
        cout << "Email de contacto: " << email << endl; // Acceso al email protegido
    }
};



int main(){
    Empleado emp1("Juan Pérez", 35, 45000.0, "juan@empresa.com", "Desarrollador", "TI");
    Cliente cli1("María García", 28, 0.0, "maria@cliente.com", "Premium", 15.0);

    cout << "\nDatos del Empleado:" << endl;
    emp1.mostrarDatos();

    cout << "\nDatos del Cliente:" << endl;
    cli1.mostrarDatos();

}