#ifndef DYNAMIC_OPERATIONS_H
#define DYNAMIC_OPERATIONS_H

#include <stdlib.h>

#include "../include/container.h"

void array_insert(dynamic_array *array, int element);
void sorted_array_insert(dynamic_array *array, int element);
void heap_insert(dynamic_array *array, int element);
int array_delete_max(dynamic_array *array, int size);
int sorted_array_delete_max(dynamic_array *array, int size);
int heap_delete_max(dynamic_array *array, int size);

#endif