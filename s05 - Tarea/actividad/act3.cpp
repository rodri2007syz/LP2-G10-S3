#include <iostream>
using namespace std;
class Fecha {
private:
	int dia, mes, anio;
public:
	Fecha(int d, int m, int a) : dia(d), mes(m), anio(a) {}
	
	void mostrar() const {
		cout << dia << "/" << mes << "/" << anio << endl;
	}
};
class Contrato {
private:
	int cod;
	string desc;
	Fecha fechainicio;
public:
	Contrato(int _cod, string _desc, Fecha _fechainicio)
		: cod(_cod), desc(_desc), fechainicio(_fechainicio) {}

	void mostrarContrato() const {
		cout << "Codigo: " << cod << " Descripcion: " << desc << " Fecha de inicio: ";
		fechainicio.mostrar();
		cout << endl;

	}
};
class Empleado {
private:
	string nombre;
	Contrato cont;
public:
	Empleado(string _nombre, Contrato _cont)
		: nombre(_nombre),cont(_cont) {}
	void mostrarEmpleado() const {
		cout << "Empleado: " << nombre << endl;
		cont.mostrarContrato();
	}
};
int main() {
	Fecha fechaInicio(1, 5, 2025);
	Contrato contrato(101, "Contrato indefinido", fechaInicio);
	Empleado empleado("Carlos Gómez", contrato);

	empleado.mostrarEmpleado();

	return 0;
