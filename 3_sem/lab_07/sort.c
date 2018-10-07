#include <stdio.h>
#include <stdlib.h>

#include "output.h"
#include "sort.h"

void copy_array(const int *pb_src, const int *pe_src, int *pb_dst, int **pe_dst)
{
    *pe_dst = pb_dst + (pe_src - pb_src);
    for(; pb_dst < *pe_dst; pb_dst++, pb_src++)
        *pb_dst = *pb_src;
}


int compare_int(const void* p, const void* q)
{
    const int *a = p;
    const int *b = q;
    return *a - *b;
}


void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}


// Modified buble sort
// mysort(a, sizeof(a) / sizeof(a[0]), sizeof(a[0]), compare_int);
void mysort(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void*))
{
    int *pb = (int *)base;
    int *pe = pb + nitems;

    for (int i = 0; i < nitems; i++)
    {
        for (int j = 0; j < (pe - pb) - 1; j++)
            if (compare_int((pb + j), (pb + j+1)) >= 0)
                swap((pb + j), (pb + j+1));
        pe--;
    }
}
