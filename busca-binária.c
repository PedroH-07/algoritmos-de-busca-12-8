// arquivo: busca_binaria.c
#include <stdio.h>
int busca_binaria(int v[], int n, int alvo) {
    int ini = 0, fim = n - 1;
    while (ini <= fim) {
        int meio = ini + (fim - ini) / 2; // evita overflow
        if (v[meio] == alvo) {
            return meio; // ocorrência encontrada (não necessariamente a primeira)
        } else if (v[meio] < alvo) {
            ini = meio + 1;
        } else {
            fim = meio - 1;
        }
    }
    return -1;
}
// Variante: primeira ocorrência (caso haja duplicatas)
int busca_binaria_primeira(int v[], int n, int alvo) {
    int ini = 0, fim = n - 1, resp = -1;
    while (ini <= fim) {
        int meio = ini + (fim - ini) / 2;
        if (v[meio] >= alvo) {
            if (v[meio] == alvo) resp = meio;
            fim = meio - 1;
        } else {
            ini = meio + 1;
        }
    }
    return resp;
}
int main() {
    // vetor ORDENADO
    int v[] = {7, 13, 23, 42, 42, 99};
    int n = sizeof(v)/sizeof(v[0]);
    int alvo;
    printf("Digite o valor a buscar (binaria): ");
    scanf("%d", &alvo);
    int idx = busca_binaria(v, n, alvo);
    if (idx == -1) {
        printf("Valor %d nao encontrado.\n", alvo);
    } else {
        printf("Valor %d encontrado em alguma ocorrencia (indice %d).\n", alvo, idx);
        int first = busca_binaria_primeira(v, n, alvo);
        if (first != -1) {
            printf("Primeira ocorrencia do valor %d esta no indice %d.\n", alvo, first);
        }
    }
    return 0;
}