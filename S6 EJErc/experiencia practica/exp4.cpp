#include <iostream>
using namespace std;

class Vector2D{
    private:
    float x;
    float y;

    public:
    Vector2D (): x(0.0) , y(0.0){
        cout << "se agregaron los valores predefinidos 0.0 en x e y" << endl;
    }

    Vector2D(float xUser , float yUser) : x(xUser) , y(yUser){
        cout << "se ingresaron correctamente los valores en x e y" << endl;
    }

    void mostrarVector2D(){
        cout << "X ====> " << x << endl;
        cout << "Y ====> " << y << endl;
    }

    //aqui sobre carga de operadores
    Vector2D operator +(const Vector2D& otroVector) const{
        return Vector2D(x + otroVector.x, y + otroVector.y);
    }

    Vector2D operator -(const Vector2D& otroVector) const{
        return Vector2D(x - otroVector.x, y - otroVector.y);
    }
};

int main(){
    Vector2D cordenada1(2.5 , 3);
    Vector2D cordenada2(1.5, 2);

    //vector 1
    cordenada1.mostrarVector2D();
    //vector 2
    cordenada2.mostrarVector2D();
    //suma 
    Vector2D suma1y2 = cordenada1 + cordenada2;

    suma1y2.mostrarVector2D();
    //Resta
    Vector2D resta1y2 = cordenada1- cordenada2;

    resta1y2.mostrarVector2D();
}