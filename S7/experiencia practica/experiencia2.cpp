#include <iostream>
#include <string>
#include <algorithm>//para usar el reverse

using namespace std;


class Cliente{
protected:
    string Nombre;
    int DNI;
    int Saldo;
    
    //encriptacion invirtiendo el texto que se usa
    string protegerClave(string clave){
        string copiaClv = clave;
        reverse(copiaClv.begin(),copiaClv.end());
        return copiaClv;
    }

public:
    Cliente(string nom , int dni , int sald):
    Nombre(nom),DNI(dni),Saldo(sald){
    cout << "usuario registrado" << endl;
    }

    void infGeneral(){
        cout << "Nombre  " << Nombre <<endl;
        cout << "Nombre  " << DNI <<endl;
        cout << "Saldo =>" << Saldo <<endl;
    }

};///final

class ClienteSeguro : protected Cliente {
private:
    string claveUsuario;

public://claveUsuario,Nombre(nom),DNI(dni),Saldo(sald)
ClienteSeguro(string clv,string nom , int dni ,int sald):
Cliente(nom,dni,sald){
    claveUsuario = protegerClave(clv);
}

void verificar(string contrasenaing){
    if (claveUsuario == protegerClave(contrasenaing)){
        cout << "cuenta validada" << endl;
    }
    else{
        cout << "contraseña incorrecta" << endl;
    }
}

void mostrarInfoUser(){
    infGeneral();
    cout << "clave encriptada"<< endl;
}
};



int main(){//claveUsuario,Nombre,DNI,Saldo
    ClienteSeguro usuario1("LuzDeNoche","Samuel",123456789,12000000);
    usuario1.mostrarInfoUser();
    usuario1.verificar("pan con queso");
    cout << "----------------------------"<<endl;
    usuario1.verificar("LuzDeNoche");

}