#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

#include <cereal/archives/binary.hpp>
#include <cereal/types/string.hpp>
#include <cereal/types/int.hpp>


class Persona {
    private:
    string nombre;
    int edad;
    string direccion;

    public:

    Persona() : nombre("NA"), edad(0), direccion("NR") {}

    Persona(string nom ,int ed ,string direc ) : nombre(nom),edad(ed),direccion(direc){}


    string getNombre()const {return nombre; }
    int getEdad()const {return edad; }
    string getDireccion()const {return direccion; }

    void setNombre(string NuvNombre){
        cout << "El nuevo nombre es =>"<< NuvNombre << endl;
        nombre = NuvNombre;
    }
    void setEdad(int NuvEdad ){
        cout << "La nueva edad es =>"<<NuvEdad << endl;
        edad = NuvEdad;
    }
    void setDireccion(string NuvDireccion ){
        cout << "La nueva direccion es =>"<< NuvDireccion << endl;
        direccion = NuvDireccion;
    }

    template <class Archive>
    void serialize(Archive& archive){
        archive(nombre,edad,direccion);
    }


    void mostrarInfo() const {
        cout << "Nombre "<< nombre << endl;
        cout << "Edad " << edad << endl;
        cout << "Direccion "<< direccion << endl;
    }
};

int main() {
    Persona persona1("Ricardo",20,"Siempre viva 123");

    cout << "Objeto orig"<<endl;
    persona1.mostrarInfo();
    cout << endl ;

    {
        ofstream os("persona.bin", ios::binary);

        if (!os.is_open()) {
            cout << "No se pudo abrir 'persona.bin' para escritura." << endl;
        cereal::BinaryOutputArchive archivo(os);

        archivo(persona1);
    }

    Persona perDeserealizada;
    {
        ifstream is ("persona.bin", ios::binary);

        if (!is.is_open()){
            cout << "no se encontro / abrio el archivo" << endl;

        }
        cereal::BinaryInputArchive archivo(is);

        cout << "Deserializando el objeto Persona ""persona.bin""" << endl;
        archivo(perDeserealizada);
    }

    cout << "Persona deserealizada normal ._." << endl;
    perDeserealizada.mostrarInfo();

    return 0;
}