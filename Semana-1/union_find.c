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
    for (i = 0; i <= uf->count; ++i)
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
    
    printf("%d == %d\n",find_UF(uf, p) , find_UF(uf, q));
 return find_UF(uf, p) == find_UF(uf, q)?  1 : 0;
}

int find_UF(UF *uf, int p)
{
   return(uf->id[p]);
   
}

void union_UF(UF *uf, int p, int q)
{
    int aux = find_UF(uf,p);
   for (int i = 0; i < uf->n; i++)
      if (find_UF(uf,i) == aux) {
               printf("CONECTANDO o %dcom o %d\n\n ", i, uf->id[q]);
          uf->id[i] = uf->id[q];};
   uf->count--;
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
        
        if (!connected_UF(uf, p, q))
        {
            printf("%d %d\n", p, q);
            union_UF(uf, p, q);
        }else{
            printf("CONECTADOS");
        }

        scanf("%d %d", &p, &q);
    }
    printf("%d Componentes",count_UF(uf));
}   
