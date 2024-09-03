#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../include/array_utils.h"

int *generate_array(int length, int max)
{
    srand(time(NULL));
    int *array = malloc(sizeof(int) * length);
    for (int i = 0; i < length; i++)
        array[i] = rand() % max;
    return array;
}

void print_array(int *array, int length)
{
    printf("[");
    for (int i = 0; i < length; i++)
    {
        printf("%d", array[i]);
        if (i != length - 1)
            printf(", ");
    }
    printf("]\n");
}

void is_sorted(int *array, int length)
{
    for (int i = 0; i < length - 1; i++)
    {
        if (array[i] > array[i + 1])
        {
            printf("Array is not sorted.\n");
            return;
        }
    }
    printf("Array is sorted.\n");
}