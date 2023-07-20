#include "ft_btree.h"
#include <stdio.h>
#include <stdlib.h>

// int size_binary_tree(t_btree *root, int value)
// {
//     int count_nodes = 0;
//     if (root == NULL)
//         return (0);
//     while (root)
//     {
//         printf("root->value = %d\n", root->value);
//         count_nodes++;
//         size_binary_tree(root->right, value);
//         if (root->left == NULL)
//             return (count_nodes);
//         size_binary_tree(root->left, value);
//         count_nodes++;
//         if (root->right == NULL)
//             return (count_nodes);
//         if (root->value == value)
//             return (count_nodes);
//     }
//     return (count_nodes);
// }

int size_binary_tree(t_btree *root, int value)
{
    int count_nodes;
    
    count_nodes = 0;
    if (root == NULL)
        return (0);
    while (root)
    {
        printf("root->value = %d\n", root->value);
        count_nodes += size_binary_tree(root->right, value);
        count_nodes += size_binary_tree(root->left, value);
        return (count_nodes + 1);
    }
    return (count_nodes);
}

// int size_binary_tree(t_btree *root, int value)
// {
//     if (root == NULL)
//         return (0);
//     else
//         return (size_binary_tree(root->right, value) + 1 + size_binary_tree(root->left, value));

// }

int main(void)
{
    // make tree
    t_btree *root;

    root = malloc(sizeof(t_btree));
    root->value = 50;
    root->left = malloc(sizeof(t_btree));
    root->left->value = 24;
    root->left->left = NULL;
    root->left->right = malloc(sizeof(t_btree));
    root->left->right->value = 45;
    root->left->right->right = NULL;
    root->left->right->left = malloc(sizeof(t_btree));
    root->left->right->left->value = 25;
    root->left->right->left->left = NULL;
    root->left->right->left->right = NULL;

    root->right = malloc(sizeof(t_btree));
    root->right->value = 59;
    root->right->left = NULL;
    root->right->right = malloc(sizeof(t_btree));
    root->right->right->value = 84;
    root->right->right->right = NULL;
    root->right->right->left = malloc(sizeof(t_btree));
    root->right->right->left->value = 74;
    root->right->right->left->left = NULL;
    root->right->right->left->right = NULL;

    printf("amount of nodes = %d\n", size_binary_tree(root, 50));
    return (0);
}
