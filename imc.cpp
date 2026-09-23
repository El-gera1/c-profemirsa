#include <iostream>
#include <cstdlib>
using namespace std;
int main(){
    int edad, peso;
    string nom;
    float  imc,estatura;
    cout << "ingresa tu nombre: " << endl;
    cin >> nom;
    cout <<" ingresa tu edad : " << endl;
    cin >> edad;
    cout <<" ingresa tu estatura: "<< endl;
    cin >> estatura;
    cout << " ingresa tu peso: "<< endl;
    cin >> peso;

    imc  = peso / (estatura*estatura);
      cout << " tu imc es : " << imc << endl;
      if (imc <= 18.5){
        cout << " tu imc  esta bajo " << endl;
        } else if (imc <= 24.9 && 18.5){
            cout << " tu peso esta normal"<< endl;

        } else if (imc <= 29.9 && imc > 24.9){
            cout << " estas gord@"<< endl;
         }

}