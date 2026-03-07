/*
Ejercicio 1
Se desea gestionar estudiantes, donde no se conoce de antemano cuántos habrá.

Cada estudiante tiene código y promedio

Escribir un programa que:

a) Solicitar al usuario la cantidad N de estudiantes

b) Reservar memoria dinámicamente para los N estudiantes

c) Leer los datos

d) Mostrar únicamente los aprobados (>= 10)

e) Liberar memoria correctamente
*/
#include<iostream>
using namespace std;

struct Estudiantes{
    int codigo;
    double promedio;
};

void LeerDatos(Estudiantes *e1,int n){
    for(int i = 0; i < n; i++){
        cout << "Estudiante "<<i+1<<":"<<endl;
        cout << "Codigo: ";
        cin >> e1[i].codigo;

        do{
        cout << "Promedio: ";
        cin >> e1[i].promedio; // (*(e1+i)).promedio = e1[i].promedio

        if(e1[i].promedio > 20){
            cout << "ERROR: El promedio no puede ser mayor a 20"<<endl;
        }

        }while(e1[i].promedio > 20);
        
        cout << endl;
    }
}

void Aprobados(Estudiantes * &e1,int &n){ 
    int cont = 0;
    for(int i = 0; i < n; i++){
        if(e1[i].promedio >= 10){
            cont++;
        }
    }

    Estudiantes *e2 = new Estudiantes[cont];
    int j = 0;

    for(int i = 0; i < n; i++){
        if(e1[i].promedio >= 10){
            e2[j] = e1[i];
            j++;
        }
    }
    delete [] e1;
    e1 = e2;
    n = cont;
    /*
    delete [] e2 
    Cuando termina el programa al ser un void no retorna nada entonces se libera la memoria guardad de e2
    */
}

void Imprimir(Estudiantes *e1,int n){
    cout << "Los aprobados son: " << endl;
    for(int i = 0; i < n; i++){
        cout << "Codigo: " << e1[i].codigo << " | " << "Promedio: " << e1[i].promedio <<endl;
    }
}

int main(){
    int n = 0;
    do{
    cout << "Digite el numero de estudiantes: ";
    cin >> n;
    if(n < 1){
        cout << "El numero de estudiantes tiene que se mayor o igual a 1";
    }
    }while(n < 1);

    Estudiantes *e1 = new Estudiantes[n];

    LeerDatos(e1,n);
    Aprobados(e1,n);
    Imprimir(e1,n);
    
    delete [] e1;

    return 0;
}