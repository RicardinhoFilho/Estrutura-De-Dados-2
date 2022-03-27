#include <stdlib.h>
#include <stdio.h>

typedef struct node node;
struct node
{
    int num;
    node *left;
    node *right;
};

node *cria_node(int num)
{
    node *root = (node *)malloc(sizeof(node));
    root->num = num;
    root->left = NULL;
    root->right = NULL;
    if (num > root->num)
        root->right->num = num;
    if (num < root->num)
        root->left->num = num;
    return root;
}

void print(node *root)
{
    if (root != NULL)
    {
        printf("%d\t", root->num);
        print(root->left);
        print(root->right);
    }
}

void free_tree(node *root)
{
    if (root != NULL)
    {
        free_tree(root->left);
        free_tree(root->right);
        free(root);
    }
}

int checkEspelho(node *root, node *espelho)
{
    if (root != NULL)
    {
        int checa_esquerda = checkEspelho(root->left, espelho->right);
        int checa_direita = checkEspelho(root->right, espelho->left);
        if (root->num == espelho->num && checa_direita && checa_esquerda)
        {
            printf("Sao espelho");
            return 1;
        }
        else
        {
            printf("Nao sao espelho");
            return 0;
        };
    }
    printf("\n");
    return 1;
}

node *espelha(node *root, node **root_e)
{
    if (root != NULL)
    {
        *root_e = cria_node(root->num);
        espelha(root->left, &((*root_e)->right));
        espelha(root->right, &((*root_e)->left));
    }
}



void main()
{
    node *root = cria_node(1);
    root->left = cria_node(2);
    root->right = cria_node(3);

    node *espelho = NULL;
    espelha(root, &espelho);
    printf("MODELO\n");
    print(root);
    printf("\n");
    printf("ESPELHADO\n");
    print(espelho);
    printf("\n");

    checkEspelho(root, espelho);

    free_tree(root);
    free_tree(espelho);
}
