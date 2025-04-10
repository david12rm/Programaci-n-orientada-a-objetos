#include<iostream>
#include<fstream>
using namespace std;
struct Jugador {
  char nombre [30];
  int puntaje;
};
void guardarJugadores( Jugador* jugadores, int cantidad){
  ofstream archivo("jugadores.bin", ios::binary);
  archivo.write((char*)jugadores, sizeof(Jugador)*cantidad);
  archivo.close();
  cout<<"Jugadores guardados en el archivo binario"<<endl;
}
void leerjugadores(){
  ifstream archivo("jugadores.bin", ios::binary);
  if(!archivo){
    cerr<<"no se encontró el archivo"<<endl;
    return;
  }
archivo.seekg(0,ios::end);
  int cantidad= archivo.tellg()/sizeof(Jugador);
  archivo.seekg(0,ios::beg);
  Jugador* jugadores= new Jugador[cantidad];
  archivo.read((char*)jugadores, sizeof(Jugador)*cantidad);
  archivo.close();
  cout<<"Jugadores leidos del archivo binario:"<<endl;
  for(int i=0; i<cantidad; i++){
    cout<<"Nombre: "<<jugadores[i].nombre<<", Puntaje: "<<jugadores[i].puntaje<<endl;
  }
  delete[] jugadores;
  
  
}
int main(){
  int cantidad;
  cout<<"Ingrese la cantidad de jugadores: ";
  cin>>cantidad;
  Jugador* jugadores= new Jugador[cantidad];
  for(int i=0; i<cantidad; i++){
    cout<<"Ingrese el nombre del jugador "<<i+1<<": ";
    cin>>jugadores[i].nombre;
    cout<<"Ingrese el puntaje del jugador "<<i+1<<": ";
    cin>>jugadores[i].puntaje;
    
  }
  guardarJugadores(jugadores, cantidad);
  delete[] jugadores;
  leerjugadores();
  return 0;
  
}
