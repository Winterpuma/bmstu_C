#include <stdio.h>
#include "output.h"

/**
 * Print out array to console
 * @param ab - pointer to beginning of array
 * @param ae - pointer to ending of array
 */
void print_array(const int *ab, const int *ae)
{
    printf("\n");
    for (; ab < ae; ab++)
        printf("%d ", *ab);
}

/**
 * Output array to file
 * @param f - FILE
 * @param ba - pointer to beginning of array
 * @param ea  - pointer to ending of array
 */
void fill_file(FILE *f, const int *ba, const int *ea)
{
    for (int i = 0; (ba + i) < ea; i++)
        fprintf(f, "%d ", *(ba + i));
}
