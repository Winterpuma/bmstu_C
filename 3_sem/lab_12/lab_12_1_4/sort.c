#include <stdio.h>
#include <stdlib.h>

#include "output.h"
#include "sort.h"

 /**
  * Copy one array to another
  * @param pb_src - pointer to beginning of source array
  * @param pe_src - pointer to ending of source array
  * @param pb_dst - pointer to beginning of dest array
  * @param pe_dst - pointer to ending of dest array
  */
void copy_array(const int *pb_src, const int *pe_src, int *pb_dst, int **pe_dst)
{
    *pe_dst = pb_dst + (pe_src - pb_src);
    for(; pb_dst < *pe_dst; pb_dst++, pb_src++)
        *pb_dst = *pb_src;
}

/**
 * Compare two integers
 * @param p - pointer to first int
 * @param q - pointer to second int
 * @return
 */
int compare_int(const void* p, const void* q)
{
    const int *a = p;
    const int *b = q;
    return *a - *b;
}

/**
 * Swap functions for int
 * @param a
 * @param b
 */
void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

// mysort(a, sizeof(a) / sizeof(a[0]), sizeof(a[0]), compare_int);
/**
 * Modified bubble sort
 * @param base - beginning of array
 * @param nitems - amount of elements in array
 * @param size - size of
 * @param compar - comparison function
 */
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
