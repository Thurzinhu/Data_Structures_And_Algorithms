#ifndef CONTAINER_H
#define CONTAINER_H

typedef struct node
{
    struct node *next;
    char item;
}
node;

typedef struct
{
    node *top;
    int size;
}
stack;

stack *buildStack();
void deleteStack(stack *s);

#endif 