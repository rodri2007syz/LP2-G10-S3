#include <iostream>
#include <string>

using namespace std;

class Dispositivo{
private:
    string marca;
    string modelo;
    int anioFabricacion;

public:
    // Constructor predeterminado (como lo tenías)
    Dispositivo(){
        marca = "NA";
        modelo = "NA";
        anioFabricacion = 0;
        cout << "Se creó el dispositivo con valores por defecto" << endl;
    }

    // Constructor con 1 parametro
    Dispositivo(string m){
        marca = m;
        modelo = "NA";
        anioFabricacion = 0;
        cout << "Se creo el dispositivo con 1 parametro" << endl;
    }

    // Constructor con 2 parametros
    Dispositivo(string m, string mod){
        marca = m;
        modelo = mod;
        anioFabricacion = 0;
        cout << "Se creo el dispositivo con 2 parametros" << endl;
    }

    // Constructor con 3 parametros
    Dispositivo(string m, string mod, int anio){
        marca = m;
        modelo = mod;
        anioFabricacion = anio;
        cout << "Se creo el dispositivo con 3 parametros" << endl;
    }

    // Constructor de copia (añadido como lo pediste)
    Dispositivo(const Dispositivo& otro){
        marca = otro.marca;
        modelo = otro.modelo;
        anioFabricacion = otro.anioFabricacion;
        cout << "Se creo una copia del dispositivo " << modelo << endl;
    }

    // Método mostrar
    void mostrar(){
        cout << "Modelo: " << modelo << endl;
        cout << "Marca: " << marca << endl;
        cout << "Año de fabricación: " << anioFabricacion << endl;
    }

    // Destructor
    ~Dispositivo(){
        cout << "Se eliminó el modelo " << modelo << endl;
    }
};

int main(){
    
    Dispositivo audifonosNOF;
    Dispositivo celular("Huawei","z11G");
    Dispositivo PS2("Sony","PS2",2005);

    audifonosNOF.mostrar();
    cout << "-----------------"<< endl;
    celular.mostrar();
    cout << "-----------------"<< endl;
    PS2.mostrar();
    cout << "-----------------"<< endl;


    Dispositivo copia1(PS2);
    Dispositivo copia2 = PS2;
    Dispositivo dispositivos[] = {PS2, Dispositivo("Microsoft", "Xbox", 2020)};
    
    // Mostrar PS2
    PS2.mostrar();
    
    return 0;
}