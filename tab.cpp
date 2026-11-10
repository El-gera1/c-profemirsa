#include <iostream>
using namespace std;

int main(){
    int m[5][5];
        for(int i = 0; i < 5; i++){
            for (int j = 0; j <5; j++){
                m[i][j] = i * j;
                cout << i << " x " << j << " = " << m[i][j] << endl;
            }
            cout << endl;
        }
        return 0;
}
