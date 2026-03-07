#include<iostream>
#include<fstream>
using namespace std;

struct Proyecto{
    int id;
    char titulo[40];
    double presupuesto;
    int duracionMeses;
};

bool Comparar(Proyecto *P1, int n){
    for (int i = 0; i < n - 1; ++i){
        if(P1[i].id == P1[i + 1].id){
            cout << "Ya existe otro proyecto con igual id";
            
        }
    }
    return 0;
}
void Ordenar(Proyecto *P1, int n){
    for (int i = 0; i < n; ++i){
        if(P1[i].presupuesto > P1[i + 1].presupuesto){
            swap(P1[i],P1[i+1]);
        }
    }
}

int main(){
    fstream Arch("proyectos.dat",ios::in|ios::out|ios::binary);
    int a;
    int n = 100;
    int contador = 1;
    Proyecto *P1 = new Proyecto[n];
    do{
        cout << "2. Agregar |1. Mostrar |0. Salir: ";
        cin >> a;
        Ordenar(P1,n);
        if (a == 2){
            cout << "Digite el id: ";
            Arch.write(reinterpret_cast<char*>(&P1[contador]),sizeof(Proyecto));
            cin >> P1[contador].id;
            cin.ignore();
            if(Comparar(P1, contador)){
                cout << "Ya existe otro proyecto con igual id";
            }
            else{
                cout << "Digite el Titulo del Proyecto: ";
                cin.getline(P1[contador].titulo, 40);
                cout << "Digite el Presupuesto del Proyecto: ";
                cin >> P1[contador].presupuesto;
                cout << "Digite la duracion del Proyecto en meses: ";
                cin >> P1[contador].duracionMeses;
                Arch.write(reinterpret_cast<char*>(&P1[contador].id),sizeof(Proyecto));
                Arch.write(reinterpret_cast<char*>(&P1[contador].titulo),sizeof(Proyecto));
                Arch.write(reinterpret_cast<char*>(&P1[contador].presupuesto),sizeof(Proyecto));
                Arch.write(reinterpret_cast<char*>(&P1[contador].duracionMeses),sizeof(Proyecto));
                contador++;
            }
        }
        if(a == 1){
            for (int i = 0; i < contador; ++i){
                Arch.read(reinterpret_cast<char*>(&P1[contador].id),sizeof(Proyecto));
                cout << "Id " << P1[contador].id;
                Arch.read(reinterpret_cast<char*>(&P1[contador].titulo),sizeof(Proyecto));
                cout << "Titulo " << P1[contador].titulo;
                Arch.read(reinterpret_cast<char*>(&P1[contador].presupuesto),sizeof(Proyecto));
                cout << "presupuesto " << P1[contador].presupuesto;
                Arch.read(reinterpret_cast<char*>(&P1[contador].duracionMeses),sizeof(Proyecto));
                cout << "Titulo " << P1[contador].duracionMeses << endl;
            }
        }
    }while(a != 0);

    return 0;
}










































