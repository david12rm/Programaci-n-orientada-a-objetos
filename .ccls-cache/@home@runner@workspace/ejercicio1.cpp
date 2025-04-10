#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

struct Jugador {
    char nombre[30];
    int puntaje;
};

void guardarJugadores(Jugador *jugadores, int cantidad) {
    ofstream archivo("jugadores.bin", ios::binary);
    archivo.write(reinterpret_cast<char*>(jugadores), cantidad * sizeof(Jugador));
    archivo.close();

   
    Jugador mejorJugador = jugadores[0];
    for (int i = 1; i < cantidad; i++) {
        if (jugadores[i].puntaje > mejorJugador.puntaje) {
            mejorJugador = jugadores[i];
        }
    }

  
    ofstream archivoMejor("mejor_jugador.bin", ios::binary);
    archivoMejor.write(reinterpret_cast<char*>(&mejorJugador), sizeof(Jugador));
    archivoMejor.close();
}

void leerJugadores() {
    ifstream archivo("jugadores.bin", ios::binary);
    if (!archivo) {
        cerr << "No se encontró el archivo" << endl;
        return;
    }


    archivo.seekg(0, ios::end);
    int cantidad = archivo.tellg() / sizeof(Jugador);
    archivo.seekg(0, ios::beg);


    Jugador *jugadores = new Jugador[cantidad];
    archivo.read(reinterpret_cast<char*>(jugadores), cantidad * sizeof(Jugador));
    archivo.close();

    cout << "Jugadores registrados:" << endl;
    for (int i = 0; i < cantidad; i++) {
        cout << "Nombre: " << jugadores[i].nombre << ", Puntaje: " << jugadores[i].puntaje << endl;
    }

    delete[] jugadores;
}

void leerMejorJugador() {
    ifstream archivo("mejor_jugador.bin", ios::binary);
    if (!archivo) {
        cerr << "No se encontró el archivo del mejor jugador" << endl;
        return;
    }

    Jugador mejorJugador;
    archivo.read(reinterpret_cast<char*>(&mejorJugador), sizeof(Jugador));
    archivo.close();

    cout << "\nJUGADOR CON MAYOR PUNTAJE:" << endl;
    cout << "Nombre: " << mejorJugador.nombre << ", Puntaje: " << mejorJugador.puntaje << endl;
}

int main() {
    int cantidad;
    cout << "Ingrese la cantidad de jugadores: ";
    cin >> cantidad;

 
    Jugador *jugadores = new Jugador[cantidad];
    for (int i = 0; i < cantidad; i++) {
        cout << "Ingrese el nombre del jugador " << i + 1 << ": ";
        cin >> jugadores[i].nombre;
        cout << "Puntaje: ";
        cin >> jugadores[i].puntaje;
    }

    guardarJugadores(jugadores, cantidad);
    delete[] jugadores;

    leerJugadores();
    leerMejorJugador();

    return 0;
}