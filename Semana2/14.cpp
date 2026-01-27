#include <iostream>
using namespace std;

int main() {
    int mat[2][3] = {{1,2,3},{4,5,6}};
int (*p)[3] = mat; // puntero a fila

for(int i=0;i<2;i++)
    for(int j=0;j<3;j++)
        cout << *(*(p+i)+j) << " ";
cout << endl;
}