#include <iostream>
using namespace std;

int main() {
    int a=1,b=2,c=3;
int* arrP[] = {&a,&b,&c};
int n=sizeof(arrP)/sizeof(arrP[0]);

for(int i=0;i<n;i++)
    cout << *arrP[i] << " ";
cout << endl;
}