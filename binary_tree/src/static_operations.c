#include <stdio.h>
#include <stdlib.h>
#include "../include/static_operations.h"

void subtree_iter(node *root)
{
    if (root == NULL)
        return;

    subtree_iter(root->left);   
    printf("%c ", (char)root->item);
    subtree_iter(root->right);   
}

node *subtree_first(node *root)
{
    if (root->left != NULL)
        return subtree_first(root->left);
    return root;
}

node *subtree_last(node *root)
{
    if (root->right != NULL)
        return subtree_last(root->right);
    return root;
}

node *successor(node *root)
{
    if (root->right != NULL)
        return subtree_first(root->right);
    while (root->parent && root == root->parent->right)
        root = root->parent;
    return root->parent;
}

node *predecessor(node *root)
{
    if (root->left != NULL)
        return subtree_last(root->left);
    while (root->parent && root == root->parent->left)
        root = root->parent;
    return root->parent;
}