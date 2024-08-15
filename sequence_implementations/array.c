#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    int *collection;
    int size;
}
array;

array *build(int *collection, int n);
int get_at(int idx);
void set_at(int idx, int value);
void insert_at(int idx, int value);
int delete_at(int idx);
void delete_sequence();
void copy_forward(int from, int to, int aux[], int j);

#define insert_first(value) insert_at(0, value)
#define insert_last(value) insert_at(A->size, value)
#define delete_first() delete_at(0)
#define delete_last() delete_at(A->size - 1)
#define print_sequence() { for(int i = 0; i < A->size; i++) printf("%i ", A->collection[i]); printf("\n"); }

array *A = NULL;

int main()
{
    int sample[] = {1, 2, 3, 4, 5};
    A = build(sample, 5);
    print_sequence();

    insert_first(100);
    insert_last(50);
    for (int i = 10; i <= 30; i++) insert_first(i);
    print_sequence();

    delete_last();
    delete_first();

    insert_at(1, 890);

    print_sequence();
    delete_sequence();
}

array *build(int *collection, int n)
{
    array *newArray = malloc(sizeof(array));
    newArray->collection = malloc(sizeof(int) * n);
    newArray->size = n;

    for (int i = 0; i < n; i++) newArray->collection[i] = collection[i];

    return newArray;
}

int get_at(int idx) // O(1)
{
    if (idx >= A->size || idx < 0)
        return -1;

    return A->collection[idx];
}

void set_at(int idx, int value) // O(1)
{
    if (idx >= A->size || idx < 0)
        return;

    A->collection[idx] = value;
}

void insert_at(int idx, int value)
{
    int n = A->size + 1;
    
    int aux[n];
    copy_forward(0, idx, aux, 0);
    aux[idx] = value;
    copy_forward(idx, A->size, aux, idx + 1);
    
    delete_sequence(); // O(1)

    A = build(aux, n); // O(n)
}

int delete_at(int idx)
{
    int n = A->size - 1;
    int removed_item = A->collection[idx];

    int aux[n];
    copy_forward(0, idx, aux, 0);
    copy_forward(idx + 1, A->size, aux, idx);

    delete_sequence(); // O(1)
    
    A = build(aux, n); // O(n)

    return removed_item;
}

void copy_forward(int from, int to, int aux[], int j)
{
    for (int i = from; i < to; i++, j++) aux[j] = A->collection[i];
}

void delete_sequence()
{
    free(A->collection);
    free(A);
}