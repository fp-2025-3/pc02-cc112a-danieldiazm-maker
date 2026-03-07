#include<iostream>
#include<fstream>
using namespace std;

void escribirFibonaciBinario(){
    long n1 = 0, n2 = 1, temp;
    int contador = 1;
    ofstream Escribir("input/fibonacci.txt");

    if(!Escribir){
        cout << "Error, no se pudo abrir fibonacci.txt";
        return;
    }

    cout << "Funcion escribirFibonacciBinario:" << endl;

    while(contador <= 20){
        Escribir << n1 << endl;
        temp = n1;
        n1 = n2;
        n2 += temp;
        contador++;
    }
    Escribir.close();
    cout << "Terminos de Fibonacci escritos en el archivo correctamente." << endl << endl;
}

void leerFibonacciBinario(){
    ifstream Leer("input/fibonacci.txt");
    long valor;
    int contador = 1;

    if(!Leer){
        cout << "Error, no se pudo abrir fibonacci.txt" << endl;
        return;
    }

    cout << "Funcion leerFibonacciBinario:" << endl;

    while(Leer >> valor && contador <= 20){ // Con Leer logramos logramos abrir fibonacci.txt y con esto leemos la primera linea en valor, despues lo imprimimos y asi ..,
        cout << "Termino " << contador << ": " << valor << endl;
        contador++;
    }
    Leer.close();
}


int main(){
    escribirFibonaciBinario();
    leerFibonacciBinario();
    return 0;
}