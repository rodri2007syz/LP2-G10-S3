
#include <string>
#include <iostream>
using namespace std;

class Movil{
    private:
    string marca;
    string modelo;
    string sistemaOperativo;


    public:
    Movil(string mar,string mod,string sis):
    marca(mar),modelo(mod),sistemaOperativo(sis){
        cout << "El modelo " << modelo << "del la marca " << marca << "del sistema operativo se creo correctamente "<< endl;
    }

    void infomovil(){
        cout << "Marca: " << marca << endl;
        cout << "Modelo: " << modelo << endl;
        cout << "Sistema Operativo: " << sistemaOperativo << endl;
    }


    ~Movil(){
        cout << "Se elimino el modelo " << modelo << endl;
    }

};

class  Telefono : private Movil {
    private:
    int numero;
    string tipoRed;

    public:
    Telefono(int num,string red , string mar,string mod,string sis):
    numero(num),tipoRed(red),Movil(mar,mod,sis){}

    void infoTelf(){
        infomovil();
        cout << "Numero " << numero << endl;
        cout << "Tipo de red que capta el dispositivo " << tipoRed << endl;
    }

    ~Telefono(){
        cout << "Se elimino el telefono corectamente "<<endl;
    }
};

class  Tablet : public Movil {
    private:
    int tamanio;
    bool PermiteLlamadas;

    public:
    Tablet(int tam , bool call , string mar,string mod,string sis):
    tamanio(tam),PermiteLlamadas(call),Movil(mar,mod,sis){
        cout <<"La tablet se creo correctamente "<< endl;
    }
        void infoTablet(){
        cout << "Tamaño " << tamanio <<"pulgadas"<< endl;
        cout << "este dispositivo " << PermiteLlamadas << "permite las llamadas"<<endl;
    }

    ~Tablet(){
        cout << "se elimino la table ingresada "<< endl;
    }
};

int main() {
    // telefono
    Telefono t1(987654321, "4G", "Samsung", "Galaxy S21", "Android");
    t1.infoTelf();

    cout << "-------------------------" << endl;

    // tablet
    Tablet t2(10, true, "Apple", "iPad", "iPadOS");
    t2.infoTablet();

    return 0;