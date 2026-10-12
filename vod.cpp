#include <iostream>
using namespace std;
int litros,clientefrecuente,tipodecombustible;
float total,subtotal;
void subtotallitros(int &litros, int &tipodecombustible,float &precio){
    cout << "Ingrese los litros a cargar:" ;
    cin >> litros ;
    cout << "Seleccione el tipo de combustible :" << endl;
    cout << "1 : Regular [22.50] " << endl;
    cout << "2 : Premium [24.80]" << endl;
    cin >> tipodecombustible ;
    if (tipodecombustible == 1){
        precio = 22.50;
    } else {
        if (tipodecombustible == 2){
            precio = 24.80;
        } else {
            if (tipodecombustible != 1 && tipodecombustible != 2)
                precio = 0.0;
        }

    }
   subtotal = litros * precio ;
}

void calcularDescuento(float &subtotal, int esClienteFrecuente, float &descuento){
    cout << "== Cuenta con tarjeta frecuente? ==" << endl;
    cout << " 1 = SI    0 = NO :";
    cin >> esClienteFrecuente ;
    if  (esClienteFrecuente == 1 && subtotal >= 500) {
        descuento = subtotal * 0.08;
    } else {
        descuento = 0.0;
    }
    total = subtotal - descuento;
}


void mostrarTicket(float &subtotal, float &descuento, float &total){
    cout << " Subtotal:   $" << &subtotal ;
    cout << " Descuento (8%):  $"<< &descuento;
    cout << " TOTAL A PAGAR:  $"<< &total;
}

int main(){
    int l = 0, tipo = 0, cliente = 0;
    float precioCombustible = 0.0, desc = 0.0;

    cout << "=== Estacion de combustible ===" << endl;


    subtotallitros(l, tipo, precioCombustible);
    calcularDescuento(subtotal, cliente, desc);


    mostrarTicket(subtotal, desc, total  );

    cout << "desea realizar otra carga?";
    return 0;
}

