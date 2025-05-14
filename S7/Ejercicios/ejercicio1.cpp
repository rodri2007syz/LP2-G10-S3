#include <iostream>
using namespace std;

class Vehiculo{
    private:
    string marca, modelo;
    int anioFabricacion;
    double precio;
    public:
    Vehiculo(string m, string mod, int anio, double p) 
        : marca(m), modelo(mod), anioFabricacion(anio), precio(p) {}

    virtual void mostrarInformacion() const {
        cout << "Marca: " << marca << endl;
        cout << "Modelo: " << modelo << endl;
        cout << "Año: " << anioFabricacion << endl;
        cout << "Precio: $" << precio << endl;
    }

    virtual ~Vehiculo() {}
    
};
class Automovil : public Vehiculo {
private:
    int numPuertas;
    string tipoCombustible;

public:
    Automovil(string m, string mod, int anio, double p, int puertas, string comb)
        : Vehiculo(m, mod, anio, p), numPuertas(puertas), tipoCombustible(comb) {}

    void mostrarInformacion() const override {
        Vehiculo::mostrarInformacion();
        cout << "Número de puertas: " << numPuertas << endl;
        cout << "Tipo de combustible: " << tipoCombustible << endl;
    }
};

class Motocicleta : public Vehiculo {
private:
    int cilindrada; 

public:
    Motocicleta(string m, string mod, int anio, double p, int cil)
        : Vehiculo(m, mod, anio, p), cilindrada(cil) {}

    void mostrarInformacion() const override {
        Vehiculo::mostrarInformacion();
        cout << "Cilindrada: " << cilindrada << "cc" << endl;
    }
};

int main()
{
    Automovil auto1("Toyota", "Corolla", 2022, 25000.0, 4, "Gasolina");
    Motocicleta moto1("Honda", "CBR600", 2021, 12000.0, 600);

    cout << "\nInformación del Automóvil:" << endl;
    auto1.mostrarInformacion();
    
    cout << "\nInformación de la Motocicleta:" << endl;
    moto1.mostrarInformacion();


}