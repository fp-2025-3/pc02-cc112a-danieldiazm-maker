#include<iostream>
using namespace std;

void BusquedaDominante(int[],int);
void ElementosDominantes(int[],int);

int main(){
    int A[]={5,3,8,6,2,11};
    int n = sizeof(A)/sizeof(A[0]);

    BusquedaDominante(A,n);
    cout<<"Los elementos Dominantes son: ";
    ElementosDominantes(A,n);

    return 0;
}
void BusquedaDominante(int arr[],int n){
    if(n==1){
        return;
    }
    else if(arr[n-1]<arr[n]){
        arr[n-1]=-1;
    }
    BusquedaDominante(arr,n-1);
    return;
}
void ElementosDominantes(int arr[],int n){
    if(arr[n] != -1){
        cout<<arr[n]<<" ";
    }
    ElementosDominantes(arr,n-1);
    return;
}