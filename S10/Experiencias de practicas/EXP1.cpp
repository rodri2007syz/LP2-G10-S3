

#include <string>
#include <iostream>
using namespace std;

template<class T>
//distancia + peso = costo basico
void costoDeEnvio(T a,T b){
    T costoBasico= a + b;
    cout << "S/" << costoBasico <<" del pedido" <<endl;
}



int main() {

    costoDeEnvio<float>(23.22,23.00);
    costoDeEnvio<double>(0.22,0.59);
    costoDeEnvio<bool>(true,false);

    return 0;
}