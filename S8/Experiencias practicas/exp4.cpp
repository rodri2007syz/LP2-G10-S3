#include <iostream>
#include <string>

using namespace std;

class Vehiculo{
    public:
    virtual void acelerar(){
        cout << "Acelerando el vehículo" << endl;
    }

    virtual void luces(){
        cout << "se encendieron las luces"<<endl;
    }
};

class Coche : public Vehiculo{
    public:
    void acelerar()override{
        cout << "Acelerando el coche" << endl;
    }

    void encenderLuces(){
        cout <<"Luces del coche encendidas" << endl;
    }

};

class Motocicleta: public Vehiculo{
    public:
    void acelerar()override{
        cout << "Acelerando la motocicleta" << endl;
    }
    virtual void luces()override{
        Vehiculo::luces();
            cout << "delanteras" <<endl;

    }
};


int main(){
    Coche micoche;
    Motocicleta mimoto;
    micoche.acelerar();
    micoche.encenderLuces();
    mimoto.acelerar();
    mimoto.luces();


}

