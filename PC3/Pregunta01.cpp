#include<iostream>
using namespace std;


void Separar_numeros(char *texto, char* numeros[]){
    char* p = texto;
    int i = 0;
    while(*p != '\0'){
        if( (*p != ' ' && *p != ',') && (p == texto || *(p-1) == ' ') ){
            numeros[i] = p;
            i++;
        }
        p++;
    }
}

void suma(char* numeros[], int sumas[]){
    for(int i = 0;i < 4;i++){
        sumas[i] = *numeros[i] + *numeros[i+1]; // Falto convertir de char a int
    }
    for(int i = 4;i < 7;i++){
        sumas[i] = *numeros[i] + *numeros[i+2];
    }
    for(int i = 7;i < 9;i++){
        sumas[i] = *numeros[i] + *numeros[i+3];
    }
    for(int i = 9;i < 10;i++){
        sumas[i] = *numeros[i] + *numeros[i+4];
    }
}
void Igualdad(int sumas[],int n){
    for(int i=0;i < 10; i++){
        if(n == sumas[i]){
            cout<<"SI existen 2 numeros con suma "<<n<<endl;
        }
        else{
            cout<<"NO existen 2 numeros con suma "<<n<<endl;
        }
    }
}

int main(){
    char texto[] = "1, 2, 4, 7, 11";
    char *numeros[10];
    int sumas[10];
    int a = 15; // Variable a encontrar
    int b = 10;
    cout<<"Cadena original: "<<endl;
    cout<<texto<<endl;
    Separar_numeros(texto,numeros);
    suma(numeros,sumas);
    Igualdad(sumas,a);
    Igualdad(sumas,b);
}