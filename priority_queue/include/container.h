#ifndef CONTAINER_H
#define CONTAINER_H

typedef struct 
{
    int *elements;
    int size;
    int capacity;
}
dynamic_array;

dynamic_array *build_dynamic_array(int size);
void insert_last(dynamic_array *array, int element);
void resize(dynamic_array *array);
void delete_dynamic_array(dynamic_array *array);

typedef int(*pq_delete)(dynamic_array *array, int pq_size);
typedef void(*pq_insert)(dynamic_array *array, int element);

typedef struct 
{
    pq_delete delete_max;
    pq_insert insert;
    dynamic_array *items;
    int size;
}
priority_queue;

priority_queue *build_base_priority_queue(int *elements, int size, pq_insert insert, pq_delete delete_max);
void insert_elements(priority_queue *pq, int *elements);
priority_queue *build_priority_queue_as_array(int *elements, int size);
priority_queue *build_priority_queue_as_sorted_array(int *elements, int size);
priority_queue *build_priority_queue_as_heap(int *elements, int size);
void delete_priority_queue(priority_queue *pq);

#endif