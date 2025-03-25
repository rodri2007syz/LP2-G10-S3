#include <iostream>
using namespace std;
class Carrera {
    private:
    int largocarrera;
    string nombrecorredor;
    public:
    Carrera(int _largocarrera, string _nombrecorredor){
        largocarrera=_largocarrera;
        nombrecorredor=_nombrecorredor;
    }
    string getnombre(){
        return nombrecorredor;
    }
    int getlargocarrera(){
        return largocarrera;
    }
    void setnombre(string _nombrecorredor){
        nombrecorredor=_nombrecorredor;
    }
    void setlargocarrera(int _largocarrera){
        if (_largocarrera>0){
            largocarrera=_largocarrera;    
        }
        else {
            cout << "El numero que ha ingresado no corresponde "<< endl;
        }
    }
    void mostrarinformacion(){
        cout << " INFORMACION DE LA CARRERA: \n NOMBRE: "<< nombrecorredor << "\n LONGITUD DE LA CARRERA : "<< largocarrera <<" Km " << endl; 
    }
    
}; 
class Auto {
    private:
    int vel, pos;
    public:
    Auto(int _vel, int _pos){
        vel=_vel;
        pos=_pos;
    }
    int getvelocidad(){
        return vel;
    }
    int getposicion(){
        return pos;
    }
    void setvelocidad(int _vel){
        vel=_vel;
    }
    void setposicion(int _pos){
        pos=_pos;
    }
};
