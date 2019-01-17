#ifndef LAB_10_PROCESS_H
#define LAB_10_PROCESS_H

#include <stdio.h>
#include "list.h"

enum OPERATION {c_help = 1, c_sort = 2, c_remove_last = 3,
        c_reverse = 4, c_print_console = 5};

void help();
void process(node_t **head, int operation);
int check_args(int argc, char *argv[]);

#endif //LAB_10_PROCESS_H
