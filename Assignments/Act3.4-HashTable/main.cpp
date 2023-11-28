#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "HashStudentId.h"

using namespace std;

int main() {
    HashStudentId matri;
    int choice;

    while (true) {
        // Mostrar el menú
        cout << "\nMenu:" << endl;
        cout << "0. Leer matrículas desde archivo\n";
        cout << "1. Insertar matrícula\n";
        cout << "2. Eliminar matrícula\n";
        cout << "3. Buscar matrícula\n";
        cout << "4. Mostrar tabla hash\n";
        cout << "5. Salir\n";
        cout << "Ingrese su elección: ";
        cin >> choice;

        switch (choice) {
            case 0: {
                // Leer matrículas desde archivo
                ifstream fileIn("matriculas.txt");
                string matriculaFromFile;
                while (getline(fileIn, matriculaFromFile)) {
                    matri.insert(matriculaFromFile);
                }
                cout << "Matrículas leídas desde el archivo.\n";
                break;
            }
            case 1: {
                // Insertar matrícula
                string matricula;
                cout << "Ingrese la matrícula a insertar: ";
                cin >> matricula;
                matri.insert(matricula);
                cout << "Matrícula insertada con éxito.\n";
                break;
            }
            case 2: {
                // Eliminar matrícula
                string matricula;
                cout << "Ingrese la matrícula a eliminar: ";
                cin >> matricula;
                matri.remove(matricula);
                cout << "Matrícula eliminada con éxito.\n";
                break;
            }
            case 3: {
                // Buscar matrícula
                string matricula;
                cout << "Ingrese la matrícula a buscar: ";
                cin >> matricula;
                int index = matri.findStudentId(matricula);
                if (index != -1) {
                    cout << "La matrícula existe en la tabla hash en la posición " << index << ".\n";
                } else {
                    cout << "La matrícula no existe en la tabla hash.\n";
                }
                break;
            }
            case 4:
                // Mostrar tabla hash
                matri.print();
                break;
            
            case 5:
                // Salir
                cout << "Saliendo del programa.\n";
                return 0;
            default:
                cout << "Opción no válida. Intente de nuevo.\n";
        }
    }

    return 0;
}
