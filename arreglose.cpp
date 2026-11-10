#include <iostream>
using namespace std;

int main() {

    const int estudiantes = 30;
    float cal[estudiantes];
    int l;

    do
    {
        cout<<" ingrese el numero  de estudiantes a regristrar: " << endl;
        cin >> l;
        if (l <= 0 || l > estudiantes){
            cout << "Error  Por favor, ingrese un número entre 1 y 30.\n";
        }

    } while (l <= 0 || l > estudiantes);
    
    cout <<"\n registro de calificaciones \n";
    for (int i = 0; i < l; i++){
        do
        {
            cout <<" ingrese  la calificion de el estudiante: "<< (i + 1)<<": ";
            cin >> cal[i];
            if (cal[i] < 0 || cal[i] > 100){
                cout <<"Error Debe estar entre 0 y 100.\n ";
            }

        } while (cal[i] < 0 || cal[i] > 100);
        
    }

    cout <<"\n calificaciones registradas: \n";
    for (int i = 0; i < l; i++){
        cout << "Estudiante " << (i + 1) << ": " << cal[i]<<endl;
    }

    float s = 0;
    for (int i = 0; i < l; i++){
        s += cal[i];
    }
    float promedio = s / l;
    cout << "\nPromedio del grupo: " << promedio << endl;

    float a = cal[0];
    float b = cal[0];
    for (int i = 1; i < l; i++){
        if (cal[i] > a){
            a = cal[i];
        }
        if (cal[i] < b){
            b = cal[i];
        }
    }

    cout << "Calificación más alta: " << a << endl;
    cout << "Calificación más baja: " << b << endl;

    int apro = 0;
    int rep = 0;
    for(int i = 0; i < l; i++){
        if ( cal[i] >= 60){
            apro++;
        } else{
            rep++;
        }
        

    }

    
    cout << "Estudiantes aprobados: " << apro << endl;
    cout << "Estudiantes reprobados: " << rep<< endl;
    return 0;

}