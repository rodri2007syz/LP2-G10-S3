#include <iostream>
using namespace std;

class Banco {
public:
    static double tasaInteres;
    static void cambiarTasa(double nuevaTasa) {
        tasaInteres = nuevaTasa;
    }
};


double Banco::tasaInteres = 0.05;


class CuentaBancaria {
private:
    double saldo;

public:

    CuentaBancaria(double saldoInicial = 0) {
        saldo = saldoInicial;
    }


    void depositar(double monto) {
        saldo += monto;
        cout << "Depositados $" << monto << endl;
    }

    void retirar(double monto) {
        if (monto <= saldo) {
            saldo -= monto;
            cout << "Retirados $" << monto << endl;
        } else {
            cout << "Fondos insuficientes!" << endl;
        }
    }

    double calcularInteres() {
        return saldo * Banco::tasaInteres;
    }

    void mostrarSaldo() {
        cout << "Saldo actual: $" << saldo << endl;
        cout << "Interes anual: $" << calcularInteres() << endl;
    }
};

int main() {

    Banco::cambiarTasa(0.04);

    CuentaBancaria cuenta1(1000);
    CuentaBancaria cuenta2;

    cout << "\n Cuenta 1" << endl;
    cuenta1.mostrarSaldo();
    cuenta1.depositar(500);
    cuenta1.retirar(200);
    cuenta1.mostrarSaldo();

    cout << "\n Cuenta 2 " << endl;
    cuenta2.depositar(800);
    cuenta2.retirar(100);
    cuenta2.mostrarSaldo();

    cout << "\n Cambio de tasa al 6% " << endl;
    Banco::cambiarTasa(0.06);
    cuenta1.mostrarSaldo();
    cuenta2.mostrarSaldo();

    return 0;
}
