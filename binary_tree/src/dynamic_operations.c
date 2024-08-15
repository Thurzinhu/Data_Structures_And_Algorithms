#include <stdio.h>
#include <stdlib.h>
#include "../include/static_operations.h"
#include "../include/dynamic_operations.h"
#include "../include/set_interface.h"

void subtree_insert_before(node *a, node *b)
{
    if (a->left == NULL)
    {
        a->left = b;
        b->parent = a;
    }
    else
    {
        node *lastNode = subtree_last(a->left);
        lastNode->right = b;
        b->parent = lastNode;
    }
}

void subtree_insert_after(node *a, node *b)
{
    if (a->right == NULL)
    {
        a->right = b;
        b->parent = a;
    }
    else
    {
        node *firstNode = subtree_first(a->right);
        firstNode->left = b;
        b->parent = firstNode;
    }
}

node *subtree_delete(node *root)
{
    if (root->left != NULL || root->right != NULL)
    {
        node *nodeToBeDeleted;
        if (root->left != NULL)
            nodeToBeDeleted = predecessor(root);
        else
            nodeToBeDeleted = successor(root);
        swap(&nodeToBeDeleted->item, &root->item);
        return subtree_delete(nodeToBeDeleted);
    }

    // case node is a leaf
    if (root->parent != NULL)
    {
        if (root->parent->left == root)
            root->parent->left = NULL;
        else
            root->parent->right = NULL;
    }
    
    return root;
}

void swap(char *a, char *b)
{
    char t = *a;
    *a = *b;
    *b = t;
}

void free_tree(node *root)
{
    if (root == NULL)
        return;

    node *left = root->left, *right = root->right; 
    free_tree(left);
    free(root);
    free_tree(right);
}

void insert_node(binaryTree *tree, char item)
{
    node *newNode = create_node(item);
    if (tree->root == NULL)
        tree->root = newNode;
    else
        subtree_insert(tree->root, newNode);
    tree->size++;
}

void delete_node(binaryTree *tree, char item)
{
    node *nodeToBeDeleted = subtree_find(tree->root, item);
    if (nodeToBeDeleted != NULL)
    {
        free(subtree_delete(nodeToBeDeleted));
        tree->size--;
    }
}