
#include <stdio.h>
#include <stdlib.h>
void mergeInt(int v[], int inicio, int fim, int aux[]) {
    int meio = (inicio + fim) / 2;
    int i = inicio;
    int j = meio + 1;
    int k = 0;
    while (i <= meio || j <= fim) {
        if (i <= meio && (j > fim || v[i] < v[j])) {
            aux[k] = v[i];
            i++;
        } else {
            aux[k] = v[j];
            j++;
        }
        k++;
    }
}

void mergeSortInt(int v[], int inicio, int fim, int aux[]) {
    int meio = (inicio + fim) / 2;

    if (inicio < fim) {
        mergeSortInt(v, inicio, meio, aux);
        mergeSortInt(v, meio + 1, fim, aux);
        mergeInt(v, inicio, fim, aux);

        for (int l = 0; l < fim - inicio + 1; l++) {
            v[inicio + l] = aux[l];
        }
    }
}

void mergeSort(int v[], int tamanho) {
    int *aux = malloc(sizeof(int) * tamanho);
    mergeSortInt(v, 0, tamanho, aux);
    free(aux);
}

int main() {
    int a[] = {10, 2, 7, 1, 4, 9, 3, 8, 0, 5, 6};
    mergeSort(a, 11);
    for (int i = 0; i < 11; i++) {
        printf("%d \n", a[i]);
    }
}