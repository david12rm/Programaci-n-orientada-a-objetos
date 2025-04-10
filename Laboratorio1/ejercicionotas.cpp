#include <iostream>

using namespace std;

const int MAX_NOMBRE = 50;  // Máximo tamaño para el nombre de un estudiante
const int MAX_CALIFICACIONES = 10;  // Número máximo de calificaciones

struct Estudiante {
    char nombre[MAX_NOMBRE];  // Nombre como arreglo de caracteres
    float calificaciones[MAX_CALIFICACIONES];  // Arreglo estático de calificaciones
    int numCalificaciones;  // Número de calificaciones
};


void ingresarDatos(Estudiante* estudiante) {
    cout << "Ingrese el nombre del estudiante: ";
    cin.getline(estudiante->nombre, MAX_NOMBRE);

    cout << "Ingrese la cantidad de calificaciones: ";
    cin >> estudiante->numCalificaciones;

    cout << "Ingrese las calificaciones (0.0 a 5.0): " << endl;
    for (int i = 0; i < estudiante->numCalificaciones; i++) {
        float calificacion;
        cout << "Calificación " << i + 1 << ": ";
        cin >> calificacion;

        // Validar que la calificación esté entre 0.0 y 5.0
        while (calificacion < 0.0 || calificacion > 5.0) {
            cout << "Calificación inválida. Debe estar entre 0.0 y 5.0. Ingrese nuevamente: ";
            cin >> calificacion;
        }
        estudiante->calificaciones[i] = calificacion;
    }

    // Limpiar el buffer de la entrada para evitar problemas con getline después de cin
    cin.ignore();
}

// Función para encontrar la mayor calificación de un estudiante
float obtenerMayorCalificacion(Estudiante* estudiante) {
    float mayor = estudiante->calificaciones[0];
    for (int i = 1; i < estudiante->numCalificaciones; i++) {
        if (estudiante->calificaciones[i] > mayor) {
            mayor = estudiante->calificaciones[i];
        }
    }
    return mayor;
}

// Función para buscar un estudiante por nombre
bool compararNombres(const char* nombre1, const char* nombre2) {
    int i = 0;
    while (nombre1[i] != '\0' && nombre2[i] != '\0') {
        if (nombre1[i] != nombre2[i]) {
            return false;  // Si los caracteres no coinciden, los nombres son diferentes
        }
        i++;
    }
    // Los nombres son iguales si ambos terminan en '\0'
    return nombre1[i] == nombre2[i];
}

Estudiante* buscarEstudiante(Estudiante estudiantes[], int numEstudiantes, const char* nombreBuscado) {
    for (int i = 0; i < numEstudiantes; i++) {
        if (compararNombres(estudiantes[i].nombre, nombreBuscado)) {
            return &estudiantes[i];
        }
    }
    return nullptr;  // Si no lo encuentra, retorna nullptr
}

int main() {
    const int MAX_ESTUDIANTES = 10;  // Máximo número de estudiantes
    Estudiante estudiantes[MAX_ESTUDIANTES];
    int numEstudiantes = 0;

    while (true) {
        cout << "Desea ingresar un estudiante? (1 = Si, 0 = No): ";
        int opcion;
        cin >> opcion;
        if (opcion == 0) {
            break;
        }

        if (numEstudiantes < MAX_ESTUDIANTES) {
            ingresarDatos(&estudiantes[numEstudiantes]);
            numEstudiantes++;
        } else {
            cout << "Se alcanzó el número máximo de estudiantes." << endl;
        }

        cin.ignore();  // Limpiar el buffer de la entrada
    }

    // Búsqueda por nombre
    cout << "Ingrese el nombre del estudiante a buscar: ";
    char nombreBusqueda[MAX_NOMBRE];
    cin.getline(nombreBusqueda, MAX_NOMBRE);

    Estudiante* estudianteEncontrado = buscarEstudiante(estudiantes, numEstudiantes, nombreBusqueda);

    if (estudianteEncontrado) {
        float mayorCalificacion = obtenerMayorCalificacion(estudianteEncontrado);
        cout << "La mayor calificación de " << estudianteEncontrado->nombre << " es: " << mayorCalificacion << endl;
    } else {
        cout << "Estudiante no encontrado." << endl;
    }

    return 0;
}
