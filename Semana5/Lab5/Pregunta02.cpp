#include<iostream>
#include<cmath>
using namespace std;

struct Punto{
    int x;
    int y;
    int z;
};

void Rellenar(Punto *P2){
    cout << "Ingrese las coordenas del primer punto: " << endl;
    cout << "X: "; cin >> P2[0].x;
    cout << "Y: "; cin >> P2[0].y;
    cout << "Z: "; cin >> P2[0].z;
    cout << "Ingrese las coordenas del segundo punto: " << endl;
    cout << "X: "; cin >> P2[1].x;
    cout << "Y: "; cin >> P2[1].y;
    cout << "Z: "; cin >> P2[1].z;
}

void Distancia(Punto *P2){
    double potencia = pow(P2[0].x - P2[1].x,2) + pow(P2[0].y - P2[1].y,2) + pow(P2[0].z - P2[1].z,2);
    double raiz = sqrt(potencia);
    cout << "La distancia entre los dos puntos es: " << raiz << endl;
}

int main(){
    Punto *P2 = new Punto[2];
    Rellenar(P2);
    Distancia(P2);

    delete [] P2;

    return 0;
}