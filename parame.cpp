#include <iostream>
using namespace std;


int menu();
void operaciones(int op);



int main(){
    int opcion;

    opcion = menu();
   
    operaciones(opcion);


    return 0;
    
}

int menu(){
    int op;
    cout << "Opciones" << endl;
        cout << "1: Suma" << endl;
        cout << "2: Resta" << endl;
        cout << "3: Multiplicacion" << endl;
        cout << "4: Division" << endl;
        cout << "5: Salir" << endl;
        cout << "Opcion: ";
        cin >> op;
        return op;
}

void operaciones(int op){
    float n1 = 0, n2 = 0;
    switch (op) {
            case 1: {
                cout << "Ingresa #1: ";
                cin >> n1;
                cout << "Ingresa #2: ";
                cin >> n2;
                cout << "La suma es: " << (n1 + n2) << endl;
                break; 
            } 
            case 2: {
                cout << "Ingresa #1: ";
                cin >> n1;
                cout << "Ingresa #2: ";
                cin >> n2;
                cout << "La resta es: " << (n1 - n2) << endl;
                break;
            } 
            case 3: {
                cout << "Ingresa #1: ";
                cin >> n1;
                cout << "Ingresa #2: ";
                cin >> n2;
                cout << "La multiplicacion es: " << (n1 * n2) << endl;
                break;
            } 
            case 4: {
                cout << "Ingresa #1: ";
                cin >> n1;
                cout << "Ingresa #2: ";
                cin >> n2;
                if (n2 != 0) {
                    cout << "La division es: " << (n1 / n2) << endl;
                } else {
                    cout << "Error: No se puede dividir entre cero." << endl;
                }
            break;
            } 
            case 5: {
                cout << "bay" << endl;
                break;
            }
            default: {
                cout << "Opcion no valida." << endl;
                break;
            }
        }   
}