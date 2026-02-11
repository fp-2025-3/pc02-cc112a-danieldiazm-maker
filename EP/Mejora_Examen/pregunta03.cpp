#include<iostream>
using namespace std;

const int N = 4;

int sumaFila(int (*M)[N], int f){
    int suma = 0;
    for (int j = 0; j < N; j++){
        suma += *(*(M + f) + j);  // Sumando los numeros de la fila f
    }
    return suma;
}

bool esFilaDominanteEstricta(int (*M)[N], int f){
    bool Estricto = false;

    for (int j = 0; j < N; j++){
        for (int i = 0; i < N; i++){ // Vemos si es mayor o igual a todos en su columna
            if (i != f && *(*(M + i) + j) > *(*(M + f) + j)){
                return false; // Si hay un elemento mayor en la columna, ya no cumple el para todo j y retornamos
            }
        }
        
        bool esEstrictoEnEstaCol = true; // Inicializamos en true 
        for(int i = 0; i < N; i++){ // Vemos si al menos una columna es estrictamente mayor que todos
            if(i != f && *(*(M + i) + j) >= *(*(M + f) + j)){
                esEstrictoEnEstaCol = false; // Si una fila es estrictamente mayor se quedara en true, caso contrario false
            }
        }
        if(esEstrictoEnEstaCol){ // Vemos si es verdadero en caso si damos es valor true y despues retornamos
            Estricto = true;
        }
    }

    return Estricto; // Finalmento solo sera dominante estricta si se cumplieron ambas reglas
}

bool esFilaFuertementeDominante(int (*M)[N], int f){

    if(!esFilaDominanteEstricta(M, f)){ // Como en las condiciones se debe cumplir que sea Dominante estricta, caso contrario retornamos false
        return false;
    }

    int sumaActual = sumaFila(M, f); // Ahora damos el valor de la suma de elementos de la fila f
    for(int i = 0; i < N; i++){
        if (i != f && sumaActual <= sumaFila(M, i)){ // Comprobamos si esta existe al menos una suma en otra fila i que sea mayor, a la sumafila_f 
            return false; // En ese caso retornamos false
        }
    }
    return true; // Si no hubo un retorno anterior ---> es Fuertemente Dominante
}

int main() {
    int M[N][N] = {{2, 3, 1, 4},{1, 2, 3, 2},{5, 6, 7, 8},{0, 1, 2, 1}};

    cout << "Fila\tDominante Estricta\tFuertemente Dominante" << endl; // \t es para tabulador \n es para salto de linea
    cout << "------------------------------------------------------" << endl;

    for (int i = 0; i < N; i++){
        cout << i << "\t";
        
        if (esFilaDominanteEstricta(M, i)) cout << "SI\t\t\t"; 
        else cout << "NO\t\t\t";

        if (esFilaFuertementeDominante(M, i)) cout << "SI" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}