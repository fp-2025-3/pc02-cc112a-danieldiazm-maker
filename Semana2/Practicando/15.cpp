#include <iostream>
using namespace std;

int main() {
    const char* dias[] = {"Lun", "Mar", "Mie", "Jue"};
    int n = sizeof(dias)/sizeof(dias[0]);

    for (int i = 0; i < n; ++i) {
        cout << dias[i] << endl;
    }
}