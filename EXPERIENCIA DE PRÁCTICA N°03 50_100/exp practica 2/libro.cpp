//Crea una clase Libro con atributos privados y públicos (titulo, autor, genero).
//• Implementa getters/setters y algún método auxiliar mostrarInfoLibro().
//• Instancia varios Libro y haz pruebas para confirmar que la encapsulación funciona

#include <iostream>
#include <stdlib.h>
using namespace std;

class Libro {
    private:
        string titulo;
        string autor;
        string genero;
    public:
        Libro();
        Libro(string t, string a, string g);
        void setTitulo(string t);
        string getTitulo();
        void setAutor(string a);
        string getAutor();
        void setGenero(string g);
        string getGenero();
        void mostrarInfoLibro();
};

Libro::Libro() {
    titulo = "";
    autor = "";
    genero = "";
}

Libro::Libro(string t, string a, string g) {
    titulo = t;
    autor = a;
    genero = g;
}

void Libro::setTitulo(string t) {
    titulo = t;
}

string Libro::getTitulo() {
    return titulo;
}

void Libro::setAutor(string a) {
    autor = a;
}

string Libro::getAutor() {
    return autor;
}

void Libro::setGenero(string g) {
    genero = g;
}

string Libro::getGenero() {
    return genero;
}

void Libro::mostrarInfoLibro() {
    cout << "titulo: " << titulo << endl;
    cout << "autor: " << autor << endl;
    cout << "genero: " << genero << endl;
}


int main() {

    Libro libro1;
    libro1.setTitulo("Don Quijote de la Mancha");
    libro1.setAutor("Miguel ");
    libro1.setGenero("Novela");

    Libro libro2("Cien años de soledad", "Gabriel", " magico");
    cout << "Libro 1:" << endl;
    libro1.mostrarInfoLibro();
    cout << "Libro 2:" << endl;
    libro2.mostrarInfoLibro();

    cout << "titulo del libro 2: " << libro2.getTitulo() << endl;

}