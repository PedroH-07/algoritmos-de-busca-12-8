#include <stdio.h>
int busca_linear(int v[], int n, int alvo) {
    for (int i = 0; i < n; i++) {
        if (v[i] == alvo) {
            return i; 
        }
    }
    return -1;
}

int main() {
    int v[] = 
}