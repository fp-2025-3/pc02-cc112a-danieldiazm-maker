#include<iostream>
#include<cstring>
using namespace std;

void LeerDatos(char *corredores[],int Tiempo[],int n){
    for(int i=0;i<5;i++){
        cout<<"Nombre del corredor "<<i+1<<": ";
        cin.getline(corredores[i],20,'\n');
        cout<<"\nTiempo (en segundos): ";
        cin>>Tiempo[i];
    }
}

void Burburja(int arr[],int n){
    for(int i = 0;i < 5 - 1; i++){
        for(int j = 0;j < 5 - 1 - i;j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
}

void RANKING(char *corredores[],int Tiempo[],int n){
    for(int i=0;i<5;i++){
        cout<<i+1<<". "<<corredores[i]<<" - "<<Tiempo[i] <<" Segundos"<<endl;
    }
}



int main(){
    int n = 5;
    cout<<"Ingrese numero de corredores: 5"<<endl;
    char *corredores[5];
    int Tiempo[5];
    LeerDatos(corredores,Tiempo,5);
    Burburja(Tiempo,5);
    RANKING(corredores,Tiempo,5);
    return 0;
}