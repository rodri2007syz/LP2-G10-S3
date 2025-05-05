#include <iostream>
#include <string>
#include <vector>

using namespace std;

class circulo{
private:
float radio;
float diametro;

friend float calcularArea(const circulo&);

public:
    circulo(float r) : radio(r),diametro(2*r) {
        cout <<"Se ingreso correctamente el radio " << endl;
    }
};


float calcularArea(const circulo& c ){
    return 3.1415 * c.radio * c.radio;
};

int main(){

    circulo circulo1(5.0);

    cout << "El area del circulo 1 es de " << calcularArea(circulo1)<< endl;


}