#include <iostream>
#include <string>
using namespace std;

class Libro {
private:
    string titulo;
    string autor;
    string genero;

public:
    // Constructor
    Libro(string tit, string aut, string gen)
        : titulo(tit), autor(aut), genero(gen) {}

    // Get
    string getTitulo() const {
        return titulo;
    }

    string getAutor() const {
        return autor;
    }

    string getGenero() const {
        return genero;
    }

    // Set
    void setTitulo(string tit) {
        titulo = tit;
    }

    void setAutor(string aut) {
        autor = aut;
    }

    void setGenero(string gen) {
        genero = gen;
    }

    void mostrarInfoLibro() const {
        cout << "-----------------------" << endl;
        cout << "Información del libro:" << endl;
        cout << "Título: " << titulo << endl;
        cout << "Autor: " << autor << endl;
        cout << "Género: " << genero << endl;
        cout << "-----------------------" << endl;
    }
};

