#include <iostream>
using namespace std;

void Imprimir(int (*Matriz)[5],int n,int m){  //M[i][j]==*(*(M+i)+j)
    for(int i = 0 ; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(*(*(Matriz+i)+j) >= 0){
                cout<<" ";
            }
            cout<<*(*(Matriz+i)+j)<<"\t";
        }
        cout<<endl;
    }
}
int SumaSubmatriz(int (*Matriz)[5],int i1, int j1, int i2, int j2){
    int suma=0;
    for (int i = i1; i <= i2; ++i) {
        for (int j = j1; j <= j2; ++j) {
            suma += *(*(Matriz+i)+j);
        }
    }
    return suma;
}
int main(){
    int Matriz[][5]={{-2,1,-3,4,-1},{2,3,-2,1,-5},{-1,4,2,-3,2},{1,-2,3,4,-1}};
    int (*p)[5]=Matriz;
    int n = sizeof(Matriz)/sizeof(*Matriz);
    int m = sizeof(*p)/sizeof(*(*p));
    int i1, j1, i2, j2; 
    char basura;

    cout<<"Matriz:"<<endl;
    Imprimir(p,n,m);
    cout<<endl;

    cout<<"Submatriz de suma maxima: "<<endl;

    cout << "Ingrese esquina superior izquierda: ";
    cin >> basura >> i1 >> basura >> j1 >> basura;
    
    cout << "Ingrese esquina inferior derecha: ";
    cin >> basura >> i2 >> basura >> j2 >> basura;

    cout << "Suma maxima: "<<SumaSubmatriz(p,i1,j1,i2,j2)<<endl;
    
    return 0;
}