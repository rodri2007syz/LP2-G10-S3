
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Producto{
    string nombre;
    double precio;
    int cantidad;

public:
    Producto(string nom,double pre, int cant):nombre(nom),precio(pre),cantidad(cant){}

    void infoDelProducto(){
        cout << nombre << endl;
        cout << precio << endl;
        cout << cantidad << endl;
    }
};

int main()
{
    vector <Producto> inventario;

    Producto obj1("pan",12.32,12);
    Producto obj2("queso",13.30,5);
    Producto obj3("soda",11.10,10);

    inventario.push_back(obj1);
    inventario.push_back(obj2);
    inventario.push_back(obj3);
    
    for (size_t i = 0;i < inventario.size();++i){
        inventario[i].infoDelProducto();
    }

}
