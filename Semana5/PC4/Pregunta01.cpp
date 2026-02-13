#include<iostream>
using namespace std;

struct Polinomio{
    int n;
    int *coeficiente;
};

void Suma(Polinomio *P1, int n){
    int a = 0;
    int b = 0;
    int c = 0;
    cout << "Suma de los tres polinomios: ";
    for(int i = 0; i < n; ++i){
        a += P1[i].coeficiente[0];
        b += P1[i].coeficiente[1];
        c += P1[i].coeficiente[2];
    }
    for(int i = n - 1; i >= 0; --i){
        if(i == 0){
            cout << a<<endl;
        }
        if(i == 1){
            cout << b << "x^"<< i<< " + ";
        }
        else{
            cout << c << "x^"<< i<< " + ";
        }
    }
}

void Multipllicar(Polinomio *P1, int n){
    int a = 1;
    int b = 1;
    int c = 1;
    cout << "Producto de los tres polinomios: ";
}

int main(){
    Polinomio *P1 = new Polinomio[3];
    P1[0].n = 2;
    P1[0].coeficiente = new int[P1[0].n + 1];
    P1[0].coeficiente[0] = 3;
    P1[0].coeficiente[1] = 0;
    P1[0].coeficiente[2] = 1; 

    P1[1].n = 1;
    P1[1].coeficiente = new int[P1[1].n + 1];
    P1[1].coeficiente[0] = 5;
    P1[1].coeficiente[1] = -4;

    P1[2].n = 2;
    P1[2].coeficiente = new int[P1[2].n + 2];
    P1[2].coeficiente[0] = 1;
    P1[2].coeficiente[1] = 0;
    P1[2].coeficiente[2] = 3;

    Suma(P1,3);

    delete [] P1;
    delete [] P1[0].coeficiente;
    delete [] P1[1].coeficiente;
    delete [] P1[2].coeficiente;

    return 0;
}