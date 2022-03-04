#include <stdio.h>
#include <stdlib.h>
void merge(int *a, int l, int m, int r)
{

    int i, j, k, *aux;
    aux = (int *)malloc(sizeof(int) * r + 1);
    for (i = m + 1; i > l; i--)
        aux[i - 1] = a[i - 1];
    for (j = m; j < r; j++)
        aux[r + m - j] = a[j + 1];


        for(k=1; k<=r; k++){
            if(aux[j]<aux[i]) a[k] = aux[j--];
            else a[k] = aux[i++];
        }
}

void mergeSortOrdena(int *v, int esq, int dir)
{
    if (esq == dir)
    {
        return;
    }

    int meio = (esq + dir) / 2;
    mergeSortOrdena(v, esq, dir);
    mergeSortOrdena(v, meio + 1, dir);
    merge(v, esq, meio, dir);
}

void mergeSort(int v[], int n)
{
    mergeSortOrdena(v, 0, n - 1);
}

int EstaOrdemCrescente(int *vetor, int tamanho)
{
    for (int i = 1; i < tamanho; i++)
        if (vetor[i - 1] > vetor[i])
            return 0;
    return 1;
}

int main()
{
    int a[] = {10, 2, 7, 1, 4, 9, 3, 8, 1, 5, 6, 8, 9};

    int tamanhoVetor = sizeof(a) / sizeof(int);
    int ordenado = EstaOrdemCrescente(a, tamanhoVetor);

    printf("\nTESTE-> %d\n", tamanhoVetor);

    if (ordenado)
    {
        printf("Vetor está ordenado!\n");
    }
    else
    {
        mergeSort(a, tamanhoVetor);
    }

    for (int i = 0; i < tamanhoVetor; i++)
    {

        printf("%d \n", a[i]);
    }
}