#include <stdio.h>
#include <stdlib.h>
#include "../include/container.h"
#include "../include/dynamic_operations.h"

stack *buildStack()
{
    stack *new = malloc(sizeof(stack));
    new->size = 0;
    new->top = NULL;

    return new;
}

void deleteStack(stack *s)
{
    while (s->size)
        pop(s);

    free(s);
}