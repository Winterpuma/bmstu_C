#include <stdio.h>
#include <stdlib.h>

#include "list.h"
#include "process.h"

int main(int argc, char *argv[])
{
    node_t *head = NULL;
    FILE *f_in, *f_out;

    int operation = check_args(argc, argv);

    if (operation == -1)
    {
        printf("Something wrong with args.\n");
        return operation;
    }

    if (operation == c_help)
        help();
    else
    {
        f_in = fopen(argv[2], "r");
        if (f_in)
        {
            head = read_from_file(f_in);
            fclose(f_in);
            printf("Read list: ");
            print_int_list(head);

            process(&head, operation);
            printf("Processed list: ");
            print_int_list(head);

            f_out = fopen(argv[3], "w");
            write_to_file(f_out, head);
            fclose(f_out);
        }
    }

    free_list_all(&head);

    return 0;
}