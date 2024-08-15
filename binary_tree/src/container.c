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