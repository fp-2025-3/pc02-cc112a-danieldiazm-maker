#include<iostream>
using namespace std;

struct Polinomio{
    int n;
    int *coeficiente;
};

void MostrarPolinomio(const char* nombre, Polinomio P1){ // Una forma de nombrar una cadena de caracteres con un const char*
    cout << nombre << ": ";
    for(int i = 0; i <= P1.n; i++){
        if(P1.coeficiente[i] != 0){
            cout << P1.coeficiente[i];
        }
        
        if(i < P1.n && P1.coeficiente[i] != 0){ // Esto se pone porque cuanod el coeficiente sea 0 no queremos que se imprima el x^ (P1.n - i)
            if(P1.coeficiente[i+1] >= 0){
                cout << "x^" << P1.n - i << " + ";
            }
            else{
                cout << "x^" << P1.n - i << " ";
            }
        }
    }
    cout << endl;
}

void Suma(Polinomio *P, int cantidad){
    int gradoMax = 0; // Inicializamos en 0
    for(int i = 0; i < cantidad; i++){ // Con esto buscamos el grado maximo de los tres polinomios
        if (P[i].n > gradoMax){
            gradoMax = P[i].n;
        }
    }

    int *resultado = new int[gradoMax + 1];
    for(int i = 0; i <= gradoMax; i++){ // Reservamos memoria en un nuevo arreglo dinamico para el resultado de la suma
        resultado[i] = 0;
    }

    for(int i = 0; i < cantidad; i++){
        for(int j = 0; j <= P[i].n; j++){
            resultado[gradoMax - (P[i].n - j)] += P[i].coeficiente[j]; // Se va sumando cada coeficiente del polinomio al arreglo dinamicro creado
        }
    }

    cout << "Suma de los tres polinomios: ";
    for(int i = 0; i <= gradoMax; i++){
        if(resultado[i] != 0){
            cout << resultado[i];
        }
        
        if(i < gradoMax && resultado[i] != 0){ // Se imprime el polinomio resultante de la suma
            if(resultado[i+1] >= 0){
                cout << "x^" << gradoMax - i << " + ";
            }
            else{
                cout << "x^" << gradoMax - i << " "; 
            }
        }
    }
    cout << endl;
    delete[] resultado; // Se libera
}

void MultiplicarTres(Polinomio *P){
    int gradoTotal = P[0].n + P[1].n + P[2].n; // El grado final es la suma de los grados de los tres polinomios
    
    int gradoTemp = P[0].n + P[1].n; // Primero mutiplicamos el primer y segundo polinomio (Divide y venceras)
    int *temporal = new int[gradoTemp + 1]; // arreglo dinamico para Polinomio 1 y 2
    for(int i = 0; i <= gradoTemp; i++){ // Inicializamos en 0
        temporal[i] = 0;
    }

    for(int i = 0; i <= P[0].n; i++){
        for(int j = 0; j <= P[1].n; j++){
            temporal[i + j] += P[0].coeficiente[i] * P[1].coeficiente[j]; // Multiplicamos uno a uno (haciendo ditrivutiva) y sumamos al 0 inicial 
        }
    }

    int *resultado = new int[gradoTotal + 1]; // arreglo dinamico para Polinomio total
    for(int i = 0; i <= gradoTotal; i++){
        resultado[i] = 0;
    }

    for(int i = 0; i <= gradoTemp; i++){
        for(int j = 0; j <= P[2].n; j++){
            resultado[i + j] += temporal[i] * P[2].coeficiente[j]; // Multiplicamos el anterior resultado con el tercer polinomio uno a uno (haciendo ditrivutiva) y sumamos al 0 inicial 
        }
    }

    cout << "Producto de los tres polinomios: ";
    for(int i = 0; i <= gradoTotal; i++){
        if(resultado[i] != 0){
            cout << resultado[i];
        }
        
        if(i < gradoTotal && resultado[i] != 0){ // Imprimimos el resultado de la multiplicacion de los tres poliniomio 
            if(resultado[i+1] >= 0){
                cout << "x^" << gradoTotal - i << " + "; 
            }
            else{
                cout << "x^" << gradoTotal - i << " "; 
            }
        }
    }
    cout << endl;

    delete[] temporal; // Se libera 
    delete[] resultado; // Se libera 
}

int main(){
    Polinomio *P1 = new Polinomio[3];
    P1[0].n = 2;
    P1[0].coeficiente = new int[P1[0].n + 1]{1,0,3}; // Otra forma de definir y resevar memoria

    P1[1].n = 1;
    P1[1].coeficiente = new int[P1[1].n + 1]{-4,5};

    P1[2].n = 2;
    P1[2].coeficiente = new int[P1[2].n + 2]{3,0,1};

    MostrarPolinomio("Polinomio 1",P1[0]);
    MostrarPolinomio("Polinomio 2",P1[1]);
    MostrarPolinomio("Polinomio 3",P1[2]);

    Suma(P1,3);
    MultiplicarTres(P1);

    for(int i = 0; i < 3; i++){
        delete[] P1[i].coeficiente;
    }
    delete [] P1;

    return 0;
}