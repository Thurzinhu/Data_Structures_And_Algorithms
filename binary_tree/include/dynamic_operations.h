#ifndef DYNAMIC_OPERATIONS_H
#define DYNAMIC_OPERATIONS_H

#include "./container.h"

void subtree_insert_before(node *a, node *b);
void subtree_insert_after(node *a, node *b);
void insert_node(binaryTree *tree, char item);
node *subtree_delete(node *root);
void delete_node(binaryTree *tree, char item);
void swap(char *a, char *b);
void free_tree(node *root);

#endif