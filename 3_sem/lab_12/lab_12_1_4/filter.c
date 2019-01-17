#include <stdio.h>
#include <stdlib.h>

#include "filter.h"

/**
 * Will count average of array
 * @param pb - pointer to beginning of array
 * @param pe - pointer to ending of array
 * @return average
 */
float count_average(const int *pb, const int *pe)
{
    float sum = 0;
    int size = pe - pb;

    for (; pb < pe; pb++)
        sum += *pb;

    return sum / size;
}

/**
 * Will count amount of elements above average
 * @param pb - pointer to beginning of array
 * @param pe - pointer to ending of array
 * @param average
 * @return new size of array
 */
int new_size(const int *pb, const int *pe, int average)
{
    int dst_size = 0;
    for (; pb < pe; pb++)
        if (*pb > average)
            dst_size++;
    return dst_size;
}

/**
 * Will move elements from src array to dst array above average
 * @param pb_src - pointer to beginning of source array
 * @param pe_src - pointer to ending of source array
 * @param pb_dst - pointer to beginning of dest array
 * @param average
 */
void move_elements(const int *pb_src, const int *pe_src, int *pb_dst, float average)
{
    int *pcurr = pb_dst;
    for (; pb_src < pe_src; pb_src++)
    {
        if (*pb_src > average)
        {
            *pcurr = *pb_src;
            pcurr++;
        }
    }
}

// Filter - function
/**
 * Will delete all elements below average
 * @param pb_src - pointer to beginning of source array
 * @param pe_src - pointer to ending of source array
 * @param pb_dst - pointer to beginning of dest array
 * @return error: 0 - if ok
 */
int key(const int *pb_src, const int *pe_src, int *pb_dst)
{
    if (!pb_dst || !pb_src)
        return -3;

    int error = 0;

    int src_size = pe_src - pb_src;
    int dst_size = 0;

    float average;

    if (!src_size) // src array is empty
        error = -1;

    if (!error)
    {
        average = count_average(pb_src, pe_src);
        dst_size = new_size(pb_src, pe_src, average);

        if (dst_size)
            move_elements(pb_src, pe_src, pb_dst, average);
        else
            error = -2;
    }
    return error;
}
