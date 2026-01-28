#include <iostream>
using namespace std;

int main() {
}
/*
1. ¿Qué es un Token?
En programación, un token es la unidad más pequeña con significado en una cadena de texto que ha sido separada por un delimitador.

Imagina una oración: "Hola mi nombre es Daniel".

Si el delimitador es el espacio, los tokens son: Hola, mi, nombre, es, Daniel.

Si el delimitador fuera la letra 'e', los tokens serían: Hola mi nombr, es Dani, l.

En resumen: El token es el "pedazo" de texto que queda entre los separadores.

2. Explicación de tu mensaje anterior
Tu mensaje explica el proceso técnico de cómo strtok "rompe" la cadena. Aquí te resumo lo más importante que debes retener para tu examen:

Es destructiva: strtok mete un \0 (nulo) donde encuentra el delimitador. Por eso "rompe" la cadena original.

Es estática: Tiene una "memoria interna" (un puntero oculto) que recuerda dónde se quedó. Por eso la primera vez le das la variable y luego le das nullptr.

3. Ejemplo pequeño de cada función/error
Aquí tienes ejemplos cortos de lo que mencionaste, aplicando lo que hemos aprendido:

A. Uso correcto de strtok (Separación por varios delimitadores)
strtok puede recibir varios delimitadores a la vez (coma, punto y coma, espacio).

C++

char datos[] = "192.168;1,50"; // IP separada por puntos, comas y comas
char* p = strtok(datos, ".;,"); // Buscamos cualquiera de esos 3

while(p != nullptr) {
    cout << "Token: " << p << endl;
    p = strtok(nullptr, ".;,"); 
}
B. El Error de la Cadena Literal (¡Cuidado en la PC2!)
Este es el error que te decía que lanza Segmentation Fault.

C++

// INCORRECTO
char* p = "Lima,Peru"; 
strtok(p, ","); // ¡CRASH! Intentaste escribir un '\0' en memoria de solo lectura.

// CORRECTO
char p[] = "Lima,Peru"; 
strtok(p, ","); // Funciona, porque el arreglo [] está en el Stack (es modificable).
C. Perder la cadena original
Si intentas imprimir la variable después de usar strtok, te llevarás una sorpresa.

C++

char frase[] = "PC2;2024;UNI";
strtok(frase, ";"); 

cout << frase; // SOLO imprimirá "PC2". El resto se "perdió" para el cout.
4. ¿Cómo funciona cada parte de tu código?
char* token = strtok(texto, ",");:

Acción: Busca la primera coma. La cambia por \0.

Resultado: token apunta a "Juan". La memoria interna de strtok apunta ahora a donde empieza "Pedro".

while (token != nullptr):

Acción: El bucle sigue mientras strtok encuentre algo. Si ya no hay más comas ni texto, devuelve nullptr (0) y el bucle rompe.

token = strtok(nullptr, ",");:

Acción: Como le pasas nullptr, la función dice: "Ah, sigo con la cadena de antes". Busca la siguiente coma desde donde se quedó.

Resumen para tu examen:
Si te piden contar cuántas palabras hay en una frase, puedes usar un contador dentro de ese while(token != nullptr). Cada vuelta del bucle es un token (una palabra).

¿Te sientes más seguro con el concepto de "destrucción" de la cadena original? Si quieres, podemos ver cómo hacer una copia de seguridad antes de destruirla.
*/