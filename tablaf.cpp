#include <iostream>
using namespace std;

int multiplicar (int tabla, int i){
    return tabla * i;
}

void multi(){
    cout << "=== TABLAS DE MULTIPLICAR DEL 1 AL 10 ";
                for (int tabla = 1; tabla <= 10; tabla++) {
                    cout << "--- TABLA DEL " << tabla <<endl;
                    for (int i = 1; i <= 10; i++) {
                        cout << tabla << " x " << i << " = " << multiplicar(tabla, i) <<endl ;
                    }
                }
}

int main(){
     multi();
                return 0;
 }