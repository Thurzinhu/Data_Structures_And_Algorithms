#ifndef SET_INTERFACE_H
#define SET_INTERFACE_H

#include "./container.h"

node *subtree_find(node *root, char key);
node *subtree_find_next(node *root, char key);
node *subtree_find_previous(node *root, char key);
void subtree_insert(node *root, node *newNode);

#endif