#include <stdio.h>
#include "output.h"

void print_array(const int *ab, const int *ae)
{
    printf("\n");
    for (; ab < ae; ab++)
        printf("%d ", *ab);
}

// Output array to file
void fill_file(FILE *f, const int *ba, const int *ea)
{
    for (int i = 0; (ba + i) < ea; i++)
        fprintf(f, "%d ", *(ba + i));
}
