#include<iostream>
using namespace std;

const int FILAS = 3;
const int COLUMNAS = 3;

void imprimirMatriz(int[][COLUMNAS]);

int main(){
    int Matriz[FILAS][COLUMNAS]={{1,2,3},{4,5,6},{7,8,9}};

    imprimirMatriz(Matriz);

    return 0;
}
void imprimirMatriz(int matriz[][COLUMNAS]){
    for(int i=0;i<FILAS;i++){
        for(int j=0;j<COLUMNAS;j++){
            cout<<matriz[i][j]<<" ";
        }
        cout<<endl;
    }
}