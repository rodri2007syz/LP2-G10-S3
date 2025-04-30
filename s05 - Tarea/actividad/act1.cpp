#include <iostream>
using namespace std;
class CuentaBancaria {
private :
	int numero;
	string titular;
	double saldo;
public:
	CuentaBancaria(int _numero, string _titular, double _saldo)
		: numero(_numero), titular(_titular), saldo(_saldo) {}

	CuentaBancaria& depositar(const double& cantidad) {
		if (cantidad <= 0) {
			cout << "Fallo en el deposito , ingrese un valor valido" << endl;
		}
		else {
			this->saldo += cantidad;
			cout << "Deposito exitoso " << endl;
			return *this;
		}

	}
	CuentaBancaria& retirar(const double& cantidad) {
		if (cantidad < 0) {
			cout << "Fallo en retiro " << endl;
		}
		else {
			this->saldo -= cantidad;
			cout << "Retiro Exitoso " << endl;
			return *this;
		}

	}
	void mostrarSaldo() {
		cout << "El saldo de la cuenta :" << numero << " del titular : " << titular << " es : " << saldo << endl;
	}
};

int main() {
	CuentaBancaria cuenta1(98706432, "Ratin Rodriguez", 100.0);
	cuenta1.depositar(10000).retirar(200).mostrarSaldo();
	cout << "casos de fallo: " << endl;
	cuenta1.depositar(-1).retirar(0);
	return 0;
}
