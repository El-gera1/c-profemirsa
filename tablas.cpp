#include <iostream>

using namespace std;

int main() {
    int opcion;
    do {
        
        cout << "1. Mostrar Tablas de Multiplicar (1 al 10)";
        

        switch (opcion) {
            case 1:
                cout << "=== TABLAS DE MULTIPLICAR DEL 1 AL 10 ";
                for (int tabla = 1; tabla <= 10; tabla++) {
                    cout << "--- TABLA DEL " << tabla << " ---";
                    for (int i = 1; i <= 10; i++) {
                        cout << tabla << " x " << i << " = " << (tabla * i) <<endl ;
                    }
                    
                }
                break;

            case 2:
                

            case 3:
                

            case 4:
                cout << "¡Saliendo del programa! Gracias por usarlo.";
                break;

            default:
                cout << "Opción no válida. Intenta de nuevo.";
                break;
        }

    } while (opcion != 4); 

    return 0;
}
