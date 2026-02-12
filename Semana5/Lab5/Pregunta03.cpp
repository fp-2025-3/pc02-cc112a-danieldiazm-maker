#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;

struct Seleccion{
    int PG;
    int PE;
    int PP;
    int Puntaje;
    double Rendimiento;
};

void Rellenar(Seleccion *S1,int n){
    srand(time(NULL));
    for (int i = 0; i < n; i++){
        S1[i].PG = 0 + rand()%(100 + 1 - 0); // Limite_Inferior + rand() % (Limite_Superior + 1 -Limite_Inferior)
        S1[i].PE = 0 + rand()%(100 - S1[i].PG + 1 - 0);
        S1[i].PP = 100 - (S1[i].PG + S1[i].PE);
        S1[i].Puntaje = 3 * S1[i].PG + S1[i].PE;
        S1[i].Rendimiento = S1[i].Puntaje / 3.0;
    }
}

void Imprimir(Seleccion *S1,int n){
    cout << "Seleccion" << "\t\t\tPG" << "\tPP" << "\tPE" << "\tPuntaje" << "\t\tRendiemiento" << endl;
    for (int i = 0; i < n; i++){
        cout << "Pais_Seleccion " << i+1 << "\t\t" << S1[i].PG << "\t" << S1[i].PP << "\t" << S1[i].PE << "\t" << S1[i].Puntaje << "\t\t" << S1[i].Rendimiento << endl;
    }
}

void Rendimiento(Seleccion *S1, int n){
    int r = 0;
    int pos = -1;
    for (int i = 0; i < n; i++){
        if(r < S1[i].Rendimiento){
            r = S1[i].Rendimiento;
            pos = i;
        }
    }
    cout << "La seleccion con mejor rendimiento es: Seleccion " << pos + 1 << " Rendimiento: " << S1[pos].Rendimiento << endl;

}

int main(){
    int n = 1000;

    Seleccion *S1 = new Seleccion[n];
    Rellenar(S1,n);
    Imprimir(S1,n);
    Rendimiento(S1,n);

    delete [] S1;

    return 0;
}