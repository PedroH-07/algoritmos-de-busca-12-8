#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 30

// Função de comparação para qsort
int compara(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

// Busca linear em vetor desordenado
int busca_linear(int vet[], int tam, int chave, int *passos) {
    *passos = 0;
    for (int i = 0; i < tam; i++) {
        (*passos)++;
        if (vet[i] == chave) return i;
    }
    return -1;
}

// Busca binária em vetor ordenado
int busca_binaria(int vet[], int tam, int chave, int *passos) {
    int ini = 0, fim = tam - 1, meio;
    *passos = 0;
    while (ini <= fim) {
        (*passos)++;
        meio = (ini + fim) / 2;
        if (vet[meio] == chave) return meio;
        else if (vet[meio] < chave) ini = meio + 1;
        else fim = meio - 1;
    }
    return -1;
}

void imprime_vetor(int vet[], int tam) {
    for (int i = 0; i < tam; i++) {
        printf("%d ", vet[i]);
    }
    printf("\n");
}

int main() {
    int produtos[TAM], chave, passos_linear, passos_binaria;

    srand(time(NULL));
    // Gera vetor de códigos aleatórios entre 1000 e 9999
    for (int i = 0; i < TAM; i++) {
        produtos[i] = rand() % 9000 + 1000;
    }

    printf("Vetor de códigos de produto:\n");
    imprime_vetor(produtos, TAM);

    // Escolha do código a buscar
    printf("Digite o código do produto para buscar: ");
    scanf("%d", &chave);

    // Parte A: Busca Linear
    int pos_linear = busca_linear(produtos, TAM, chave, &passos_linear);
    if (pos_linear != -1)
        printf("Busca Linear: Código encontrado na posição %d (%d passos)\n", pos_linear, passos_linear);
    else
        printf("Busca Linear: Código não encontrado (%d passos)\n", passos_linear);

    // Parte B: Ordena vetor e faz busca binária
    qsort(produtos, TAM, sizeof(int), compara);
    printf("Vetor ordenado:\n");
    imprime_vetor(produtos, TAM);

    int pos_binaria = busca_binaria(produtos, TAM, chave, &passos_binaria);
    if (pos_binaria != -1)
        printf("Busca Binária: Código encontrado na posição %d (%d passos)\n", pos_binaria, passos_binaria);
    else
        printf("Busca Binária: Código não encontrado (%d passos)\n", passos_binaria);

    // Comparação
    printf("\nComparação de passos:\n");
    printf("Linear: %d passos\n", passos_linear);
    printf("Binária: %d passos\n", passos_binaria);

    return 0;

    printf("-----------------------");
}