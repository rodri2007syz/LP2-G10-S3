#include <iostream>
#include <string>

using namespace std;

class Figura{
    public:
    virtual float calcularArea() = 0;

    virtual ~Figura() {}
};

class Circulo: public Figura{
    private:
    float radio;

    public:
    Circulo(float  rad):
    radio(rad){}

    float calcularArea() override{
        return 3.14159 * (radio * radio);
    }

};
class Rectangulo: public Figura{
    private:
    float largo;
    float ancho;

    public:
    Rectangulo(float lar,float anc):
    largo(lar),ancho(anc){}

    float calcularArea() override{
        return largo * ancho;
    }

};
class Triangulo: public Figura{

        private:
    float largo;
    float ancho;

    public:
    Triangulo(float lar,float anc):
    largo(lar),ancho(anc){}

    float calcularArea() override{
        return (largo * ancho)/2;
    }
};
class Cuadrado: public Figura{
    private:
    float lado;
    public:
    Cuadrado(float cua):lado(cua){}

    float calcularArea(){
        return lado * lado;
    }
};
class Pentagono: public Figura{
    private:
    float largo;
    float apotema;
    float Perimetro;

    public:
    Pentagono(float lar,float apo):
    largo(lar),apotema(apo){}

    float calcularArea()override{
    Perimetro= 5 * largo;
    return  (Perimetro* apotema)/2 ;

    }
};


int main(){
int opciones;
Figura* mifig;

cout <<" Elija que area desea calcular"<< endl ;
cout <<" 1 => Circulo"<< endl ;
cout <<" 2 => Recangulo" << endl ;
cout <<" 3 => triangulo"<< endl ;
cout <<" 4 => Cuadrado"<< endl ;
cout <<" 5 => Pentagono"<< endl ;
cout <<" salir cualquier otro numero"<< endl ;

cout << "=>" ; cin >> opciones;

switch (opciones)
{
case 1:{
float radio;
cout << "radio => \n"; cin >> radio ;
mifig = new Circulo(radio);
cout << "El area de la figura es: " << mifig->calcularArea() << endl;
break;
}
case 2:{
float largo;
float ancho;

cout << "largo=> \n";cin >> largo;
cout << "ancho=> \n"; cin >> ancho;
mifig = new Rectangulo(largo,ancho);
cout << "El area de la figura es: " << mifig->calcularArea() << endl;
break;
}
case 3:{
float largo;
float ancho;

cout <<"largo=> \n";cin >> largo;
cout <<"ancho=> \n";cin >> ancho;
mifig = new Triangulo(largo,ancho);
cout << "El area de la figura es: " << mifig->calcularArea() << endl;
break;

}
case 4:{
float lado;
cout << "lado => \n"; cin >> lado ;
mifig = new Cuadrado(lado);
cout << "El area de la figura es: " << mifig->calcularArea() << endl;
break;

}
case 5:{
float largo;
float apotema;
cout << "Largo => \n"; cin >> largo ;
cout << "Apotema => \n"; cin >> apotema ;

mifig = new Pentagono(largo,apotema);
cout << "El area del Pentagono es: " << mifig->calcularArea() << endl;
break;
}
}

delete mifig;
}