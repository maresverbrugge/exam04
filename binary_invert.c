#include "ft_btree.h"
#include <stdio.h>
#include <stdlib.h>

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
    t_btree *tree; /// size = 10, height = 4

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
    t_btree *tree; // size = 7, height = 4

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

void print_bst(t_btree* root, int level, char *prefix)
{
    if (root == NULL)
        return ;
    int spaces = 4;
    char indent[spaces + 1];
    for (int i = 0; i < spaces; i++) {
        indent[i] = ' ';
    }
    indent[spaces] = '\0';

    if (level == 0)
        printf("%s%d\n", prefix, root->value);
    else
        printf("%*s|__ %d\n", spaces * level, indent, root->value);
    char left_prefix[6] = "L--- ";
    char right_prefix[6] = "R--- ";
    print_bst(root->left, level + 1, left_prefix);
    print_bst(root->right, level + 1, right_prefix);
}

int invert_binary_tree(t_btree *root)
{
    t_btree *tmp;

    if (root == NULL)
        return (0);
    invert_binary_tree(root->right);
    invert_binary_tree(root->left);
    tmp = root->left;
    root->left = root->right;
    root->right = tmp;
    return (1);
}
int main(void)
{
	t_btree *tree1;
	t_btree *tree2;
	t_btree *tree3;

	tree1 = make_tree1();
	tree2 = make_tree2();
	tree3 = make_tree3();

    print_bst(tree1, 0, "Root: ");
    printf("\n\n\n\n");
    if (invert_binary_tree(tree1) != 0)
        print_bst(tree1, 0, "Root: ");
    else
        printf("tree is empty\n");

    // printf("size of tree1 = %d\n\n", size_binary_tree(tree1));
    // printf("size of tree2 = %d\n\n", size_binary_tree(tree2));
    // printf("size of tree3 = %d\n", size_binary_tree(tree3));
    return (0);
}
