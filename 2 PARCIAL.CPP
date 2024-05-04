#include <iostream>
#include <fstream> // Corregir el include para archivos
#include <string>

using namespace std;

// Nombre del archivo para almacenar estudiantes
const string FILENAME = "notas.dat";

// Estructura del estudiante
struct Estudiante {
    string id;
    string nombres;
    string apellidos;
    float notas[4];
    float promedio;
    string resultado;
};

// Función para agregar un estudiante al archivo
void agregarEstudiante() {
    Ofstream archivo(FILENAME, ios::binary | ios::app); // Correcto
    if (!archivo) {
        cout << "Error al abrir el archivo." << endl;
        return;
    }

    Estudiante estudiante; // Instancia del estudiante

    // Leer datos del estudiante
    cout << "Ingrese el ID del estudiante: ";
    cin >> estudiante.id; // Ingreso correcto
    cout << "Ingrese los nombres del estudiante: ";
    cin >> estudiante.nombres; // Correcto
    cout << "Ingrese los apellidos del estudiante: ";
    cin >> estudiante.apellidos; // Correcto
    cout << "Ingrese las notas del estudiante (nota1 nota2 nota3 nota4): "; // Entrada válida
    for (int i = 0; i < 4; ++i) { // Asegurarse de que el bucle sea correcto
        cin >> estudiante.notas[i]; // Validar entrada
    }

    // Calcular el promedio
    float suma = 0; // Asegurarse de que 'suma' esté inicializada
    for (int i = 0; i < 4; ++i) {
        suma += estudiante.notas[i]; // Correcto, sumando notas
    }
    estudiante.promedio = suma / 4; // Calcular promedio

    // Verificar si aprueba o no
    estudiante.resultado = (estudiante.promedio >= 60) ? "Aprobado" : "Reprobado"; // Lógica correcta

    archivo.write(reinterpret_cast<char*>(&estudiante), sizeof(Estudiante)); // Correcto, guardar en archivo

    archivo.close(); // Cerrar el archivo correctamente

    cout << "Estudiante agregado correctamente." << endl; // Salida correcta
}

// Función para mostrar todos los estudiantes
void mostrarEstudiantes() {
    ifstream archivo(FILENAME, ios::binary); // Lectura binaria
    if (!archivo) {
        cout << "Error al abrir el archivo." << endl; // Manejo del error
        return;
    }

    Estudiante estudiante; // Instancia para leer estudiantes

    cout << "\nListado de estudiantes:\n"; // Imprimir título
    while (archivo.read(reinterpret_cast<char*>(&estudiante), sizeof(Estudiante))) { // Corregir paréntesis
        cout << "ID: " << estudiante.id << endl;
        cout << "Nombres: " << estudiante.nombres << endl;
        cout << "Apellidos: " << estudiante.apellidos << endl;
        cout << "Promedio: " << estudiante.promedio << endl;
        cout << "Resultado: " << estudiante.resultado << endl;
        cout << endl; // Imprimir información del estudiante
    }

    archivo.close(); // Cerrar el archivo
}

// Función principal
int main() {
    int opcion; // Definición de la variable para opción

    do {
        cout << "\nMenú:\n"; // Menú de opciones
        cout << "1. Agregar estudiante\n"; // Opción para agregar
        cout << "2. Mostrar estudiantes\n"; // Opción para mostrar
        cout << "3. Salir\n"; // Opción para salir
        cout << "Ingrese su opción: ";
        cin >> opcion; // Leer la opción

        switch (opcion) {
            case 1:
                agregarEstudiante(); // Correcto, llamar la función
                break;
            case 2:
                mostrarEstudiantes(); // Llamar la función correcta
                break;
            case 3:
                cout << "Saliendo del programa...\n"; // Salida del programa
                break;
            default:
                cout << "Opción no válida. Intente de nuevo.\n"; // Manejo de error para opción incorrecta
                break;
        }
    } while (opcion != 3); // Continuar mientras no sea opción de salida

    return 0; // Salida exitosa
}
