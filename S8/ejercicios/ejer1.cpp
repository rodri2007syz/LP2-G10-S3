#include <string>
#include <iostream>
using namespace std;

class Figura{
    public:
    virtual float CalcularArea()=0;

    virtual void  figuraDibujada(){
        cout <<"usted a dibujado" << endl;
    }

    virtual ~Figura() {}
};

class Circulo: public Figura{
    private:
    float radio;

    public:
    Circulo(float  rad):
    radio(rad){}

    void  figuraDibujada(){
        Figura::figuraDibujada();
        cout <<"un circulo , tiene un radio de " << radio << endl;

    }

    float CalcularArea() override{
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

    void  figuraDibujada(){
        Figura::figuraDibujada();
        cout <<"un rectangulo con las medidas , largo "<< largo << ", ancho " << ancho << endl;
    }

    float CalcularArea() override{
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

    void  figuraDibujada(){
        Figura::figuraDibujada();
        cout <<"un Trialgulo que tiene las medidas , largo "<< largo << ", ancho " << ancho << endl;
    }

    float CalcularArea() override{
        return (largo * ancho)/2;
    }


};

int main(){

    Circulo miCirculo(5.0);
    Rectangulo miRectangulo(10.0, 4.0);
    Triangulo miTriangulo(6.0, 8.0);

    miCirculo.figuraDibujada();
    cout << "Area del Circulo: " << miCirculo.CalcularArea() << endl;
    cout <<"----------------------------------------------------"<< endl;
    miRectangulo.figuraDibujada();
    cout << "Area del Rectangulo: " << miRectangulo.CalcularArea() << endl;
    cout <<"----------------------------------------------------"<< endl;
    miTriangulo.figuraDibujada();
    cout << "Area del Triangulo : " << miTriangulo.CalcularArea() << endl;
}