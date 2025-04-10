#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>



int main() {
    // Nombre del archivo CSV
    std::string filename = R"(C:\Users\aulasingenieria\Downloads\Admission_Predict_Ver1.1.csv)";



    // Abrir el archivo
    std::ifstream file(filename);

    // Verificar si el archivo se abrió correctamente
    if (!file.is_open()) {
        std::cerr << "No se pudo abrir el archivo!" << std::endl;
        return 1;
    }

    std::string line;
    std::vector<std::vector<std::string>> data;

    // Leer línea por línea
    while (std::getline(file, line)) {
        std::stringstream lineStream(line);
        std::string cell;
        std::vector<std::string> row;

        // Leer cada celda separada por coma
        while (std::getline(lineStream, cell, ',')) {
            row.push_back(cell); // Agregar la celda a la fila
        }

        data.push_back(row); // Agregar la fila al conjunto de datos
    }

    // Cerrar el archivo
    file.close();

    // Imprimir los datos leídos
    for (const auto& row : data) {
        for (const auto& cell : row) {
            std::cout << cell << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
