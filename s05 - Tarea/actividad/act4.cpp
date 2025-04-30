#include <iostream>
#include <string>
using namespace std;

class ComponenteA{
private:
    int Id;
    string Usuario;
public:
    ComponenteA (int i , string u){
        Id = i;
        Usuario = u;
        cout << "Componente a se creo correctamente" << endl;
    }

    void infoUser(){
        cout << "Usuario "<< Usuario << endl;
        cout << "ID " << Id << endl;
    }

    ~ComponenteA() {
        cout <<  "Se elimino correctamente a " << Usuario << endl;
    }


};


class ComponenteB
{
private:
    string Nombre;
    int Dni;
public:
    ComponenteB(string n , int d){
        Nombre= n;
        Dni = d;
        cout << "se creo correctamente el componente b de " << Nombre << endl;
    }

    void infoPer(){
        cout << "Nombre "<< Nombre << endl;
        cout << "DNI " << Dni << endl;
    }

    ~ComponenteB() {
        cout <<  "Se elimino correctamente a " << Nombre << endl;
    }
};



class Sistema
{
private:
    string fecha;
    ComponenteA ComponenteAin;
    ComponenteB ComponenteBin;

public:
    Sistema(string f,int I , string U , string N , int D ):
    fecha(f), ComponenteAin(I , U) , ComponenteBin(N,D){
        cout << "se creo al cliente correctamente" << endl;
    }

    void infoCliente(){
        cout << "Fecha "<< fecha << endl;
        ComponenteAin.infoUser();
        ComponenteBin.infoPer();
    }
};


int main() {
    Sistema cliente1("2025-04-28", 101, "usuario01", "nombre01", 12345678);

    cout << endl << "Información del cliente:" << endl;
    cliente1.infoCliente();

    cout << "\nPrograma finalizado." << endl;
    return 0;
}