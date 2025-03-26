#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
class Auto {
private:
	int velocidad, distanciareco;
	string nombre;
public:
	Auto(string _nombre ) {
		nombre = _nombre;
		velocidad = 0;
		distanciareco = 0;
		
	}
	string getnombre() { // Retornan el atributo que deseee ejmp : si le damos un valor a la variable (nombre="rodrigo") auto1.getnombre = "rodrigo"
		return nombre;
	}
	int getvelocidad() {
		return velocidad;
	}
	int getdistancia() {
		return distanciareco;
	}
	void setnombre(string _nombre) {
		nombre = _nombre;
	}
	void setvelocidad(int _velocidad) {
		velocidad = _velocidad;
	}
	
	void setdistancia(int _distanciareco) {
		distanciareco = _distanciareco;
	}
	void avanzar() { 
		distanciareco += velocidad;
	}
	void reinicio(int distanciareco, int velocidad) {
		distanciareco = 0;
		velocidad = 0;
		
	}
};
class Carrera {
private:
	int distanciaCarrera;
	string ganador;

public:
	Carrera(int _distanciaCarrera) { 
		distanciaCarrera = _distanciaCarrera; 
	}

	void iniciarCarrera(Auto& jugador, Auto& computadora) {
		 
		while (jugador.getdistancia() < distanciaCarrera && computadora.getdistancia() < distanciaCarrera) {
			jugador.avanzar();
			computadora.avanzar();
			cout << jugador.getnombre() << " avanzo a " << jugador.getdistancia() << " metros.\n";
			cout << "Computadora avanzo a " << computadora.getdistancia() << " metros.\n\n";
		}

		if (jugador.getdistancia() >= distanciaCarrera && computadora.getdistancia() >= distanciaCarrera) {
			ganador = "Empate";
		}
		else if (jugador.getdistancia() >= distanciaCarrera) {
			ganador = jugador.getnombre();
		}
		else {
			ganador = "CPU";
		}

		cout << "ganador de la carrera: " << ganador << "!\n";
	}

};
class Verificacion {
	
public:
	Verificacion(int num) {

	}
	int validadorvelocidad(int num) {
		if (num < 0) {
			cout << " El numero que ingreso DEBE SER POSITIVO " << endl;
			return num = 0;
		}
		else {
			cout << " numero valido " << endl;
		}
	}
};
