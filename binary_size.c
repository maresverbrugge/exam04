#include "ft_btree.h"
#include <stdio.h>
#include <stdlib.h>

int size_binary_tree(t_btree *root)
{
    int count_nodes;
    
    count_nodes = 0;
    if (root == NULL)
        return (0);
    while (root)
    {
        printf("root->value = %d\n", root->value);
        count_nodes += size_binary_tree(root->left);
        count_nodes += size_binary_tree(root->right);
        return (count_nodes + 1);
    }
    return (count_nodes);
}

// int size_binary_tree(t_btree *root)
// {
//     if (root == NULL)
//         return (0);
//     else
//         return (size_binary_tree(root->right) + 1 + size_binary_tree(root->left));
// }

int main(void)
{
    // make tree
    t_btree *root;

    // root = malloc(sizeof(t_btree));
    // root->value = 50;

    // root->left = malloc(sizeof(t_btree));
    // root->left->value = 24;
    // root->left->left = NULL;
    // root->left->right = malloc(sizeof(t_btree));
    // root->left->right->value = 45;
    // root->left->right->right = NULL;
    // root->left->right->left = malloc(sizeof(t_btree));
    // root->left->right->left->value = 25;
    // root->left->right->left->left = NULL;
    // root->left->right->left->right = NULL;

    // root->right = malloc(sizeof(t_btree));
    // root->right->value = 59;
    // root->right->left = NULL;
    // root->right->right = malloc(sizeof(t_btree));
    // root->right->right->value = 84;
    // root->right->right->right = NULL;
    // root->right->right->left = malloc(sizeof(t_btree));
    // root->right->right->left->value = 74;
    // root->right->right->left->left = NULL;
    // root->right->right->left->right = NULL;

    // ---------------------------
    root = malloc(sizeof(t_btree));
    root->value = 11;

    root->left = malloc(sizeof(t_btree));
    root->left->value = 7;
    root->left->right = malloc(sizeof(t_btree));
    root->left->right->value = 9;
    root->left->right->left = NULL;
    root->left->right->right = NULL;
    root->left->left = malloc(sizeof(t_btree));
    root->left->left->value = 3;
    root->left->left->left = malloc(sizeof(t_btree));
    root->left->left->left->value = 1;
    root->left->left->left->left = NULL;
    root->left->left->left->right = NULL;
    root->left->left->right = malloc(sizeof(t_btree));
    root->left->left->right->value = 5;
    root->left->left->right->left = NULL;
    root->left->left->right->right = NULL;

    root->right = malloc(sizeof(t_btree));
    root->right->value = 17;
    root->right->left = malloc(sizeof(t_btree));
    root->right->left->value = 16;
    root->right->left->right = NULL;
    root->right->left->left = NULL;
    root->right->right = malloc(sizeof(t_btree));
    root->right->right->value = 19;
    root->right->right->left = NULL;
    root->right->right->right = malloc(sizeof(t_btree));
    root->right->right->right->value = 20;
    root->right->right->right->right = NULL;
    root->right->right->right->left = NULL;

    printf("size of tree = %d\n", size_binary_tree(root));
    return (0);
}
