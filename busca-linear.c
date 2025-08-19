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
    int v[] = {73, 28, 15, 89, 35, 13};
    int n = sizeof(v)/sizeof(v[0]);
    int alvo;
    printf("Digite o valor a buscar (linear): ");
    scanf("%d", &alvo);
    int idx = busca_linear(v, n, alvo);
    if (idx == -1) {
        printf("Valor %d nao encontrado.\n", alvo);
    } else {
        printf("Valor %d encontrado no indice %d.\n", alvo, idx);
    }
    return 0;
}