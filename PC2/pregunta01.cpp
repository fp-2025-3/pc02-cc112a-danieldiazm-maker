#include <iostream>
using namespace std;

// Complete la funcion que calcula la derivada de orden k de un polinomio
// Usar EXCLUSIVAMENTE punteros (NO indices)

void derivadaK(
    const double* coef, //
    int grado, int k,   //
    double* res,        //
    int& gradoRes       //
) {
        const double *coeficiente = coef;
        double *resultado = res;

        for(int i = 0;i <= grado; ++i){
            *(resultado+i)=*(coeficiente+i);
        }

        for (int i = k; i <= grado; ++i) {
        double temp = *(resultado + i);    //Coeficiente al inicio
        
            for (int j = 0; j < k; ++j){    //Iteraciones para obtener el coeficiente despues de derivar k veces
              temp *= (i - j);
            }
        
            *(resultado + (i - k)) = temp;  //Posicionando el coeficiente en su posicion despues de derivar k veces
        }

        for (int i = (grado - k + 1); i <= grado; i++) {
            *(resultado + i) = 0;   //Dando valor 0 a los coeficientes que se vuelven nulos despues de la k-esima derivada
        }

        gradoRes = grado - k;

    }




    // Complete la función auxiliar para imprimir un polinomio
    void imprimirPolinomio(const double* p, int grado) {
        for(int i = grado;i >= 0; --i){ //Viendo diversos casos si es i=0; no poner el x^0 sino solo el numero y cuando queda +- no poner el +;
            if(i==grado){
                if(*(p+i)==0){
                }
                else{
                    cout<<*(p+i)<<"x^"<<i;
                }
            }
            else if(i==0){
                if(*(p+i)==0){
                }
                else if(*(p+i)<0){
                    cout<<" "<<*(p+i);
                }
                else{
                    cout<<" + "<<*(p+i);
                }
            }
            else{
                if(*(p+i) > 0){
                    cout<<" + "<<*(p+i)<<"x^"<<i;
                }

                else if(*(p+i) == 0){
                    ;
                }

                else{
                    cout<<" "<<*(p+i)<<"x^"<<i;
                }
            }
            
        }
    }

    int main() {
        // Polinomio:
        // P(x) = 2 + 3x - x^2 + 4x^3
        double coef[] = {2, 3 , -1, 4};
        const int grado = 3;

        double resultado[10]={0}; // espacio suficiente
        int gradoResultado=0;

    int k = 2; // derivada de orden 2

    // Llamar a su funcion derivadaK
    cout<<"Polinomio original: "<<endl;
    imprimirPolinomio(coef,grado);

    derivadaK(coef,grado,k,resultado,gradoResultado);

    cout<<"\n\nDerivada de orden "<<k<<": "<<endl;
    imprimirPolinomio(resultado,gradoResultado);

    // Llamar la funcion imprimir para mostrar el polinomio original y  la derivada
    

    return 0;
}