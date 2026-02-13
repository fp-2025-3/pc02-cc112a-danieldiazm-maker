#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;

struct Futbol{
    int pais;
    int PG;
    int PE;
    int PP;
    int GF;
    int GC;
    int Puntaje;
    int DG;
    double Rendimiento;
};

void Rellenar(Futbol *F1,int n){
    srand(time(NULL));
    for(int i = 0;i < n; i++){
        int gf = 0;
        int gc = 0;
        int pg = 0;
        int pe = 0;
        int pp = 0;
        for(int j = 0;j < 100;j++){
            int a = 0 + rand() % (5 + 1 - 0);
            int b = 0 + rand() % (5 + 1 - 0);
            if(a > b){
                pg++;
            }
            if(a == b){
                pe++;
            }
            if(a < b){
                pp++;
            }
            gf += a;
            gc += b;
        }
        F1[i].PG = pg;
        F1[i].PE = pe;
        F1[i].PP = pp;
        F1[i].GF = gf;
        F1[i].GC = gc;
        F1[i].DG = gf - gc;
        F1[i].Puntaje = F1[i].PG * 3 + F1[i].PE;
        F1[i].Rendimiento = F1[i].Puntaje / 3.0;
        F1[i].pais = i + 1;
    }
}

void Ordenar(Futbol *F1,int n){
    for(int i = 0;i < n - 1;i++){
        for(int j = 0;j< n -1 -i;j++){
            if(F1[j].Puntaje < F1[j+1].Puntaje){
                swap(F1[j],F1[j+1]);
            }
            if(F1[j].Puntaje == F1[j+1].Puntaje){
                if(F1[j].DG < F1[j+1].DG){
                    swap(F1[j],F1[j+1]);
                }
            }
        }
    }
}

void Imprimir(Futbol *F1,int n){
    cout << "Seleccion"<< "\tPG"<< "\tPE" << "\tPP" << "\tGF" << "\tGC" << "\tDG" << "\tPts" << "\tRend(%)"<< endl;
    for(int i = 0; i < n; i++){
        cout<<"Pais_"<<F1[i].pais<<"\t\t"<<F1[i].PG<<"\t"<<F1[i].PE<<"\t"<<F1[i].PP<<"\t"<<F1[i].GF<<"\t"<<F1[i].GC<<"\t"<<F1[i].DG<<"\t"<<F1[i].Puntaje<<"\t"<<F1[i].Rendimiento<<endl;
    }
    cout<< "CAMPEON: "<<"Pais_"<< F1[0].pais <<" | "<< "Puntaje: " << F1[0].Puntaje << " | " << F1[0].DG << " | " << F1[0].Rendimiento<< "%"<< endl;
}

int main(){
    Futbol *F1 = new Futbol[5];

    Rellenar(F1,5);
    Ordenar(F1,5);
    Imprimir(F1,5);

    delete [] F1;

    return 0;
}
