#include <iostream>
#include <string>

using namespace std;

const int max_estudiantes = 25; // Máximo de estudiantes

struct Estudiante {
    string id;
    string nombres;
    string apellidos;
    float notas[4];
    float promedio;
    string estado;
};

void calcularPromedio(Estudiante& estudiante) {
    float suma = 0;
    for (int i = 0; i < 4; ++i) {
        suma += estudiante.notas[i];
    }
    estudiante.promedio = suma / 4;
}

void verificarAprobacion(Estudiante& estudiante) {
    if (estudiante.promedio >= 60) {
        estudiante.estado = "Aprobado";
    } else {
        estudiante.estado = "Reprobado";
    }
}

int main() {
    Estudiante estudiantes[max_estudiantes]; // Arreglo para los estudiantes
    int numEstudiantes;

    cout << "Ingrese la cantidad de estudiantes: ";
    cin >> numEstudiantes; // Leer la cantidad de estudiantes

    // Validar la cantidad de estudiantes ingresada
    if (numEstudiantes < 1 || numEstudiantes > max_estudiantes) {
        cerr << "Número inválido de estudiantes. Debe ser entre 1 y " << max_estudiantes << ".\n";
        return 1; // Termina el programa con error
    }

    // Ingresar datos para cada estudiante
    for (int i = 0; i < numEstudiantes; ++i) {
        cout << "\nIngrese datos del estudiante " << i + 1 << ":\n";
        cout << "ID del estudiante: ";
        cin >> estudiantes[i].id;
        cout << "Nombres: ";
        cin >> estudiantes[i].nombres;
        cout << "Apellidos: ";
        cin >> estudiantes[i].apellidos;
        cout << "Notas (separadas por espacio, ejemplo: 85 90 78 88): ";
        for (int j = 0; j < 4; ++j) {
            cin >> estudiantes[i].notas[j];
        }

        // Calcular el promedio y determinar el estado del estudiante
        calcularPromedio(estudiantes[i]);
        verificarAprobacion(estudiantes[i]);
    }

    // Mostrar resultados
    cout << "\nResultados:\n";
    for (int i = 0; i < numEstudiantes; ++i) { 
        cout << "Estudiante " << i + 1 << ":\n";
        cout << "  ID: " << estudiantes[i].id << endl;
        cout << "  Nombres: " << estudiantes[i].nombres << endl;
        cout << "  Apellidos: " << estudiantes[i].apellidos << endl;
        cout << "  Promedio: " << estudiantes[i].promedio << endl;
        cout << "  Estado: " << estudiantes[i].estado << endl;
    }

    return 0; 
}

