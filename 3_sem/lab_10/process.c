#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "process.h"
#include "list.h"

/**
 * Get help in console.
 * ./app.exe help
 */
void help()
{
    printf("You can run this program with such flags:\n"
           "\thelp - get help info\n"
           "\tsort [f_in] [f_out] - sort l\n"
           "\tremove_last [f_in] [f_out] - remove last element from data\n"
           "\treverse [f_in] [f_out] - reverse data order\n"
           "f_in - file with original data.\n"
           "f_out - somehow changed data.\n");
}

/**
 * Function that runs one of determined operations.
 * @param head - pointer to list head
 * @param operation - operation number
 */
void process(node_t **head, int operation)
{
    void *data = NULL;

    switch (operation)
    {
        case c_sort:
            *head = sort(*head, comparator_int);
            break;
        case c_reverse:
            *head = reverse(*head);
            break;
        case c_print_console:
            print_int_list(*head);
            break;
        case c_remove_last:
            data = pop_back(head);
            if (data)
                free(data);
            break;
        default:
            break;
    }
}

/**
 * Check args for correctness
 * @param argc - number of args
 * @param argv - args
 * @return operation number or -1 if err
 */
int check_args(int argc, char *argv[])
{
    int flag = -1;

    if (argc == 2)
    {
        if (!strcmp(argv[1], "help"))
            flag = c_help;
    }
    else if (argc == 4)
    {
        if (!strcmp(argv[1], "sort"))
            flag = c_sort;
        else if (!strcmp(argv[1], "remove_last"))
            flag = c_remove_last;
        else if (!strcmp(argv[1], "reverse"))
            flag = c_reverse;
    }

    return flag;
}
