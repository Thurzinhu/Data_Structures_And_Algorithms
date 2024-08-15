#include <stdio.h>
#include <stdlib.h>
#include "../include/container.h"
#include "../include/dynamic_operations.h"
#include "../include/static_operations.h"

int main(int argc, char *argv[])
{
    if (argc != 2)
        return 1;
    
    stack *s = buildStack();

    printf("%s\n", isBalanced(argv[1]) ? "true" : "false");
    
    deleteStack(s);

    return 0;
}