#ifndef CONTAINER_H
#define CONTAINER_H

typedef struct
{
    char title[51];
    char author[51];
    int year;
    int quantity;
}
Book;

typedef struct Node
{
    Book info;
    struct Node *next;
}
Node;

typedef struct
{
    Node *head;
    int size;
}
LinkedList;

LinkedList *buildLinkedList();
void deleteLinkedList(LinkedList *list);
void displayList(LinkedList *list);
void displayBook(Book b);

#endif