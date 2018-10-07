#include <stdio.h>
#include <stdlib.h>

#include "filter.h"

// Will count average of array
float count_average(const int *pb, const int *pe)
{
    float sum;
    int size = pe - pb;

    for (; pb < pe; pb++)
        sum += *pb;

    return sum / size;
}

// Will count amount of elements above average
int new_size(const int *pb, const int *pe, int average)
{
    int dst_size = 0;
    for (; pb < pe; pb++)
        if (*pb > average)
            dst_size++;
    return dst_size;
}

// Will move elements from src array to dst array above average
void move_elements(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst, float average)
{
    int *pcurr = *pb_dst;
    for (; pb_src < pe_src; pb_src++)
    {
        if (*pb_src > average)
        {
            *pcurr = *pb_src;
            pcurr++;
        }
    }
    *pe_dst = pcurr;
}

// Filter - function
// Will delete all elements below average
int key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst)
{
    int error = 0;

    int src_size = pe_src - pb_src;
    int dst_size = 0;
    *pb_dst = NULL;

    float average;

    if (!src_size) // src array is empty
        error = -1;

    if (!error)
    {
        average = count_average(pb_src, pe_src);
        dst_size = new_size(pb_src, pe_src, average);

        if (!dst_size) // dst array is empty
            error = -2;

        if (!error)
        {
            *pb_dst = (int*) malloc(dst_size * sizeof(int));
            if (*pb_dst)
                move_elements(pb_src, pe_src, pb_dst, pe_dst, average);
            else
                error = -3; // malloc error
        }
    }
    return error;
}
