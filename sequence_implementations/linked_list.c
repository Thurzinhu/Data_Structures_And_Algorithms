#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    struct node *next;
    int item;
}
node;

typedef struct 
{
    node *head;
    int size;
}
linked_list;

void build(int *collection, int n);
int get_at(int idx); // O(n)
void set_at(int idx, int value); // O(n)
void insert_at(int idx, int value);
int delete_at(int idx);
void delete_sequence();
node *later_node(node *cur, int idx);

#define insert_first(value) insert_at(0, value) // O(1)
#define insert_last(value) insert_at(L->size, value) // O(n)
#define delete_first() delete_at(0) // O(1)
#define delete_last() delete_at(L->size - 1) // O(n)
#define print_sequence() { for (node *aux = L->head; aux != NULL; aux = aux->next) printf("%i ", aux->item); printf("\n"); }

linked_list *L;

int main()
{
    int sample[] = {1, 2, 3, 4, 5};
    build(sample, sizeof(sample) / sizeof(sample[0]));

    printf("%i\n", get_at(4));
    print_sequence();
    delete_last();
    delete_first();
    insert_at(1, 100);
    print_sequence();

    delete_sequence();
}

void build(int *collection, int n)
{
    L = malloc(sizeof(linked_list));
    L->head = NULL;
    L->size = 0;

    for (int i = 0; i < n; i++) insert_last(collection[i]);
}

int get_at(int idx)
{
    node *aux = later_node(L->head, idx);

    return aux->item;
}

void set_at(int idx, int value)
{
    node *aux = later_node(L->head, idx);

    aux->item = value;
}

node *later_node(node *cur, int idx)
{
    if (idx == 0)
        return cur;

    return later_node(cur->next, idx - 1);
}

void insert_at(int idx, int value)
{
    if (idx < 0 || idx > L->size)
        return;
    
    node *newNode = malloc(sizeof(node));
    newNode->next = NULL;
    newNode->item = value;

    if (idx == 0)
    {
        newNode->next = L->head;
        L->head = newNode;
    }
    else
    {
        node *aux = later_node(L->head, idx - 1);
        newNode->next = aux->next;
        aux->next = newNode;
    }

    L->size++;
}

int delete_at(int idx)
{
    if (idx < 0 || idx >= L->size)
        return -1;

    int deleted_item;
    node *tmp;

    if (idx == 0)
    {
        tmp = L->head;
        
        deleted_item = tmp->item;
        L->head = tmp->next;
    }        
    else
    {
        node *aux = later_node(L->head, idx - 1);
        tmp = aux->next;

        deleted_item = tmp->item;
        aux->next = tmp->next;    
    }
    
    free(tmp);

    L->size--;

    return deleted_item;
}

void delete_sequence()
{
    node *tmp = L->head;
    while(tmp != NULL)
    {
        node *aux = tmp->next;
        free(tmp);
        tmp = aux;
    }

    free(L);
}