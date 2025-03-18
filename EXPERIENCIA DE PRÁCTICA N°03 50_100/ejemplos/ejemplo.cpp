#include <iostream>
#include <stdlib.h>
using namespace std;


class Punto{
    private://atributos
    int x;
    int y;

    public: //metodos
        Punto();//constructor
        void setPunto(int,int);//establecer valores
        int getPuntoX();//obtener valores
        int getPuntoY();

};

Punto::Punto(){
}


void Punto::setPunto(int _x,int _y){
    x= _x;
    y = _y;
}
int Punto::getPuntoX(){
    return x;
}
int Punto::getPuntoY(){
    return y;
}


int main(){
    Punto punto1;
    punto1.setPunto(10,20);
    cout<<punto1.getPuntoX()<<endl;
    cout<<punto1.getPuntoY()<<endl;


}