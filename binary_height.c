#include "ft_btree.h"
#include <stdio.h>
#include <stdlib.h>

int height_binary_tree(t_btree *root)
{
    int height_left;
    int height_right;
    
    height_left = 0;
    height_right = 0;
    if (root == NULL)
        return (0);
    while (root)
    {
        printf("root->value = %d\n", root->value);
        height_left += height_binary_tree(root->left);
        height_right += height_binary_tree(root->right);
        if (height_left >= height_right)
            return (height_left + 1);
        return (height_right + 1);
    }
    return (-1);
}

t_btree *new_node(int value)
{
    t_btree *new_node = malloc(sizeof(t_btree));
    new_node->value = value;
    new_node->left = NULL;
    new_node->right = NULL;
    return (new_node);
}

t_btree *make_tree1()
{
    t_btree *tree; /// height = 4

	tree = new_node(11);
	tree->left = new_node(7);
	tree->left->left = new_node(3);
	tree->left->right = new_node(9);
	tree->left->left->left = new_node(1);
	tree->left->left->right = new_node(5);
	tree->right = new_node(17);
	tree->right->right = new_node(19);
	tree->right->left = new_node(16);
	tree->right->right->right = new_node(20);
    return (tree);
}

t_btree *make_tree2()
{
    t_btree *tree; // height = 4

	tree = new_node(50);
	tree->left = new_node(24);
	tree->left->right = new_node(45);
	tree->left->right->left = new_node(25);
	tree->right = new_node(59);
	tree->right->right = new_node(84);
	tree->right->right->left = new_node(74);
    return (tree);
}

t_btree *make_tree3()
{
    t_btree *tree; // size = 11, height = 6

	tree = new_node(30);
	tree->left = new_node(24);
	tree->left->left = new_node(11);
	tree->left->left->right = new_node(13);
	tree->left->right = new_node(26);
	tree->left->right->right = new_node(27);
	tree->left->right->right->right = new_node(28);
	tree->left->right->right->right->right = new_node(29);
	tree->right = new_node(40);
	tree->right->right = new_node(58);
	tree->right->right->left = new_node(48);
    return (tree);
}

int main(void)
{
	t_btree *tree1;
	t_btree *tree2;
	t_btree *tree3;

	tree1 = make_tree1();
	tree2 = make_tree2();
	tree3 = make_tree3();

    printf("height of tree1 = %d\n\n", height_binary_tree(tree1));
    printf("height of tree2 = %d\n\n", height_binary_tree(tree2));
    printf("height of tree3 = %d\n", height_binary_tree(tree3));

    return (0);
}