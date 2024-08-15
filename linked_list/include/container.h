#ifndef CONTAINER_H
#define CONTAINER_H

typedef struct node
{
    int data;
    struct node *next;
}
node;

typedef struct
{
    int length;
    node *head;
    node *tail;
}
linked_list;

linked_list *build_linked_list();
void delete_list(linked_list *list);

#endif