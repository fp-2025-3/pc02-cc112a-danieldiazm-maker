#include<iostream>
#include<cmath>
#include<fstream>
using namespace std;

int main(){
    ofstream Escribir("output/grafico.txt");

    int puntos = 80, filas = 21, columnas = 80, contador = 1, Var_Vertical = 0.1;
    long Var_Horisontal = 0.025 * M_PI;

    if(!Escribir){
        cout << "ERROR: No se puedo abrir corectamente grafico.txt" << endl;
    }

    while(contador <= puntos){
        long a = sin(5 * Var_Horisontal * contador);
        int b = 0;
        Escribir << "*" ;
        contador++;
    }

    return 0;
}