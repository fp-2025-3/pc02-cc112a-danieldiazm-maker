#include<iostream>
using namespace std;

void Imprimir(int[],int);

int main(){
    int n=0;
    char Alumno[30];
    double promedios[30];
    char estados[30];
    int notas[30][5];

    do{
    cout<<"Ingrese la cantidad de alumnos (5-30): ";
    cin>>n;
    }while(n<5 && n>30);
    
    return 0;
}
void Imprimir(int arr[],int m){
    for(int i=0;i<m;i++){
        cout<<arr[i]<<" ";
    }
}