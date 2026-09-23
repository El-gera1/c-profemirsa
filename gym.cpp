#include <iostream>
using namespace std;

int main(){
    int ma;
    char tipodeusuario;
    int ndmp;
    char dc;
    int op;
    int diasRegistrados = 0;

    do {
        cout << "\n--- MENU ---" << endl;
        cout << " 1: Registrar cobro de membresia" << endl;
        cout << " 2: Salir" << endl; 
        cout << "Elija una opcion: ";
        cin >> op;

        switch (op) {
            case 1: {
                double tarifa = 0;
                cout << "\n--- REGISTRAR COBRO DE MEMBRESIA ---" << endl;
            
                cout << "Ingrese su matricula: ";
                cin >> ma;
      
                cout << "Su membresia es para estudiante, docente o publico? (E, D, G): ";
                cin >> tipodeusuario;

              
                if (tipodeusuario == 'E' || tipodeusuario == 'e'){
                    tarifa = 150;
                }
                else if (tipodeusuario == 'D' || tipodeusuario == 'd'){
                    tarifa = 250;
                }
                else if (tipodeusuario == 'G' || tipodeusuario == 'g'){
                    tarifa = 400;
                }
                else {
                    cout << "Error: dato no valido. No se realizara el cobro." << endl;
                    tarifa = -1;
                }

                if (tarifa != -1) {
                  
                    cout << "Ingrese los meses que desea pagar (1 a 12): ";
                    cin >> ndmp;
                    
                    while (ndmp < 1 || ndmp > 12) {
                        cout << "Error: los meses deben ser entre 1 y 12. Por favor ingrese de nuevo: ";
                        cin >> ndmp;
                    }

                    cout << "Desea casillero? (S/N): ";
                    cin >> dc;
                     
                    double subtotalBase = tarifa * ndmp;
                    double cargoCasillero = 0;

                    if (dc == 'S' || dc == 's'){
                        cargoCasillero = 50 * ndmp;
                    }

                    double subtotalConAdicionales = subtotalBase + cargoCasillero;
                    double descuentoAplicado = 0;
                    
                    if (ndmp == 12) {
                        descuentoAplicado = subtotalConAdicionales * 0.20;
                    } 
                    else if (ndmp >= 6) {
                        descuentoAplicado = subtotalConAdicionales * 0.10;
                    }

                    double totalDefinitivo = subtotalConAdicionales - descuentoAplicado;

                    double horas;
                    diasRegistrados = 0;

                    cout << "\n--- REGISTRO DE ASISTENCIA (Maximo 30 dias) ---" << endl;
                    for (int dia = 1; dia <= 30; dia++) {
                        cout << "Dia " << dia << " - Cuantas horas entreno el usuario? (0 o negativo para cancelar): ";
                        cin >> horas;
                        
                        if (horas <= 0) {
                            cout << "Entrenamiento cancelado o suspendido. Finalizando registro..." << endl;
                            break;
                        }

                        diasRegistrados = dia;
                    }

                    cout << "\n=============================================" << endl;
                    cout << "           DESGLOSE FORMAL DE PAGO          " << endl;
                    cout << "=============================================" << endl;
                    cout << "Matricula: " << ma << endl;
                    cout << "Subtotal base por mensualidades: $" << subtotalBase << " MXN" << endl;
                    cout << "Cargo extra por casillero: $" << cargoCasillero << " MXN" << endl;
                    cout << "Descuento aplicado: $" << descuentoAplicado << " MXN" << endl;
                    cout << "Total definitivo a pagar: $" << totalDefinitivo << " MXN" << endl;
                    cout << "Total de dias registrados antes de finalizar: " << diasRegistrados << endl;
                    cout << "=============================================" << endl;
                }
                break;
            }
            case 2: {
                cout << "Saliendo del programa..." << endl;
                break;
            }
            default: {
                cout << "Opcion no valida. Intente de nuevo." << endl;
                break;
            }
        }
        
        if (op != 2) {
            cout << "\nPresione Enter o una tecla para continuar...";
      
        }
        
    } while (op != 2);

    return 0;
}