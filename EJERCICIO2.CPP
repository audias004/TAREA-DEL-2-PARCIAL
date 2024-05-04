#include <iostream>
#include <string>

using namespace std;

// Estructura del estudiante
struct Estudiante {
    string id;
    string nombres;
    string apellidos;
    float notas[4];
    float promedio;
    string estado;
};

// Función para calcular el promedio
void calcularPromedio(Estudiante* estudiante) {
    float suma = 0;
    for (int i = 0; i < 4; ++i) {
        suma += estudiante->notas[i];
    }
    estudiante->promedio = suma / 4;    
}

// Función para verificar si aprobó o no
void verificarAprobacion(Estudiante* estudiante) {
    if (estudiante->promedio >= 60) {
        estudiante->estado = "Aprobado";
    } else {
        estudiante->estado = "Reprobado";
    }
}

int main() {
    int numEstudiantes;

    cout << "Ingrese la cantidad de estudiantes: ";
    cin >> numEstudiantes;

    // Validar el número de estudiantes
    if (numEstudiantes < 1) {
        cerr << "Debe haber al menos un estudiante.\n";
        return 1;
    }

    Estudiante* estudiantes = new Estudiante[numEstudiantes]; // Memoria dinámica

    // Leer datos de los estudiantes
    for (int i = 0; i < numEstudiantes; ++i) {
        cout << "\nIngrese datos del estudiante " << i + 1 << ":\n"; // Corrección del mensaje
        cout << "ID del estudiante: ";
        cin >> estudiantes[i].id;
        cout << "Nombres: ";
        cin >> estudiantes[i].nombres;
        cout << "Apellidos: ";
        cin >> estudiantes[i].apellidos;
        cout << "Notas (nota1, nota2, nota3, nota4): ";
        for (int j = 0; j < 4; ++j) {
            cin >> estudiantes[i].notas[j];
        }

        // Calcular promedio y estado
        calcularPromedio(&estudiantes[i]);
        verificarAprobacion(&estudiantes[i]);
    }

    // Mostrar resultados
    cout << "\nResultados:\n";
    for (int i = 0; i < numEstudiantes; ++i) {
        cout << "ID: " << estudiantes[i].id << endl;
        cout << "Nombres: " << estudiantes[i].nombres << endl;
        cout << "Apellidos: " << estudiantes[i].apellidos << endl;
        cout << "Promedio: " << estudiantes[i].promedio << endl;
        cout << "Estado: " << estudiantes[i].estado << endl;
    }

    delete[] estudiantes; // Liberar memoria

    return 0; // Salir exitosamente
}

