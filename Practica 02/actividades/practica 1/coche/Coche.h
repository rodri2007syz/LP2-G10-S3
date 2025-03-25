#include <iostream>
#include <string>
using namespace std;

class Coche{
    private:
    string modelo;
    int anio;
    int velocidad;
    
    public:
    Coche (string mod , int an )
    :modelo(mod),
    anio(an),
    velocidad(0){
    }
    
    void acelerar(int aumento){
        velocidad = velocidad + aumento;
        cout << "El veiculo " << modelo << " del año "<< anio << " esta acelerando a " << velocidad << "km/h" << endl;
    }
    
    void frenar(int disminuir){
        if (velocidad >= 0 ){
            velocidad = velocidad - disminuir;
            
        }
        else{
            velocidad = 0;
            
        }
         cout << "El veiculo " << modelo << " del año "<< anio << " esta desaselerando , su velocidad actual es de " << velocidad << "km/h" << endl;
    }
    
    void informacionVi(){
        cout << "INFORMACION DEL VEICULO" << endl;
        cout << "-----------------------" << endl;
        cout << "Modelo : " <<  modelo << endl;
        cout << "Año : " << anio << endl;
        cout << "velocidad actual :" << velocidad <<endl;
        cout << "-----------------------" << endl;
    }
};