#include<iostream>
#include<cmath>
using namespace std;

struct Termino{
    double coeficiente;
    int exponente;
};
struct Polinomio{
    Termino *terminos;
    int cantidad;
};

void crearPolinomio(Polinomio &p, int n){
    p.cantidad = n;
    p.terminos = new Termino[p.cantidad]; 
}
void leerPolinomio(Polinomio &p){
    for (int i = 0; i < p.cantidad; ++i){
        cout << "Ingrese el coeficiente y exponente del termino " << i << ": ";
        cin >> p.terminos[i].coeficiente >> p.terminos[i].exponente;
    } 
}
void mostrarPolinomio(const Polinomio &p){
    cout << "El polinomio es: ";
    for (int i = 0; i < p.cantidad; ++i){
        if(p.terminos[i].coeficiente > 0 && i > 0){
            cout << " + ";
        }
        else{
            cout << " ";
        }
        if(p.terminos[i].coeficiente != 0){
            cout << p.terminos[i].coeficiente <<"x^" << p.terminos[i].exponente;
        }
    }
    cout << endl;
}
void evaluarPolinomio(const Polinomio &p, double x){
    cout << "El resultado al evaluar es: ";
    long double resultado = 0;
    for (int i = 0; i < p.cantidad; ++i){
        resultado += p.terminos[i].coeficiente * pow(x,p.terminos[i].exponente);
    }
    cout << resultado << endl;
}
void derivarPolinomio(const Polinomio &p, Polinomio &der){
    int ExpNulos = 0;

    for (int i = 0; i < p.cantidad; ++i) {
        if (p.terminos[i].exponente != 0) {
            ExpNulos++;
        }
    }
    crearPolinomio(der, ExpNulos);

    int j = 0;
    for (int i = 0; i < p.cantidad; ++i){
        if (p.terminos[i].exponente != 0) {
            der.terminos[j].coeficiente = p.terminos[i].coeficiente * p.terminos[i].exponente;
            der.terminos[j].exponente = p.terminos[i].exponente - 1;
            j++;
        }
    }
}
void liberarPolinomio(Polinomio &p){
    delete [] p.terminos;
    p.terminos = nullptr;
}

int main(){
    Polinomio P1,P2;
    int n;
    double x;
    cout << "Ingrese la cantidad de terminos: ";
    cin >> n;
    crearPolinomio(P1,n);
    leerPolinomio(P1);
    mostrarPolinomio(P1);
    cout << "Digite el valor al evaluar al polinomio: ";
    cin >> x;
    evaluarPolinomio(P1,x);
    cout << "Derivamos el polinomio: " << endl;
    derivarPolinomio(P1,P2);
    liberarPolinomio(P1);
    mostrarPolinomio(P2);
    liberarPolinomio(P2);

    return 0;
}