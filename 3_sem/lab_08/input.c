#include <stdio.h>

#include "input.h" //?
#include "memory.h"
#include "output.h"

// Scanf matrix from file
float **input(FILE *f, int *n, int *m)
{
    int in_i = 0, in_j = 0;
    int non_zero = 0;
    float **matr = NULL;
    if (f)
    {
        fscanf(f, "%d %d %d", n, m, &non_zero);
        matr = alloc_mat(*n, *m);
        for(int i = 0; i < non_zero; i++)
        {
            fscanf(f, "%d %d", &in_i, &in_j);
            fscanf(f, "%f", &(matr[in_i-1][in_j-1]));
        }
    }
    print_mat(matr, *n, *m);
    return matr;
}
