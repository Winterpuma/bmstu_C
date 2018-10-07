#include <stdio.h>
#include <stdlib.h>

#include "memory.h"

float **alloc_mat(int n, int m)
{
    float **a = NULL;
    a = malloc(n*m*sizeof(float) + n*sizeof(float*));
    if (a)
    {
        float *beg = (float*)(a+n);
        for (int i = 0; i < n; i++)
            *(a+i) = beg + m*i;
    }
    return a;
}

void free_mat(float **matr)
{
    free(matr);
}
