#include "../include/container.h"
#include "../include/static_operations.h"
#include "../include/dynamic_operations.h"

void array_insert(dynamic_array *array, int element)
{
    insert_last(array, element);
}

void sorted_array_insert(dynamic_array *array, int element)
{
    insert_last(array, element);
    for (int j = array->size - 1; j > 0 && array->elements[j] < array->elements[j - 1]; j--)
        swap(&array->elements[j], &array->elements[j - 1]);
}

void heap_insert(dynamic_array *array, int element)
{
    insert_last(array, element);
    max_heapify_up(array->elements, array->size - 1);
}

int array_delete_max(dynamic_array *array, int size)
{
    int maxIdx = 0;
    for (int i = 1; i < size; i++)
        if (array->elements[i] > array->elements[maxIdx])
            maxIdx = i;
    swap(&array->elements[maxIdx], &array->elements[size - 1]);
    return array->elements[size - 1];
}

int sorted_array_delete_max(dynamic_array *array, int size)
{
    return array->elements[size - 1];
}

int heap_delete_max(dynamic_array *array, int size)
{
    swap(&array->elements[0], &array->elements[size - 1]);
    max_heapify_down(array->elements, 0, size - 1);
    return array->elements[size - 1];
}