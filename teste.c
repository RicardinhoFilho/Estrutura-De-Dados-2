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

void free_arvore(node *root)
{
    if (root != NULL)
    {
        free_arvore(root->left);
        free_arvore(root->right);
        free_arvore(root);
    }
}

int eh_espelho(node *root, node *root_2)
{
    int checa_esquerda = eh_espelho(root->left, root_2->right);
    int checa_direita = eh_espelho(root->right, root_2->left);
    if (root->num == root_2->num && checa_direita && checa_esquerda)
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

node *cria_espelho(node *root, node **root_e)
{
    if (root != NULL)
    {
        *root_e = cria_node(root->num);
        cria_espelho(root->left, &((*root_e)->right));
        cria_espelho(root->right, &((*root_e)->left));
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

void main()
{
    node *root = cria_node(5);
    root->left = cria_node(10);
    root->right = cria_node(2);
   

    node *root_2 = NULL;
    cria_espelho(root, &root_2);

    print(root);
    printf("\n");
    print(root_2);
    printf("\n");

    eh_espelho(root, root_2);

    // free_arvore(root);
    // free_arvore(root_2);
}
