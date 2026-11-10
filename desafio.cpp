#include <iostream>
using namespace std;

struct estudiantes
{
    string nom;
    int age;
    char grade;

};



int main(){

    estudiantes l1;
    cout <<" ingresa el nombre del estudiante"<<endl;
    cin >> l1.nom;
    cout <<" ingresa la edad del estudiante"<<endl;
    cin >> l1.age;
    cout <<" ingresa el grado del estudiante"<<endl;
    cin >> l1.grade;

    cout <<" Nombre: "<< l1.nom << "\n";
    cout <<" Edad: "<< l1.age<< "\n";
    cout <<" Grado: "<< l1.grade<< "\n";



    return 0;

}