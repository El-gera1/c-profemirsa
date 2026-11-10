#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>

using namespace std;

const int ALUMNOS = 5;
const int PARCIALES = 3;
const double APROBATORIA = 70.0;

struct Alumno {
    int matricula;
    string nombre;
    int edad;
    vector<double> calificaciones;
    double promedio;
};

int main() {
    vector<Alumno> grupo;

    for (int i = 0; i < ALUMNOS; i++) {
        Alumno a;
        cout << "Alumno " << i + 1 << endl;
        cout << "Matricula: ";
        cin >> a.matricula;
        cout << "Nombre: ";
        cin >> a.nombre;
        cout << "Edad: ";
        cin >> a.edad;

        for (int j = 0; j < PARCIALES; j++) {
            double cal;
            cout << "Parcial " << j + 1 << ": ";
            cin >> cal;
            a.calificaciones.push_back(cal);
        }
        grupo.push_back(a);
    }

    for (Alumno& a : grupo) {
        double suma = 0;
        for (double cal : a.calificaciones) {
            suma += cal;
        }
        a.promedio = suma / PARCIALES;
    }

    cout << fixed << setprecision(2);
    cout << "\n--- Lista del grupo ---" << endl;
    cout << setw(10) << "Matricula" << setw(10) << "Nombre" << setw(8) << "Edad" 
         << setw(8) << "P1" << setw(8) << "P2" << setw(8) << "P3" << setw(10) << "Promedio" << endl;

    for (const Alumno& a : grupo) {
        cout << setw(10) << a.matricula 
             << setw(10) << a.nombre 
             << setw(8) << a.edad 
             << setw(8) << a.calificaciones[0] 
             << setw(8) << a.calificaciones[1] 
             << setw(8) << a.calificaciones[2] 
             << setw(10) << a.promedio << endl;
    }

    double sumaGrupo = 0;
    for (const Alumno& a : grupo) {
        sumaGrupo += a.promedio;
    }
    double promedioGrupo = sumaGrupo / ALUMNOS;
    cout << "Promedio del grupo: " << promedioGrupo << endl;

    int idxMejor = 0;
    int idxPeor = 0;
    for (int i = 1; i < ALUMNOS; i++) {
        if (grupo[i].promedio > grupo[idxMejor].promedio) {
            idxMejor = i;
        }
        if (grupo[i].promedio < grupo[idxPeor].promedio) {
            idxPeor = i;
        }
    }

    cout << "Mejor alumno: " << grupo[idxMejor].nombre << " (" << grupo[idxMejor].promedio << ")" << endl;
    cout << "Peor alumno: " << grupo[idxPeor].nombre << " (" << grupo[idxPeor].promedio << ")" << endl;

    cout << "Promedio por parcial:" << endl;
    double minPromParcial = 9999.0;
    int parcialMinimo = 0;

    for (int j = 0; j < PARCIALES; j++) {
        double sumaParcial = 0;
        for (int i = 0; i < ALUMNOS; i++) {
            sumaParcial += grupo[i].calificaciones[j];
        }
        double promParcial = sumaParcial / ALUMNOS;
        cout << "Parcial " << j + 1 << ": " << promParcial << endl;

        if (promParcial < minPromParcial) {
            minPromParcial = promParcial;
            parcialMinimo = j + 1;
        }
    }
    cout << "Parcial con el promedio mas bajo: " << parcialMinimo << endl;

    int aprobados = 0;
    int reprobados = 0;
    for (const Alumno& a : grupo) {
        if (a.promedio >= APROBATORIA) {
            aprobados++;
        } else {
            reprobados++;
        }
    }

    cout << "Aprobados: " << aprobados << endl;
    cout << "Reprobados: " << reprobados << endl;

    if (reprobados == 0) {
        cout << "Todos los alumnos aprobaron" << endl;
    } else {
        cout << "Alumnos reprobados:" << endl;
        for (const Alumno& a : grupo) {
            if (a.promedio < APROBATORIA) {
                cout << a.nombre << ": " << a.promedio << endl;
            }
        }
    }

    int matriculaBuscar;
    cout << "Matricula a buscar: ";
    cin >> matriculaBuscar;

    bool encontrado = false;
    for (const Alumno& a : grupo) {
        if (a.matricula == matriculaBuscar) {
            cout << a.nombre << ", " << a.edad << " años" << endl;
            cout << "Calificaciones: " << a.calificaciones[0] << " " << a.calificaciones[1] << " " << a.calificaciones[2] << endl;
            cout << "Promedio: " << a.promedio << endl;
            encontrado = true;
            break;
        }
    }

    if (!encontrado) {
        cout << "Alumno no encontrado" << endl;
    }

    return 0;
}