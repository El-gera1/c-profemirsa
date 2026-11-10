#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main(){
    const int m = 100;
    string nom[m];
    float precio[m];
    int canti[m];
    float igre[m];
    
    int l;
    cout << " ingresa "<< m <<" productos maximo: ";
    cin >>l;

    if (l <= 0 || l > m){
        cout << " cantidad de productos no disponible."<< endl;
        return 1;
    }

    cout  << "\n ingresa los datos de los productos: "<<endl;
    for ( int i = 0; i < l; i++){
        cout << "\n  produtos # "<< i + 1<< endl;
        cout  << "\n ingresa el nombre de los productos: "<< endl;
        cin >> nom[i];
        cout <<" ingresa el precio unitario: "<< endl;
        cin >> precio[i];
        cout << " ingresa la cantidad de unidades vendidas: "<< endl;
        cin >> canti[i];

        igre[i] = precio[i] * canti[i];



        
    }

    float t_t = 0;
    int idmax = 0;
    int idmn = 0;

    int alta = 0;
    int regular = 0;
    int baja = 0;

    cout << "\n -------------reporte de ventas-------------"<<endl;
    for(int i = 0; i < l; i++){
        cout<<"\n producto: "<<nom[i]
        <<"\n precio: "<<precio[i]
        <<"\n vendidas: "<<canti[i]
        <<"\n ingreso: "<<igre[i]<< endl;

        t_t += igre[i];

        if( igre[i] > igre[idmax]){
            idmax = i;
        }
        if (igre[i] > igre[idmn]){
            idmn = i;
        }

        if( igre[i] >= 1000){
            alta++;
        }else if(igre[i] >= 500){
            regular++;
        }else{
            baja++;
        }
        
    }

    float prom = t_t / l;

    cout << "\n---------------------------------------------------" << endl;
    cout << " ingreso total de la tienda: "<< t_t <<endl;
    cout << " promedio de ingreso por producto: "<<prom<<endl;
    cout <<" producto con mayor ingreso: "<<nom[idmax]<<" ( $ "<<igre[idmax]<<" ) "<<endl;
    cout <<" producto con menor ingreso: "<<nom[idmn]<<" ( $ "<<igre[idmn]<<" ) "<<endl;

    cout << "\n--- Clasificacion de productos ---" << endl;
    cout << "Alta venta (ingresos >= $1,000): " << alta << " producto(s)" << endl;
    cout << "Venta regular (ingresos de $500 a $999): " << regular << " producto(s)" << endl;
    cout << "Baja venta (ingresos < $500): " << baja << " producto(s)" << endl;

    char op;
    cout << "\n¿Desea buscar un producto por su nombre? (s/n): ";
    cin >> op;

    if (op == 's' || op == 'S') {
        string buscado;
        cout << "Ingrese el nombre del producto a buscar: ";
        cin >> buscado;

        bool encontrado = false;
        for (int i = 0; i < l; i++) {
            if (nom[i] == buscado) {
                cout << "\n¡Producto encontrado!" << endl;
                cout << "Nombre: " << nom[i] << endl;
                cout << "Precio unitario: $" << precio[i] << endl;
                cout << "Cantidad vendida: " << canti[i] << endl;
                cout << "Ingreso total: $" << igre[i] << endl;
                encontrado = true;
                break;
            }
        }
        if (!encontrado) {
            cout << "El producto no se encuentra registrado en el sistema." << endl;
        }

    }   

    return 0;
}