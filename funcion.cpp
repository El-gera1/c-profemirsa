#include <iostream>
using namespace std;

void suma();
void resta();
void multi();
void divi();
void salir();
int main(){
    int op;
  

    cout << "Opciones" << endl;
        cout << "1: Suma" << endl;
        cout << "2: Resta" << endl;
        cout << "3: Multiplicacion" << endl;
        cout << "4: Division" << endl;
        cout << "5: Salir" << endl;
        cout << "Opcion: ";
        cin >> op;

        switch (op)
        {
        case 1: {
            suma();
        }
            break;
        case 2: {
            resta();
        }
        case 3: {
            multi();
        }
        case 4: {
            multi();
        }
        case 5: {
            salir();
        }
     }
}

void suma(){
    float n1, n2;
    cout << "Ingresa #1: ";
        cin >> n1;
        cout << "Ingresa #2: ";
        cin >> n2;
        cout << "La suma es: " << (n1 + n2) << endl;
}

void resta(){
    float n1, n2;
    cout << "Ingresa #1: ";
        cin >> n1;
        cout << "Ingresa #2: ";
        cin >> n2;
        cout << "La resta es: " << (n1 - n2) << endl;
}

void multi(){
    float n1, n2;
    cout << "Ingresa #1: ";
        cin >> n1;
        cout << "Ingresa #2: ";
        cin >> n2;
        cout << "La multiplicacion es: " << (n1 * n2) << endl;
}

void divi(){
    float n1,  n2;
    cout << "Ingresa #1: ";
        cin >> n1;
        cout << "Ingresa #2: ";
        cin >> n2;
        if (n2 != 0) {
            cout << "La division es: " << (n1 / n2) << endl;
        } else {
            cout << "No se puede dividir entre cero." << endl;
        }
}

void salir(){
    cout << "bay" << endl;
}