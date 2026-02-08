#include<iostream>
using namespace std;

int Separar_numeros(char *texto, char* numeros[]){
    char* p = texto; // texto es una referencia al primer caracter, recordar un puntero tiene que recibir una referencia
    int i = 0;
    while(*p != '\0'){
        if( (*p >= '0' && *p <= '9') && (p == texto || *(p-1) == ' ' || *(p-1) == ',') ){ /*    Esto se hace para que guarde la direccion cada vez que empieze por un valor entre 0-9
                                                                                                ademas que la segunda parte ve si estamos en la referencia al primer caracter o 
                                                                                                si antes a la referinca hay un ' ' o ',' */
            numeros[i] = p; // Se va almacenando las referencias del primer caracter de cada "numero"
            i++; // Cambias de posicion para guardar la siguiente referencia
            while(*p >= '0' && *p <= '9'){ // Si el caracter esta entre 0-9 pasamos al siguiente caracter
                p++;  /* Al pasar al siguiente caracter vemos si esta entre 0-9 en caso sea asi seguimos pasando, en caso que no, nos que damos en el siguiente caracter 
                                                                                                                        (como sabemos que no esta entre 0-9 no hay problema) */
            } 
            if (*p == '\0'){ 
                break;
            }
        }
        p++; //Pasamos al siguiente caracter ya que sabemos que el anterior 
    }
    return i;
}

// Función para convertir de char* a int
int mi_atoi(char* p){
    int num = 0;
    while (*p >= '0' && *p <= '9') { // Si fuera 211, primero toma num = 0 * 10 + 2 ---> num = 2 * 10 + 1 ---> num = 21 * 10 + 1 ---> num = 211
        num = num * 10 + (*p - '0');
        p++;
    }
    return num;
}

bool suma(char* numeros[], int cantidad, int k){ // Damos tres parametros el arreglo con referencias, la cantidad de referencias y el numero a comprobar si es suma de dos numeros 
    int inicio = 0; 
    int fin = cantidad - 1; // Recordar que la pos maxima es la cantidad de elementos menos uno
    while (inicio < fin) {
        int sumaActual = mi_atoi(numeros[inicio]) + mi_atoi(numeros[fin]); /* Si buscamos k = 15 ---> sumaActual = 1 + 11 ---> sumaActual = 12
                                                                            ahora SumaActual = 2 + 11 ---> sumaActual = 13
                                                                            ahora SumaActual = 4 + 11 ---> sumaActual = 15
                                                                            */
        if (sumaActual == k){ // Desoues de tres pasadas se logro encontrar dos numero con suma 15
             return true; // Retorna 1
        }

        if (sumaActual < k){ // Se hace inicio++ ya que como es menor deseamos un numero mayor para poder llegar a la suma
            inicio++;
        }

        else{ // SumaActual > k // Se hace fin-- ya que como es mayor deseamos un numero menor para poder llegar a la suma
            fin--;
        }

    }
    return false; // Retorna 0
}

void Igualdad(bool encontrado, int n){
    if (encontrado){ // Si es verdadero // 1
        cout << "SI existen 2 numeros con suma " << n << endl;
    }
    else{ // Si es verdadero // 0
        cout << "NO existen 2 numeros con suma " << n << endl;
    }
}

int main() {
    char texto[] = "1, 2, 4, 7, 11";
    char* numeros[10]; //Hasta 10 punteros
    int a = 15;
    int b = 10;

    cout<<"texto: \""<<texto<<"\""<<endl; // NOTA: si queremos imprimir " tenemos que poner \ para que el programa lo acepte
    int n = Separar_numeros(texto, numeros);
    
    Igualdad(suma(numeros, n, a), a);
    Igualdad(suma(numeros, n, b), b);

    return 0;
}