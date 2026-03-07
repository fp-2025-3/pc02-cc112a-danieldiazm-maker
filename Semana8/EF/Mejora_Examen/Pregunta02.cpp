#include<iostream>
#include<cmath>
using namespace std;

struct Punto{
    double x;
    double y;
};

void leerPunto(Punto *p){ // Correcion moviendo las funciones
    cout << "Digite el punto en x: ";
    cin >> p -> x;
    cout << "Digite el punto en y: ";
    cin >> p -> y;
}
double distanciaOrigen(const Punto* p){
    double D = 0;
    D = sqrt(pow(p->x , 2) + pow(p->y , 2));
     return D;
}
Punto* masLejano(Punto* p1, Punto* p2){
    if(distanciaOrigen(p1) >= distanciaOrigen(p2)){
        return p1;
    }
    else{
        return p2;
    }
}

int main(){
    Punto P1;
    Punto P2;
    cout << "Leyendo P1: " << endl;
    leerPunto(&P1);
    cout << "Leyendo P2: " << endl;;
    leerPunto(&P2);
    // Creamos una variable en donde guardamos el retorno para mejor lectura del codigo

    Punto* lejano = masLejano(&P1,&P2);

    cout << "Las coordenadas del puntero mas lejano son: " << endl << "x: " << lejano->x << endl << "y: " << lejano->y << endl;
    return 0;
}