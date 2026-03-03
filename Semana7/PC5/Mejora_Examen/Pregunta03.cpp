#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

void liberarLienzo(char** lienzo, int filas){
    for(int i = 0; i < filas; i++){
        delete[] lienzo[i];
    }
    delete[] lienzo;
}

int main() {
    const int FILAS = 21;
    const int COLUMNAS = 80;

    char** lienzo = new char*[FILAS];
    for(int i = 0; i < FILAS; i++){
        lienzo[i] = new char[COLUMNAS];
    }

    for(int i = 0; i < FILAS; i++){
        for(int j = 0; j < COLUMNAS; j++){
            if (i == 10){
                *(*(lienzo + i) + j) = '-'; // Eje X
            }
            else if (j == 0){
                *(*(lienzo + i) + j) = '|'; // Eje Y
            }
            else{
                *(*(lienzo + i) + j) = ' '; // Espacio vacío
            }
        }
    }

    for(int j = 0; j < COLUMNAS; j++){ // Evaluamos y = sin(5x)
        double x = (double)j * (2.0 * M_PI / (COLUMNAS - 1));
        double y_val = sin(3 * x);

        int fila = (int)round(10 - (y_val * 10)); // Redondeo

        if(fila >= 0 && fila < FILAS){
            *(*(lienzo + fila) + j) = '*';
        }
    }

    ofstream grafica("output/grafico.txt");
    if(!grafica){
        cout << "Error al abrir archivo";
        liberarLienzo(lienzo, FILAS);
        return 1;
    }

    for(int i = 0; i < FILAS; i++){
        for(int j = 0; j < COLUMNAS; j++){
            grafica << lienzo[i][j];
        }
        grafica << endl;
    }

    grafica.close();
    cout << "Grafico generado exitosamente." << endl;

    liberarLienzo(lienzo, FILAS); // Liberacion de memoria

    return 0;
}