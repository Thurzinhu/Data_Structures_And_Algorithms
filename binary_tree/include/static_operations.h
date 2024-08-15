#ifndef STATIC_OPERATIONS_H
#define STATIC_OPERATIONS_H

#include "./container.h"

void subtree_iter(node *root);
node *subtree_first(node *root);
node *subtree_last(node *root);
node *successor(node *root);
node *predecessor(node *root);

#endif