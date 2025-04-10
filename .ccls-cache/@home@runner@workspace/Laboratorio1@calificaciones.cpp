#include <iostream>

using namespace std;


struct Estudiante {
    char nombre[100];  
    float calificaciones[10];  
    int numCalificaciones;
};


bool compararCadenas(const char* cadena1, const char* cadena2) {
    int i = 0;
    while (cadena1[i] != '\0' && cadena2[i] != '\0') {
        if (cadena1[i] != cadena2[i]) {
            return false;
        }
        i++;
    }
    return (cadena1[i] == '\0' && cadena2[i] == '\0');
}


void copiarCadena(char* destino, const char* origen) {
    int i = 0;
    while (origen[i] != '\0') {
        destino[i] = origen[i];
        i++;
    }
    destino[i] = '\0';
}


Estudiante* buscarEstudiante(Estudiante* estudiantes, int numEstudiantes, const char* nombre) {
    for (int i = 0; i < numEstudiantes; ++i) {
        if (compararCadenas(estudiantes[i].nombre, nombre)) {
            return &estudiantes[i];
        }
    }
    return nullptr; 
}


float mayorCalificacion(const Estudiante& estudiante) {
    float mayor = 0.0;
    for (int i = 0; i < estudiante.numCalificaciones; ++i) {
        if (estudiante.calificaciones[i] > mayor) {
            mayor = estudiante.calificaciones[i];
        }
    }
    return mayor;
}

int main() {
    int numEstudiantes;
    cout << "Ingrese el número de estudiantes: ";
    cin >> numEstudiantes;
    cin.ignore(); 

   
    Estudiante estudiantes[100];  

   
    for (int i = 0; i < numEstudiantes; ++i) {
        char nombre[100];
        cout << "Ingrese el nombre del estudiante " << i + 1 << ": ";
        cin.getline(nombre, 100);

        
        copiarCadena(estudiantes[i].nombre, nombre);

        int numCalificaciones;
        cout << "Ingrese el número de calificaciones para " << estudiantes[i].nombre << ": ";
        cin >> numCalificaciones;
        cin.ignore(); 

        estudiantes[i].numCalificaciones = numCalificaciones;

        
        for (int j = 0; j < numCalificaciones; ++j) {
            do {
                cout << "Ingrese la calificación " << j + 1 << " para " << estudiantes[i].nombre << ": ";
                cin >> estudiantes[i].calificaciones[j];

                if (estudiantes[i].calificaciones[j] < 0 || estudiantes[i].calificaciones[j] > 5) {
                    cout << "Error: La calificación debe estar entre 0 y 5. Intente de nuevo." << endl;
                }

            } while (estudiantes[i].calificaciones[j] < 0 || estudiantes[i].calificaciones[j] > 5);
            cin.ignore(); 
        }
    }

    
    char nombreBusqueda[100];
    cout << "\nIngrese el nombre del estudiante a buscar: ";
    cin.getline(nombreBusqueda, 100);

    Estudiante* estudianteEncontrado = buscarEstudiante(estudiantes, numEstudiantes, nombreBusqueda);
    if (estudianteEncontrado != nullptr) {
        float mayor = mayorCalificacion(*estudianteEncontrado);
        cout << "La mayor calificación de " << estudianteEncontrado->nombre << " es: " << mayor << endl;
    } else {
        cout << "Estudiante no encontrado." << endl;
    }

    
    cout << "\nPrograma creado por: David Rodriguez" << endl;

    return 0;
}

