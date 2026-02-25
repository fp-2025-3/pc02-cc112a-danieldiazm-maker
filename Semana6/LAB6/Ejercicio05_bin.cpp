#include <iostream>
#include <fstream>
using namespace std;

void escribirFibonaciBinario() {
    long n1 = 0, n2 = 1, temp;
    int contador = 1;
    ofstream Escribir("input/fibonacci.bin", ios::binary); // ios::binary porque es un .bin

    if (!Escribir) {
        cout << "Error, no se pudo abrir fibonacci.bin";
        return;
    }

    cout << "Funcion escribirFibonacciBinario:" << endl;

    while(contador <= 20){
        Escribir.write(reinterpret_cast<char*>(&n1), sizeof(long));
        temp = n1;
        n1 = n2;
        n2 += temp;
        contador++;
    }
    Escribir.close();
    cout << "Terminos de Fibonacci escritos en el archivo correctamente." << endl << endl;
}

void leerFibonacciBinario() {
    ifstream Leer("input/fibonacci.bin", ios::binary); // ios::binary porque es un .bin
    long valor;
    int contador = 1;

    if(!Leer){
        cout << "Error, no se pudo abrir fibonacci.bin" << endl;
        return;
    }

    cout << "Funcion leerFibonacciBinario:" << endl;

    while(Leer.read(reinterpret_cast<char*>(&valor), sizeof(long)) && contador <= 20){
        cout << "Termino " << contador << ": " << valor << endl;
        contador++;
    }
    Leer.close();
}

int main() {
    escribirFibonaciBinario();
    leerFibonacciBinario();
    return 0;
}