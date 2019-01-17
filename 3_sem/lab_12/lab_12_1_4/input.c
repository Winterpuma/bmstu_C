#include <stdio.h>
#include "input.h"

/**
 * Counts amount of ints in file
 * @param f - FILE
 * @return amount of ints in file
 */
int count_size(FILE *f)
{
    int current;
    int array_size = 0;

    while (fscanf(f, "%d", &current) == 1)
        array_size++;

    return array_size;
}


void read_file(FILE *f, int *ab)
{
    while (fscanf(f, "%d", ab) == 1)
        ab++;
}
