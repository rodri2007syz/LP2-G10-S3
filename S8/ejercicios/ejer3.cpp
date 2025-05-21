#include <iostream>
using namespace std;

class Empleado{
    protected:
    string nombre;
    double salario;
    
    public:
    Empleado(const string& nombre, double salario_)
    : nombre(nombre), salario(salario_) {}
    
    virtual double calcularSalario() const = 0;
    
    string getNombre() const { return nombre; }
};

class EmpleadoTiempoCompleto : public Empleado{
    private:
    double bonoanual;
    public:
    EmpleadoTiempoCompleto(const string& nombre, double salario , double bonoanual_)
    : Empleado(nombre, salario) , bonoanual(bonoanual_) {}
    
    double calcularSalario() const override{
        return salario + bonoanual ;
    }
    
};

class EmpleadoMedioTiempo : public Empleado{
    private: 
    int ndh;
    double pxh;
    public:
    EmpleadoMedioTiempo(const string& nombre, int ndh_ , double pxh_)
    : Empleado(nombre, salario) , ndh(ndh_), pxh(pxh_) {}
    
    double calcularSalario() const override{
        return ndh*pxh;
    }
};

void imprimirSueldo(const Empleado& emp) {
    cout << "Sueldo de " << emp.getNombre() << ": $" << emp.calcularSalario() << endl;
}

int main()
{
    EmpleadoTiempoCompleto emp1("Juan Perez", 5000, 3000);
    EmpleadoMedioTiempo emp2("Maria Gomez", 80, 25.0);
    
   
    imprimirSueldo(emp1);
    imprimirSueldo(emp2);
  return 0;
}