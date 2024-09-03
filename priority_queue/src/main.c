#include <stdio.h>
#include "../include/array_utils.h"
#include "../include/container.h"
#include "../include/static_operations.h"
#include "../include/dynamic_operations.h"

int main()
{
    int size = 1000;
    int *elements = generate_array(size, MAX_VALUE);
    
    priority_queue *pq_array = build_priority_queue_as_array(elements, size);
    priority_queue *pq_sorted_array = build_priority_queue_as_sorted_array(elements, size);
    priority_queue *pq_heap = build_priority_queue_as_heap(elements, size);

    is_sorted(pq_array->items->elements, pq_array->items->size);
    is_sorted(pq_sorted_array->items->elements, pq_sorted_array->items->size);
    is_sorted(pq_heap->items->elements, pq_heap->items->size);
    
    delete_priority_queue(pq_array);
    delete_priority_queue(pq_sorted_array);
    delete_priority_queue(pq_heap);
    
    free(elements);
}