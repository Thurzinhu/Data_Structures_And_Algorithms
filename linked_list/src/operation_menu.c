#include <stdio.h>
#include <stdlib.h>
#include "../include/container.h"
#include "../include/dynamic_operations.h"
#include "../include/static_operations.h"
#include "../include/operation_menu.h"

void linked_list_operation_menu()
{
    linked_list *list = build_linked_list();
    int choice, data, idx, continues = 1;

    while (continues) 
    {
        printf("Choose an option below.\n");
        printf("0 - Insert element at the beginning of the list\n");
        printf("1 - Insert element at the end of the list\n");
        printf("2 - Set value at a specific index\n");
        printf("3 - Print the list\n");
        printf("4 - Reverse the list\n");
        printf("5 - Remove element from the beginning of the list\n");
        printf("6 - Remove element from the end of the list\n");
        printf("7 - Remove nodes matching certain condition\n");
        printf("8 - Check if number is in the list\n");
        printf("9 - Exit the program\n\n");

        scanf("%i", &choice);

        switch(choice) 
        {
            case 0:
                printf("Enter the element to be inserted\n");
                scanf("%i", &data);
                insert_first(list, data);
                break;
            case 1:
                printf("Enter the element to be inserted\n");
                scanf("%i", &data);
                insert_last(list, data);
                break;
            case 2:
                printf("Enter the index and the value to be set\n");
                scanf("%i %i", &idx, &data);
                set_at(list, idx, data);
                break;
            case 3:
                print_list(list);
                printf("\n");
                break;
            case 4:
                reverse_list(list);
                break;
            case 5:
                remove_first(list);
                break;
            case 6:
                remove_last(list);
                break;
            case 7:
                printf("Enter 0 to remove even numbers, 1 to remove odd numbers\n");
                scanf("%i", &data);
                if (data == 0)
                    remove_nodes_matching_condition(list, is_even);
                else if (data == 1)
                    remove_nodes_matching_condition(list, is_odd);
                else
                    printf("Invalid option\n");
                break;
            case 8:
                printf("Enter the element to search for\n");
                scanf("%i", &data);
                printf("%s\n", find(list, data) ? "In list\n" : "Not in list\n");
                break;
            case 9:
                delete_list(list);
                continues = 0;
                break;
            default:
                printf("Invalid option\n");
        }

        printf("--------------------------------\n");
    }
}