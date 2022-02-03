#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int *id;
    int count;
    int n;
} UF;

UF *init_UF(int n);
int count_UF(UF *uf);
int connected_UF(UF *uf, int p, int q);
int find_UF(UF *uf, int p);
void union_UF(UF *uf, int p, int q);

UF *init_UF(int n)
{
    int i;
    UF *uf;

    uf = malloc(sizeof(UF));

    uf->id = malloc(sizeof(int) * n);
    uf->n = n;
    uf->count = n;
    for (i = 0; i < uf->count; ++i)
    {
        uf->id[i] = i;
    }

    return (uf);
}

int count_UF(UF *uf)
{
    return (uf->count);
}

int connected_UF(UF *uf, int p, int q)
{

    return (find_UF(uf, p) == find_UF(uf, q));
}

int find_UF(UF *uf, int p)
{
    return (uf->id[p]);
}

void union_UF(UF *uf, int p, int q)
{
    if (!uf->id[p])
    {
        uf->id[p] = p;
    }

    if (!uf->id[q])
    {
        uf->id[q] = uf->id[p];
    }
    else if (uf->id[q])
    {
        for (int i = 0; i < uf->count; ++i)
        {
            //printf("Comparando %d e %d\n", uf->id[q] , uf->id[i]);

            if (uf->id[q] == uf->id[i])
            {
                uf->id[q] = uf->id[p];
                //printf("Conectando %d à o grupo %d!\n", i, uf->id[p]);
            }
        }
    }

    printf("%d e %d estão foram conectados com o ID: %d\n", p, q, uf->id[p]);

    return;
}

int main()
{
    int n, p = 0, q = 0;
    UF *uf;
    printf("Digita a quantidade de elementos:\n");
    scanf("%d", &n);

    uf = init_UF(n);

    scanf("%d %d", &p, &q);
    while (p > -1 && q > -1)
    {
        //printf("%d %d\n", p, q);
        if (!connected_UF(uf, p, q))
        {
            printf("p = %d q = %d\n", p, q);
            union_UF(uf, p, q);
        }

        scanf("%d %d", &p, &q);
    }
}
