#include <stdio.h>
#include "output.h"
#include "operations.h"

/* Print out matrix to console
 * a - matrix, n, m - size */
void print_mat(float **a, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            printf("%f ", a[i][j]);
        printf("\n");
    }
}

/* Count non-zero elements in matrix
 * matr - matrix, n, m - size;
 * elements - amount of non-zero elements */
int count_non_zero(float **matr, int n, int m)
{
    int elements = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (compare_zero(matr[i][j]))
                elements++;
    return elements;
}

/* Output matrix to file
 * f - file, matr - matrix, n, m - size */
void output(FILE *f, float **matr, int n, int m)
{
    fprintf(f, "%d %d %d\n", n, m, count_non_zero(matr, n, m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (compare_zero(matr[i][j]))
                fprintf(f, "%d %d %f\n", i+1, j+1, matr[i][j]);
}
