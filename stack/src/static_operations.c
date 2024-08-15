#include <stdio.h>
#include <stdlib.h>
#include "../include/static_operations.h"

bool isEmpty(stack *s)
{
    return s->size == 0;
}

char top(stack *s)
{
    if (s->size == 0)
        return -1;
    
    return s->top->item;
}