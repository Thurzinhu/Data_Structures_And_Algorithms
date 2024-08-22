#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../include/array_utils.h"
#include "../include/sort.h"

void compare_sort_algorithms() 
{
    FILE *outputFile = fopen("results/sort_results.txt", "w");
    if (!outputFile)
    {
        terminate("Could not open output file\n");
    }

    int sizes[] = {100, 1000, 10000, 100000};
    int num_sizes = sizeof(sizes) / sizeof(sizes[0]);
    clock_t start, end;

    fprintf(outputFile, "---------------------------------------------------------------------------------------------------\n");
    fprintf(outputFile, "|                Comparison of Sorting Algorithm Execution Times (in milliseconds)                |\n");
    fprintf(outputFile, "---------------------------------------------------------------------------------------------------\n");
    fprintf(outputFile, "| %-10s | %-14s | %-14s | %-14s | %-14s | %-14s |\n", "Size", "BubbleSort", "SelectionSort", "InsertionSort", "QuickSort", "MergeSort");
    fprintf(outputFile, "---------------------------------------------------------------------------------------------------\n");

    for (int i = 0; i < num_sizes; i++) 
    {
        int size = sizes[i];
        int *array = generate_array(size, MAX_VALUE);
        if (!array)
        {
            terminate("Memory allocation failed\n");
        }

        int *copy = malloc(size * sizeof(int));
        if (!copy)
        {
            terminate("Memory allocation failed\n");
        }

        // Bubble Sort
        copy_elements(array, copy, 0, size - 1);
        start = clock();
        bubble_sort(copy, size);
        end = clock();
        double bubble_time = ((double)(end - start)) * 1000 / CLOCKS_PER_SEC;

        // Selection Sort
        copy_elements(array, copy, 0, size - 1);
        start = clock();
        selection_sort(copy, size);
        end = clock();
        double selection_time = ((double)(end - start)) * 1000 / CLOCKS_PER_SEC;

        // Insertion Sort
        copy_elements(array, copy, 0, size - 1);
        start = clock();
        insertion_sort(copy, size);
        end = clock();
        double insertion_time = ((double)(end - start)) * 1000 / CLOCKS_PER_SEC;

        // Quick Sort
        copy_elements(array, copy, 0, size - 1);
        start = clock();
        quick_sort(copy, 0, size - 1);
        end = clock();
        double quick_time = ((double)(end - start)) * 1000 / CLOCKS_PER_SEC;

        // Merge Sort
        copy_elements(array, copy, 0, size - 1);
        start = clock();
        merge_sort(copy, 0, size - 1);
        end = clock();
        double merge_time = ((double)(end - start)) * 1000 / CLOCKS_PER_SEC;

        fprintf(outputFile, "| %-10d | %-14.2f | %-14.2f | %-14.2f | %-14.2f | %-14.2f |\n", size, bubble_time, selection_time, insertion_time, quick_time, merge_time);
        free(copy);
        free(array);
    }

    fprintf(outputFile, "---------------------------------------------------------------------------------------------------\n");
    fclose(outputFile);
}

void terminate(const char *message) 
{
    fprintf(stderr, "%s", message);
    exit(EXIT_FAILURE);
}

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

void copy_elements(int *source, int *destination, int start, int end)
{
    for (int i = start, j = 0; i <= end; i++, j++)
    {
        destination[j] = source[i];
    }
}