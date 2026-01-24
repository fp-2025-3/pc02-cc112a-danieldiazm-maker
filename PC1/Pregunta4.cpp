#include<iostream>
using namespace std;

void Intercaladora(int[],int[],int[],int,int);
void Indices(int);
void Imprimir(int[],int);
int busquedabinaria(int[],int,int);
void Burbuja(int[],int);

int main(){
    int A[]={10,8,6,4};
    int B[]={9,7,6,5};
    const int n = sizeof(A)/sizeof(A[0]);
    int C[2*n];
    int i=0;
    int valor=0;
    int x = 0;
    cout<<"Lista Intercalada L: "<<endl;

    Indices(2*n);
    cout<<endl;
    Intercaladora(A,B,C,2*n,i);
    cout<<endl;

    Burbuja(C,2*n);
    do{
    cout<<"Ingrese numero a buscar: ";
    cin>>valor;
    int x = busquedabinaria(C,2*n,valor);
    if(x ==-1){
        cout<<"El numero no se encuentra."<<endl;
    }else{
        cout<<"\nEl numero se encuentra en el indice "<<busquedabinaria(C,2*n,valor)<<endl;
    }
    }while(x !=-1);

    return 0;
}
void Intercaladora(int A[],int B[],int C[],int n,int i){
    if(i==n){
        Imprimir(C,n);
        return;
    }
    if(i%2 == 0){
        C[i]=B[i/2];
    }
    else if(i%2 == 1){
        C[i]=A[(i+1)/2-1];
    }
    i++;
    Intercaladora(A,B,C,n,i);
}
void Imprimir(int arr[],int m){
    for(int i=0;i<m;i++){
        cout<<arr[i]<<" ";
    }
}
int busquedabinaria(int arr[],int n,int valor){
    int low=0; int high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(valor==arr[mid]){
            return mid;
        }
        else if(valor>arr[mid]){
            low=mid+1;
        }
        else if(valor<arr[mid]){
            high=mid-1;
        }
    }
    return -1;
}
void Indices(int n){
    for(int i=0;i<n;i++){
        cout<<i<<" ";
    }
}
void Burbuja(int C[],int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(C[j]>C[j+1]){
                swap(C[j],C[j+1]);
            }
        }
    }
}