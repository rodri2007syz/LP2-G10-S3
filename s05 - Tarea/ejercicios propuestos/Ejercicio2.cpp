
#include <iostream>
#include <string>
using namespace std;


class FechaRegistro {// mienbro del cliente
    private:
    int dia,mes,anio;
    public:
    FechaRegistro(int d,int m , int a):
    dia(d),mes(m),anio(a){
        cout << "se registro correctamente"<< endl;
    }
    void inforegistro(){
        cout << dia <<"/" << mes <<"/" << anio << endl;
    }
};
class Direccion{ // mienbro del cliente z
    private:
    string DireccionVi;
    public:
    Direccion(string Di):
    DireccionVi(Di){
        cout << "registro de direccion aceptado";
    }

    void infDireccion(){
        cout << "Direccion -> " << DireccionVi << endl;
    }
};

class cliente{
    private:
    string Nombre, apellido;
    int edad , dni;
    FechaRegistro FechaRegistros;
    Direccion Direccions;
    public:
    cliente(string n , string ap , int e , int dn , int d,int m , int a,string Di):
    Nombre(n) , apellido(ap) ,edad(e) , dni (dn), FechaRegistros(d,m,a),Direccions(Di){
        cout << "se registro correctamente al cliente " << Nombre << endl;
    }

    void infoCliente(){
        cout << "Fecha de registro "<<endl;
        FechaRegistros.inforegistro();
        cout << "Nombre -> " << Nombre << endl;
        cout << "Apellido -> " << apellido << endl;
        cout << "Edad -> " << edad << endl;
        cout << "DNI ->" << dni << endl;
        Direccions.infDireccion();
    }
};

int main(){// nombe-apellido-edad-dni-dia-mes-año-direccion
    cliente persona1("Pedro","Garcia",23,1234567, 29,10,2025,"las petunias");
    persona1.infoCliente();
}
