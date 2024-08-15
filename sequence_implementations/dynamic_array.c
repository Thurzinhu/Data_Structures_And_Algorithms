#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    int *collection;
    int size;
    int capacity;
}
dynamic_array;

dynamic_array *build(int *collection, int n);
int get_at(int idx); // O(1)
void set_at(int idx, int value); // O(1)
void insert_at(int idx, int value); // O(n)
int delete_at(int idx); // O(n)
void delete_sequence();
void resize();
void insert_last(int value);
void delete_last();
void print_sequence();

// #define insert_first(value) insert_at(0, value) // O(n)
// #define insert_last(value) insert_at(dynamicArray->size, value) // O(1)a
// #define delete_first() delete_at(0) // O(n)
// #define delete_last() delete_at(dynamicArray->size - 1) // O(1)a

dynamic_array *dynamicArray = NULL;

int main()
{
    int sample[] = {1, 2, 3, 4, 5};
    dynamicArray = build(sample, 5);
    print_sequence();
    for (int i = 0; i < 10; i++)
    {
        insert_last(i);
        print_sequence();
    }

    for (int i = 0; i < 14; i++)
    {
        delete_last();
        print_sequence();
    }

    delete_sequence();
}

void print_sequence()
{
    printf("Capacity: %i\nSize: %i\n", dynamicArray->capacity, dynamicArray->size);
    for (int i = 0; i < dynamicArray->size; i++) 
        printf("%i ", dynamicArray->collection[i]); printf("\n");
}

dynamic_array *build(int *collection, int n)
{
    int ratio = 2;
    dynamic_array *newDynamicArray = malloc(sizeof(dynamic_array));
    newDynamicArray->collection = malloc(sizeof(int) * n * ratio);
    newDynamicArray->capacity = n * ratio;
    newDynamicArray->size = n;

    for (int i = 0; i < newDynamicArray->size; i++) newDynamicArray->collection[i] = collection[i];

    return newDynamicArray;
}

int get_at(int idx)
{
    if (idx < 0 || idx >= dynamicArray->size)
        return -1;

    return dynamicArray->collection[idx];
}

void set_at(int idx, int value)
{
    if (idx < 0 || idx >= dynamicArray->size)
        return;

    dynamicArray->collection[idx] = value;
}

void resize()
{
    int ratio = 2;
    if (dynamicArray->size >= dynamicArray->capacity)
    {
        dynamicArray->capacity *= ratio;
        dynamicArray->collection = realloc(dynamicArray->collection, sizeof(int) * dynamicArray->capacity);
    }
    else if (dynamicArray->size == dynamicArray->capacity / (ratio * ratio) && dynamicArray->capacity > 4)
    {
        dynamicArray->capacity /= ratio;
        dynamicArray->collection = realloc(dynamicArray->collection, sizeof(int) * dynamicArray->capacity);
    }
}

void insert_last(int value)
{
    resize();

    dynamicArray->collection[dynamicArray->size++] = value;
}

void delete_last()
{
    resize();

    dynamicArray->size--;
}

void delete_sequence()
{
    free(dynamicArray->collection);
    free(dynamicArray);
}