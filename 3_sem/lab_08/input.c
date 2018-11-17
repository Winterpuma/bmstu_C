#include <stdio.h>

#include "input.h"
#include "memory.h"

/* Scanf matrix from file
 * f - file; n, m - pointes to size of matrix
 * matr - inputed matrix */
float **input(FILE *f, int *n, int *m)
{
    int in_i = 0, in_j = 0;
    int non_zero = 0;
    float **matr = NULL;
    if (f)
    {
        fscanf(f, "%d %d %d", n, m, &non_zero);
        matr = alloc_mat(*n, *m);
        zero_matr(matr, *n, *m);
        for(int i = 0; i < non_zero; i++)
        {
            fscanf(f, "%d %d", &in_i, &in_j);
            fscanf(f, "%f", &(matr[in_i-1][in_j-1]));
        }
    }
    return matr;
}

/* Zero all elements of matrix
 * matr - matrix, n, m - size; */
void zero_matr(float **matr, int n, int m)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            matr[i][j] = 0.0;
}
