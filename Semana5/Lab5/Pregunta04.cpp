#include<iostream>
using namespace std;

struct Polinomio{
    int n;
    int *coeficiente = new int[n];
};

void Rellenar(Polinomio *P1){
    cout<<"Ingrese el grado del primer polinomio: "; 
    cin >> P1[0].n;
    for(int i = 0; i < P1[0].n; i++){
        cout << "Ingrese el coeficiente de x^" <<  P1[0].n - i << ": ";
        cin >> P1[0].coeficiente[i];
    }
    cout<<"Ingrese el grado del segundo polinomio: ";
    cin >> P1[1].n;
    for(int i = 0; i < P1[1].n; i++){
        cout << "Ingrese el coeficiente de x^" <<  P1[1].n - i << ": ";
        cin >> P1[1].coeficiente[i];
    }
}

int main(){
    Polinomio *P1 = new Polinomio[2];
    Rellenar(P1);

    return 0;
}