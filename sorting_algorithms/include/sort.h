#ifndef SORT_H
#define SORT_H

void bubble_sort(int *array, int n);
void selection_sort(int *array, int n);
int get_max_index(int *array, int end);
void insertion_sort(int *array, int n);
void quick_sort(int *array, int start, int end);
int partition(int *array, int start, int end);
void merge_sort(int *array, int start, int end);
void merge(int *array, int *left, int *right, int i, int j, int start, int end);
void swap(int *a, int *b);

#endif