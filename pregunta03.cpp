#include <iostream>
using namespace std;

void Columna(int (*B)[4][5],int Aux,int fila,int columna){ // B[i] == *(B+i)
    for(fila=0;fila<4;++fila){
        for(int columna = 0;columna<5;++columna){
            if( (*B)[fila][columna] >= (*B)[fila+1][columna]){
                Aux = fila;
            }
        }
        cout<<"Pico en("<<fila<<","<<columna<<"): "<<Aux<<endl;
    }
    return;
}

int main() {
    int A[4][5]={{3,3,3,3,3},{3,4,4,2,3},{3,4,5,4,3},{3,3,3,3,3}};
    int (*B)[4][5] = &A;

    Columna(B,0,0,0);

    return 0;
}