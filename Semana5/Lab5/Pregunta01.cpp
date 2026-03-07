#include<iostream>
using namespace std;

struct Estudiante{
    char nombre[25];
    int nota;
};

void Rellenar(Estudiante *E1,int n){
    for (int i = 0; i < n; i++){
        cout << "Ingrese el nombre del estudiante " << i+1 << ": ";
        cin.ignore();
        cin.getline(E1[i].nombre,24);
        cout << "Ingrese la nota del estudiante " << i+1 << ": ";
        cin >> E1[i].nota;
    }
}

void OrdenarBurbuja(Estudiante *E1,int n){
    for (int i = 0; i < n - 1; i++){
        for (int j = 0; j < n - 1 - i; j++){
            if (E1[j].nota < E1[j+1].nota){
                swap(E1[j].nota , E1[j+1].nota);
                swap(E1[j].nombre , E1[j+1].nombre);
            }
        }
    }
}

void Mayornota(Estudiante *E1){
    int i = 0;
    cout << "El estudiante con la mayor nota es: " << E1[i].nombre << endl;
    cout << "Nota: " << E1[i].nota << endl;
}

int main(){
    int n = 0;
    cout << "Ingrese la cantidad de estudiantes: "; cin >> n;
    Estudiante *E1 = new Estudiante[n];
    Rellenar(E1,n);
    OrdenarBurbuja(E1,n);
    Mayornota(E1);

    delete [] E1;

    return 0;
}