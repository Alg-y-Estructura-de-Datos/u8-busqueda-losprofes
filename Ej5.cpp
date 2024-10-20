#include <iostream>
#include <fstream>  // Para la lectura de archivos
#include <sstream>  // Para manipular las cadenas de texto
#include <vector>
using namespace std;

// Estructura para almacenar los datos de los estudiantes
struct Estudiante {
    int id;
    string nombre;
    int nota;
};

// Función para buscar un estudiante por ID en un vector de estudiantes
Estudiante* buscarEstudiante(const vector<Estudiante>& estudiantes, int claveID) {
    for (auto& estudiante : estudiantes) {
        if (estudiante.id == claveID) {
            return new Estudiante(estudiante); // Retorna un puntero si encuentra el estudiante
        }
    }
    return nullptr; // Retorna nullptr si no lo encuentra
}

int main() {
    cout << "Ejercicio 08/05" << endl;

    ifstream archivo("C:/Users/salce/OneDrive/Escritorio/estudiantes.csv");
    string linea;
    vector<Estudiante> estudiantes;

    // Verificar si el archivo se abrió correctamente
    if (!archivo.is_open()) {
        cout << "Error al abrir el archivo.\n";
        return 1;
    }

    // Saltar la primera línea (encabezado del CSV)
    getline(archivo, linea);

    // Leer cada línea del archivo CSV
    while (getline(archivo, linea)) {
        stringstream ss(linea);
        string idStr, nombre, notaStr;

        // Leer los campos separados por comas
        getline(ss, idStr, ',');
        getline(ss, nombre, ',');
        getline(ss, notaStr, ',');

        // Convertir los datos a tipos adecuados
        int id = stoi(idStr);
        int nota = stoi(notaStr);

        // Crear un objeto Estudiante y agregarlo al vector
        estudiantes.push_back({id, nombre, nota});
    }

    // Cerrar el archivo
    archivo.close();

    // Solicitar al usuario el ID a buscar
    int claveID;
    cout << "Ingrese el ID del estudiante que desea buscar: ";
    cin >> claveID;

    // Buscar el estudiante por su ID
    Estudiante* resultado = buscarEstudiante(estudiantes, claveID);

    if (resultado != nullptr) {
        cout << "Estudiante encontrado:\n";
        cout << "ID: " << resultado->id << "\n";
        cout << "Nombre: " << resultado->nombre << "\n";
        cout << "Nota: " << resultado->nota << "\n";
        delete resultado;  // Liberar memoria
    } else {
        cout << "El estudiante con ID " << claveID << " no se encontró.\n";
    }

    return 0;
}

