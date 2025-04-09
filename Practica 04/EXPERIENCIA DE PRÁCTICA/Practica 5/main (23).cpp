#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Juguete {
public:
    int id;
    string nombre;
    string tipo;

    // Constructor
    Juguete(int id, string nombre, string tipo)
        : id(id), nombre(nombre), tipo(tipo) {}


    void mostrarInfo() const {
        cout << "ID: " << id << ", Nombre: " << nombre << ", Tipo: " << tipo << endl;
    }
};


class ColeccionJuguetes {
private:
    vector<Juguete*> juguetes; 

public:

    void agregarJuguete(Juguete* juguete) {
        juguetes.push_back(juguete);
    }


    // Metodo para obtener un juguete especifico de la coleccion
    Juguete* obtenerJuguete(int id) {
        for (auto& juguete : juguetes) {
            if (juguete->id == id) {
                return juguete;
            }
        }
        return nullptr;  
    }
};


int main() {
   
    ColeccionJuguetes coleccion;

   
    Juguete* juguete1 = new Juguete(1, "Muneca", "Plastico");
    Juguete* juguete2 = new Juguete(2, "Carrito", "Metal");
    Juguete* juguete3 = new Juguete(3, "Pelota", "Goma");


    coleccion.agregarJuguete(juguete1);
    coleccion.agregarJuguete(juguete2);
    coleccion.agregarJuguete(juguete3);

   
    Juguete* jugueteEncontrado = coleccion.obtenerJuguete(2);
    if (jugueteEncontrado) {
        cout << "Juguete encontrado: ";
        jugueteEncontrado->mostrarInfo();
    } else {
        cout << "Juguete no encontrado." << endl;
    }

    juguete1->tipo = "Madera";
    cout << "Juguete 1 modificado: ";
    juguete1->mostrarInfo();
  


    return 0;
}
