#include <iostream>
#include <string>
using namespace std;


class Habitacion {
private:
    int numero;
    string tipo;
    double precioPorNoche;
public:
    Habitacion() : numero(0), tipo(""), precioPorNoche(0.0) {}

    Habitacion(int _numero, string _tipo, double _precio)
        : numero(_numero), tipo(_tipo), precioPorNoche(_precio) {
    }

    double getPrecioPorNoche() const {
        return precioPorNoche;
    }

    void mostrar() const {
        cout << "Habitacion " << numero << " - Tipo: " << tipo << ", Precio por noche: $" << precioPorNoche << endl;
    }
};


class ReservaHotel {
private:
    Habitacion* habitaciones; 
    int cantidad;
public:

    ReservaHotel(int _cantidad) : cantidad(_cantidad) {
        habitaciones = new Habitacion[cantidad];
      
        for (int i = 0; i < cantidad; ++i) {
            habitaciones[i] = Habitacion(100 + i, "Estándar", 80 + 20 * i);
        }
    }


    ~ReservaHotel() {
        delete[] habitaciones;
    }

    double calcularTotalPorNoche() const {
        double total = 0.0;
        for (int i = 0; i < cantidad; ++i) {
            total += habitaciones[i].getPrecioPorNoche();
        }
        return total;
    }

    void mostrarHabitaciones() const {
        for (int i = 0; i < cantidad; ++i) {
            habitaciones[i].mostrar();
        }
    }
};

int main() {
    ReservaHotel reserva(3);

    cout << "Habitaciones" << endl;
    reserva.mostrarHabitaciones();

    cout << "\nTotal por noche para todas las habitaciones: $" << reserva.calcularTotalPorNoche() << endl;

    return 0;
}