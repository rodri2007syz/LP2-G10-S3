#include <iostream>
#include <stdexcept>

using namespace std;

double divide(int numerador, int divisor) {
    if (divisor == 0) {

        throw runtime_error("Error: No se puede dividir por cero.");
    }
    return static_cast<double>(numerador) / divisor;
}

int main() {

    try {
        int num1 = 10;
        int den1 = 2;
        double resultado1 = divide(num1, den1);
        cout << num1 << " / " << den1 << " = " << resultado1 << endl;
    } catch (const runtime_error& e) {

        cerr << "Excepción capturada: " << e.what() << endl;
    }

    cout << endl;

    try {
        int num2 = 15;
        int den2 = 0;
        double resultado2 = divide(num2, den2);
        cout << num2 << " / " << den2 << " = " << resultado2 << endl;
    } catch (const runtime_error& e) {

        cerr << "Excepción capturada: " << e.what() << endl;
    }

    cout << endl;

    try {
        int num3 = 7;
        int den3 = 3;
        double resultado3 = divide(num3, den3);
        cout << num3 << " / " << den3 << " = " << resultado3 << endl;
    } catch (const runtime_error& e) {

        cerr << "Excepción capturada: " << e.what() << endl;
    }

    cout << endl;

    int valores[][2] = {{20, 5}, {25, 0}, {100, 10}, {50, 0}};
    cout << "--- Probando múltiples divisiones ---" << endl;
    for (int i = 0; i < 4; ++i) {
        try {
            double res = divide(valores[i][0], valores[i][1]);
            cout << valores[i][0] << " / " << valores[i][1] << " = " << res << endl;
        } catch (const runtime_error& e) {
            cerr << "Error al dividir " << valores[i][0] << " / " << valores[i][1] << ": " << e.what() << endl;
        }
    }

    return 0;
}