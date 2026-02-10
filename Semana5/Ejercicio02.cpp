/*
Ejercicio 2
Implementar una agenda de contactos.

Cada contacto tiene nombre y fecha de nacimiento (estructura Fecha)

La cantidad de contactos es desconocida:

a) Reservar memoria dinámica para N contactos 
b) Leer datos 
c) y mostrar los nacidos en un año específico

*/
#include<iostream>
using namespace std;


struct Fecha{
    int dia;
    int mes;
    int anio;
};

struct Contactos{
    char nombre[50];
    Fecha nacimiento;
};

void LeerDatos(Contactos *c1,int n){
    for(int i = 0; i < n; i++){
        cout << "Contacto "<<i+1<<":"<<endl;
        cout << "nombre: ";
        cin >> c1[i].nombre;

        cout << "Fecha de nacimiento: "<<endl;

        cout << "Dia: ";
        cin >> c1[i].nacimiento.dia; // (*(e1+i)).promedio = e1[i].promedio

        cout << "Mes: ";
        cin >> c1[i].nacimiento.mes;

        cout << "Anio: ";
        cin >> c1[i].nacimiento.anio;
        
        cout << endl;
    }
}

void burburja(Contactos *c1,int n){
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < n-1-i; j++){
            if(c1[j].nacimiento.anio > c1[j+1].nacimiento.anio){
                swap(c1[j].nacimiento.anio , c1[j+1].nacimiento.anio);
                swap(c1[j].nacimiento.mes , c1[j+1].nacimiento.mes);
                swap(c1[j].nacimiento.dia , c1[j+1].nacimiento.dia);
                swap(c1[j].nombre , c1[j+1].nombre);
            }
        }
    }
}

void Imprimir(Contactos *c1,int n){
    cout << "Los nacidos por año son: " << endl;
    for(int i = 0; i < n; i++){
        cout << "Año: " << c1[i].nacimiento.anio << " | " << "nombre: " << c1[i].nombre << endl;
    }
}

int main(){
    int N = 0;
    do{
    cout << "Digite el numero de contactos: ";
    cin >> N;
    if(N < 1){
        cout << "El numero de constactos tiene que se mayor o igual a 1";
    }
    }while(N < 1);

    Contactos *c1 = new Contactos[N];

    LeerDatos(c1,N);
    burburja(c1,N);
    Imprimir(c1,N);


    delete [] c1;

    return 0;
}