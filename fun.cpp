#include <iostream>
using namespace std;

int myfuncion(int x){
    return x * 2;
}

int main(){
    for (int i = 1; i<= 5; i++){
        cout <<" doble of"<<i<< myfuncion(i)<<endl;

    }
    return 0;
}