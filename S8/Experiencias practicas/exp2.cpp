#include <iostream>
using namespace std;

class Forma {
public:
    virtual double calcularPerimetro() const = 0;
   
};

class Circulo : public Forma {
    double radio;
public:
    Circulo(double r) : radio(r) {}
    double calcularPerimetro() const override {
        return 2 * 3.1416 * radio;
    }
};

class Rectangulo : public Forma {
    double ancho, alto;
public:
    Rectangulo(double a, double h) : ancho(a), alto(h) {}
    double calcularPerimetro() const override {
        return 2 * (ancho + alto);
    }
};

class Triangulo : public Forma {
    double l1, l2, l3;
public:
    Triangulo(double a, double b, double c) : l1(a), l2(b), l3(c) {}
    double calcularPerimetro() const override {
        return l1 + l2 + l3;
    }
};

int main() {

    Circulo c(5.0);
    Rectangulo r(4.0, 6.0);
    Triangulo t(3.0, 4.0, 5.0);
    

    cout << "Perimetro circulo: " << c.calcularPerimetro() << endl;
    cout << "Perimetro rectangulo: " << r.calcularPerimetro() << endl;
    cout << "Perimetro triangulo: " << t.calcularPerimetro() << endl;
    
    return 0;
}
