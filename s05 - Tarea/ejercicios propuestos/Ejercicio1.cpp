#include <iostream>
using namespace std;

class Producto {
private:
    string nom;
    double prec, desc;
public:
    Producto(string _nom, double _prec, double _desc)
        : nom(_nom),prec(_prec),desc(_desc) {}

    Producto& setNombre(const string& _nom) {
        this->nom = _nom;
        return *this;
    }
    Producto& setPrecio(const double& _prec) {
        this->prec = _prec;
        return *this;
    }
    Producto& setDescuento(const double& _desc) {
        this->desc = _desc;
        return *this;
    }
    double calcularPrecioFinal() const{
        return prec - (prec * desc/100);
    }
    void mostrar() const {
        cout << "Producto: " << nom
            << ", Precio: $" << prec
            << ", Descuento: " << desc << "%"
            << ", Precio final: $" << calcularPrecioFinal()
            << endl;
    }
    double getPrecioFinal() const {
        return calcularPrecioFinal();
    }

};

int main() {
    const int n = 3;
    Producto productos[n] = {
        Producto("Laptop", 1500, 10),
        Producto("Mouse", 50, 5),
        Producto("Monitor", 300, 15)
    };

    double total = 0;

    cout << "Lista de productos:" << endl;
    for (int i = 0; i < n; i++) {
        productos[i].mostrar();
        total += productos[i].getPrecioFinal();
    }

    cout << "\nTotal acumulado: $" << total << endl;

    return 0;
}