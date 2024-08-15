#include <stdio.h>
#include <stdlib.h>
#include "../include/dynamic_operations.h"
#include "../include/static_operations.h"

char pop(stack *s)
{
    if (s->size == 0)
        return -1;
    
    node *tmp = s->top;
    char item = tmp->item;
    s->top = s->top->next;

    free(tmp);

    s->size--;

    return item;
}

void push(stack *s, char item)
{
    node *new = malloc(sizeof(node));
    new->item = item;
    new->next = s->top;
    s->top = new;

    s->size++;
}

bool isBalanced(char *string)
{
    stack *s = buildStack();
    
    for (int i = 0; string[i] != '\0'; i++)
    {
        if (string[i] == '[' || string[i] == '{' || string[i] == '(')
        {
            push(s, string[i]);
        }
        else
        {
            if (isEmpty(s))
            {
                return false;
            }

            char c = pop(s);
            if (string[i] != c + 2)
            {
                deleteStack(s);
                return false;
            }
        }
    }

    bool empty = isEmpty(s);
    deleteStack(s);

    return empty;
}