#include <stdio.h>
#include <stdlib.h>
#include "../include/static_operations.h"

void sort(priority_queue *pq)
{
    for (int i = 0; i < pq->items->size; i++)
    {
        pq->delete_max(pq->items, pq->size);
        pq->size--;
    }
}

void max_heapify_up(int *array, int idx)
{
    if (idx <= 0)
        return;

    int parent_idx = parent(idx);
    if (array[idx] > array[parent_idx])
    {
        swap(&array[idx], &array[parent_idx]);
        max_heapify_up(array, parent_idx);
    }
}

void max_heapify_down(int *array, int idx, int size)
{
    int left_idx = left(idx, size);
    int right_idx = right(idx, size);
    // leaf
    if (left_idx == idx && right_idx == idx)
        return;
    
    int largest = idx;
    if (array[left_idx] > array[largest])
        largest = left_idx;
    if (array[right_idx] > array[largest])
        largest = right_idx;
    if (largest != idx)
    {
        swap(&array[idx], &array[largest]);
        max_heapify_down(array, largest, size);
    }
}

int parent(int i)
{
    return (i - 1)/2;
}

int left(int i, int n)
{
    int left = (2*i) + 1;
    return (left < n) ? left : i;
}

int right(int i, int n)
{
    int right = (2*i) + 2;
    return (right < n) ? right : i;
}

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}