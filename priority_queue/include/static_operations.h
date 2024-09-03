#ifndef STATIC_OPERATIONS_H
#define STATIC_OPERATIONS_H

#include "./container.h"

void sort(priority_queue *pq);
void max_heapify_up(int *array, int idx);
void max_heapify_down(int *array, int idx, int size);
int parent(int i);
int left(int i, int n);
int right(int i, int n);
void swap(int *a, int *b);

#endif