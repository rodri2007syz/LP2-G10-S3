
#include <iostream>
#include <ctime>
using namespace std;

class Comprador {
private:
	string nombre;
	int dinero;

public:
	Comprador(string _nombre, int _dinero) {
		nombre = _nombre;
		dinero = _dinero;
	}
	string getNombre() {
		return nombre;
	}
	int getDinero() {
		return dinero;
	}
	void setNombre(string _nombre) {
		nombre = _nombre;
	}
	void setDinero(int _dinero) {
		if (_dinero <= 0) {
			cout << " Su dinero es insuficiente para comprar algun producto " << endl;
		}
		else {
			dinero = _dinero;
		}
	}

};
class producto {
private:
	string nombreprod, estado;
	int codigo, stock ;
public:
	producto() {
		nombreprod = "";
		estado = "";
		codigo = 0;
		stock = 0;
	}

	producto(string _nombreprod, string _estado, int _codigo, int _stock) {
		nombreprod = _nombreprod;
		estado = _estado;
		codigo = _codigo;
		stock = _stock;
	}
	string getNombreprod() {
		return nombreprod;
	}
	string getEstado() {
		return estado;
	}
	int getCodigo() {
		return codigo;
	}
	int getStock() {
		return stock;
	}
	void setNombreprod(string _nombreprod) {
		nombreprod = _nombreprod;
	}
	void setEstado(string _estado) {
		estado = _estado;
	}
	void setCodigo(int _codigo) {
		if (_codigo >= 0) {
			codigo = _codigo;
		}
		else {
			cout << "codigo no valido " << endl;
		}

	}
	void setStock(int _stock) {
		if (_stock >= 0) {
			stock = _stock;
		}
		else {
			cout << " Producto no disponible por el momento (SIN STOCK :,c )" << endl;
		}
	};
	void mostrarProducto() {
		cout << "Nombre: " << nombreprod<< endl;
		cout	<< " | Estado: " << estado<< endl;
		cout	<< " | Codigo: " << codigo<< endl;
		cout	<< " | Stock: " << stock << endl;
	}
};


class Pedido{
	private:
	int numeroPedido;
	string nombreCliente;
	string nombreProducto;
	int cantidad;
	string estado = "pendiente"; //pendiente o listo no olvidar 

	public:
	Pedido(int _numeroPedido, string _nombreCliente, string _nombreProducto, int _cantidad, string _estado) {
        numeroPedido = _numeroPedido;
        nombreCliente = _nombreCliente;
        nombreProducto = _nombreProducto;
        cantidad = _cantidad;
        estado = _estado;
    }

    // Métodos get y set
    int getNumeroPedido() {
        return numeroPedido;
    }

    string getNombreCliente() {
        return nombreCliente;
    }

    string getNombreProducto() {
        return nombreProducto;
    }

    int getCantidad() {
        return cantidad;
    }

    string getEstado() {
        return estado;
    }

    void setEstado(string _estado) {
        estado = _estado;
    }

	void mostrarPedido(){
		cout << "Numero de pedido:" << numeroPedido << endl;
		cout << "Nombre del cliente:" << nombreCliente << endl;
		cout << "Nombre del producto:" << nombreProducto << endl;
		cout << "Cantidad:" << cantidad << endl;
		cout << "Estado:" << estado << endl;
	}
};
