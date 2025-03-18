#include <iostream>
#include <stdlib.h>
using namespace std;

class Cuentabancaria {
private:
    int cuenta = 0;
    int depositar = 0;
    int retirar = 0;

public:
    Cuentabancaria();
    void setdepositar(int depositar);
    int getdepositar();
    void setretirar(int retirar);
    int getretirar();
    int getSaldo();
};

Cuentabancaria::Cuentabancaria() {
    cuenta = 0;
}

void Cuentabancaria::setdepositar(int depositar) {
    this->depositar = depositar;
    if (depositar > 0) {
        cuenta += depositar; 
    }
}

int Cuentabancaria::getdepositar() {
    return depositar;
}

void Cuentabancaria::setretirar(int retirar) {
    this->retirar = retirar;
    if (retirar > 0 && retirar <= cuenta) {
        cuenta -= retirar; 
    }
}

int Cuentabancaria::getretirar() {
    return retirar;
}

int Cuentabancaria::getSaldo() {
    return cuenta;
}


int main() {
    Cuentabancaria miCuenta;
    cout << "saldo inicial: " << miCuenta.getSaldo() << endl;
    miCuenta.setdepositar(1000);
    cout << "despues de depositar 1000: " << miCuenta.getSaldo() << endl;
    miCuenta.setretirar(300);
    cout << "despues de retirar 300: " << miCuenta.getSaldo() << endl;
    miCuenta.setretirar(2000);
    cout << "despues de retirar 2000 : " << miCuenta.getSaldo() << endl; //se supone que no podria retirar 
    return 0;
}