#include <stdio.h>
#include <stdlib.h>
#include "../include/container.h"

node *create_node(char c)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->parent = NULL;
    newNode->item = c;
    newNode->height = 0;
    return newNode;
}

binaryTree *create_binary_tree()
{
    binaryTree *tree = (binaryTree *)malloc(sizeof(binaryTree));
    tree->root = NULL;
    tree->size = 0;
    return tree;
}

node *build_from_array(char *array, int start, int end)
{
    int middle = (end + start)/2;
    node *currentNode = create_node(array[middle]);
    if (start < middle)
    {
        currentNode->left = build_from_array(array, start, middle - 1);
        currentNode->left->parent = currentNode;
    }
    if (middle < end)
    {
        currentNode->right = build_from_array(array, middle + 1, end);
        currentNode->right->parent = currentNode;
    }

    return currentNode;
}

void maintain(node *root)
{
    rebalance(root);
    subtree_update(root);
    if (root->parent)
        maintain(root->parent);
}

void subtree_update(node *root)
{
    root->height = 1 + max(height(root->left), height(root->right));
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

void rebalance(node *root)
{
    if (skew(root) == 2)
    {
        if (skew(root->right) < 0)
            subtree_rotate_right(root->right);
        subtree_rotate_left(root);
    }
    else if (skew(root) == -2)
    {
        if (skew(root->left) < 0)
            subtree_rotate_left(root->left);
        subtree_rotate_right(root);
    }
}

int skew(node *root)
{
    return height(root->right) - height(root->left);
}

int height(node *root)
{
    if (root == NULL)
        return -1;
    return root->height;
}

void subtree_rotate_left(node *root)
{
    if (root->right)
    {
        node *Y = root->right;
        node *B = Y->left;
        root->right = B;
        if (B != NULL)
            B->parent = root;
        Y->left = root;
        Y->parent = root->parent;
        if (root->parent)
        {
            if (root->parent->left == root)
                root->parent->left = Y;
            else
                root->parent->right = Y;
        }
        root->parent = Y;
        subtree_update(root);
        subtree_update(Y);
    }
}

void subtree_rotate_right(node *root)
{
    if (root->left)
    {
        node *X = root->left;
        node *B = X->right;    
        root->left = B;
        if (B != NULL)
            B->parent = root;
        X->right = root;
        X->parent = root->parent;
        if (root->parent)
        {
            if (root->parent->left == root)
                root->parent->left = X;
            else
                root->parent->right = X;
        }
        root->parent = X;
        subtree_update(root);
        subtree_update(X);
    }
}

void determine_new_root(binaryTree *tree)
{
    if (tree->root->parent == NULL)
        return;

    node *tmp = tree->root->parent;
    while(tmp->parent)
    {
        tmp = tmp->parent;
    }

    tree->root = tmp;
}