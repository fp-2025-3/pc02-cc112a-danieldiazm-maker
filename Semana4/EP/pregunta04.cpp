#include<iostream>
using namespace std;

void agregar_datos(int* codigos,double* promedios){
    for(int i = 0;i < 5 ;i++){
        cout<<"Ingrese el codigo del estudiante "<< i+1 <<": ";
        cin>>*(codigos+i);
    }
    
    for(int i = 0;i < 5 ;i++){
        cout<<"Ingrese el promedio del estudiante "<< i+1 <<": ";
        cin>>*(promedios+i);
    }
}
void registrados(int* codigos,double* promedios){
    cout<<"Estudiantes registrados:"<<endl;
    for(int i=0;i<5;i++){
        cout<<"Codigo: "<<*(codigos+i)<<" Promedio: "<<*(promedios+i)<<endl;
    }
}
void Eliminar(double* promedios){
    for(int i = 0;i < 5 ;i++){
        if(*(promedios+i) < 10){
            *(promedios+i) = -1; 
        }
    }
}
void aprobados(int* codigos,double* promedios){
    cout<<"\nFiltrando estudiantes desaprobados...\n\n";
    cout<<"Estudiantes aprobados: "<<endl;
    for(int i=0;i<5;i++){
        if(*(promedios+i)!=-1){
            cout<<"Codigo: "<<*(codigos+i)<<" Promedio: "<<*(promedios+i)<<endl;
        }
    }
}

int main(){
    int* codigos = new int[5];
    double* promedios = new double[5];
    agregar_datos(codigos,promedios);
    registrados(codigos,promedios);
    Eliminar(promedios);
    aprobados(codigos,promedios);
    delete [] codigos;
    delete [] promedios;

    return 0;
}