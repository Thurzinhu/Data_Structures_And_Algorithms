#ifndef STATIC_OPERATIONS_H
#define STATIC_OPERATIONS_H

#include "./container.h"

void set_at(linked_list *list, int idx, int val);
int find(linked_list *list, int val);
int helper_find(node *cur, int val);
void reverse_list(linked_list *list);
void helper_reverse_list(node *cur);
void print_list(linked_list *list);
node *get_at(linked_list *list, int idx);

#endif