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

// Funci�n para agregar un estudiante al archivo
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
    cout << "Ingrese las notas del estudiante (nota1 nota2 nota3 nota4): "; // Entrada v�lida
    for (int i = 0; i < 4; ++i) { // Asegurarse de que el bucle sea correcto
        cin >> estudiante.notas[i]; // Validar entrada
    }

    // Calcular el promedio
    float suma = 0; // Asegurarse de que 'suma' est� inicializada
    for (int i = 0; i < 4; ++i) {
        suma += estudiante.notas[i]; // Correcto, sumando notas
    }
    estudiante.promedio = suma / 4; // Calcular promedio

    // Verificar si aprueba o no
    estudiante.resultado = (estudiante.promedio >= 60) ? "Aprobado" : "Reprobado"; // L�gica correcta

    archivo.write(reinterpret_cast<char*>(&estudiante), sizeof(Estudiante)); // Correcto, guardar en archivo

    archivo.close(); // Cerrar el archivo correctamente

    cout << "Estudiante agregado correctamente." << endl; // Salida correcta
}

// Funci�n para mostrar todos los estudiantes
void mostrarEstudiantes() {
    ifstream archivo(FILENAME, ios::binary); // Lectura binaria
    if (!archivo) {
        cout << "Error al abrir el archivo." << endl; // Manejo del error
        return;
    }

    Estudiante estudiante; // Instancia para leer estudiantes

    cout << "\nListado de estudiantes:\n"; // Imprimir t�tulo
    while (archivo.read(reinterpret_cast<char*>(&estudiante), sizeof(Estudiante))) { // Corregir par�ntesis
        cout << "ID: " << estudiante.id << endl;
        cout << "Nombres: " << estudiante.nombres << endl;
        cout << "Apellidos: " << estudiante.apellidos << endl;
        cout << "Promedio: " << estudiante.promedio << endl;
        cout << "Resultado: " << estudiante.resultado << endl;
        cout << endl; // Imprimir informaci�n del estudiante
    }

    archivo.close(); // Cerrar el archivo
}

// Funci�n principal
int main() {
    int opcion; // Definici�n de la variable para opci�n

    do {
        cout << "\nMen�:\n"; // Men� de opciones
        cout << "1. Agregar estudiante\n"; // Opci�n para agregar
        cout << "2. Mostrar estudiantes\n"; // Opci�n para mostrar
        cout << "3. Salir\n"; // Opci�n para salir
        cout << "Ingrese su opci�n: ";
        cin >> opcion; // Leer la opci�n

        switch (opcion) {
            case 1:
                agregarEstudiante(); // Correcto, llamar la funci�n
                break;
            case 2:
                mostrarEstudiantes(); // Llamar la funci�n correcta
                break;
            case 3:
                cout << "Saliendo del programa...\n"; // Salida del programa
                break;
            default:
                cout << "Opci�n no v�lida. Intente de nuevo.\n"; // Manejo de error para opci�n incorrecta
                break;
        }
    } while (opcion != 3); // Continuar mientras no sea opci�n de salida

    return 0; // Salida exitosa
}
