#include <stdio.h>
#include <stdlib.h>
#include "../include/container.h"
#include "../include/static_operations.h"
#include "../include/dynamic_operations.h"

priority_queue *build_base_priority_queue(int *elements, int size, pq_insert insert, pq_delete delete_max)
{
    priority_queue *pq = (priority_queue*)malloc(sizeof(priority_queue));
    pq->items = build_dynamic_array(size);
    pq->size = size;
    pq->insert = insert;
    pq->delete_max = delete_max;
    insert_elements(pq, elements);
    sort(pq);
    return pq;
}

void insert_elements(priority_queue *pq, int *elements)
{
    for (int i = 0; i < pq->size; i++)
        pq->insert(pq->items, elements[i]);
}

priority_queue *build_priority_queue_as_array(int *elements, int size)
{
    return build_base_priority_queue(elements, size, array_insert, array_delete_max);
}

priority_queue *build_priority_queue_as_sorted_array(int *elements, int size)
{
    return build_base_priority_queue(elements, size, sorted_array_insert, sorted_array_delete_max);
}

priority_queue *build_priority_queue_as_heap(int *elements, int size)
{
    return build_base_priority_queue(elements, size, heap_insert, heap_delete_max);
}

void delete_priority_queue(priority_queue *pq)
{
    delete_dynamic_array(pq->items);
    free(pq);
}

dynamic_array *build_dynamic_array(int size)
{
    int ratio = 2;
    dynamic_array *newDynamicArray = malloc(sizeof(dynamic_array));
    newDynamicArray->elements = malloc(sizeof(int)*size*ratio);
    newDynamicArray->capacity = size*ratio;
    newDynamicArray->size = 0;
    return newDynamicArray;
}

void insert_last(dynamic_array *array, int element)
{
    resize(array);
    array->elements[array->size++] = element;
}

void resize(dynamic_array *array)
{
    int ratio = 2;
    if (array->size >= array->capacity)
    {
        array->capacity *= ratio;
        array->elements = realloc(array->elements, sizeof(int) * array->capacity);
    }
    else if (array->size == array->capacity / (ratio * ratio) && array->capacity > 4)
    {
        array->capacity /= ratio;
        array->elements = realloc(array->elements, sizeof(int) * array->capacity);
    }
}

void delete_dynamic_array(dynamic_array *array)
{
    free(array->elements);
    free(array);
}