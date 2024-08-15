#ifndef DYNAMIC_OPERATIONS_H
#define DYNAMIC_OPERATIONS_H

#include "./container.h"
#include <stdbool.h>

typedef bool (*remove_function)(int);

void insert_first(linked_list *list, int data);
void insert_last(linked_list *list, int data);
void remove_first(linked_list *list);
void remove_last(linked_list *list);
void remove_nodes_matching_condition(linked_list *list, remove_function function);

bool is_even(int n);
bool is_odd(int n);

#endif