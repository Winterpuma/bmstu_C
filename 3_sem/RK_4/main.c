#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "student.h"

// Rk 4.3
// Doubly linked ring list

int menu()
{
    setbuf(stdout, NULL);
    int res;
    printf("Menu:\n\t0:Exit\n\t1:Add\n\t2:Delete\n\t3:Print\n");
    fflush(stdin);
    scanf("%d", &res);
    return res;
}


int main()
{
    struct node *list = NULL;
    int i = 0;

    int operation;

    while (operation = menu())
    {
        switch (operation)
        {
            case 1:
                fflush(stdin);
                printf("Index: ");
                scanf("%d", &i);
                push(&list, (void *)input_stud(), i);
                break;
            case 2:
                if (list)
                {
                    fflush(stdin);
                    printf("Index: ");
                    scanf("%d", &i);
                    list = pop(list, i);
                }
                else
                    printf("List is empty.\n");
                break;
            case 3:
                print(list, 1);
                break;
            default:
                printf("Input failed.\n");
                break;
        }
    }

    free_list(list, 1);

    return 0;
}
