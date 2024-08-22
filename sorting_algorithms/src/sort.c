#include <stdio.h>
#include <stdlib.h>
#include "../include/sort.h"
#include "../include/array_utils.h"

void bubble_sort(int *array, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = n - 1; j > i; j--)
        {
            if (array[j - 1] > array[j])
                swap(&array[j - 1], &array[j]);
        }
    }
}

void selection_sort(int *array, int n)
{
    for (int i = n - 1; i > 0; i--)
    {
        int maxIdx = get_max_index(array, i);
        swap(&array[i], &array[maxIdx]);
    }
}

int get_max_index(int *array, int end)
{
    int maxIdx = end;
    for (int i = end - 1; i >= 0; i--)
        if (array[maxIdx] < array[i])
            maxIdx = i;
    return maxIdx;
}

void insertion_sort(int *array, int n)
{
    for (int i = 1; i < n; i++)
    {
        for (int j = i; j > 0 && array[j - 1] > array[j]; j--)
            swap(&array[j - 1], &array[j]);
    }
}

void quick_sort(int *array, int start, int end)
{
    if (start >= end)
        return;
    int pivot = partition(array, start, end);
    quick_sort(array, start, pivot - 1);
    quick_sort(array, pivot + 1, end);
}

int partition(int *array, int start, int end)
{
    int pivot = array[end];
    int currentIdx, swapMarker;
    for (currentIdx = start, swapMarker = start - 1; currentIdx <= end; currentIdx++)
    {
        if (array[currentIdx] <= pivot)
        {
            swapMarker++;
            swap(&array[currentIdx], &array[swapMarker]);
        }
    }
    return swapMarker;
}

void merge_sort(int *array, int start, int end)
{
    if (start >= end)
        return;
    int middle = start + (end - start) / 2;
    merge_sort(array, start, middle);
    merge_sort(array, middle + 1, end);
    int leftSize = (middle - start) + 1;
    int rightSize = (end - middle);
    int *leftArray = (int *)malloc(sizeof(int) * leftSize);
    int *rightArray = (int *)malloc(sizeof(int) * rightSize);
    copy_elements(array, leftArray, start, middle);
    copy_elements(array, rightArray, middle + 1, end);
    merge(array, leftArray, rightArray, leftSize - 1, rightSize - 1, start, end);
    free(leftArray);
    free(rightArray);
}

void merge(int *array, int *left, int *right, int i, int j, int start, int end)
{
    if (start > end)
        return;
    if (i < 0 || (j >= 0 && left[i] < right[j]))
        array[end--] = right[j--];
    else
        array[end--] = left[i--];
    merge(array, left, right, i, j, start, end);
}

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}