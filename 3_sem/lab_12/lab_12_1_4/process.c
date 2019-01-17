#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "input.h"
#include "filter.h"
#include "sort.h"
#include "output.h"
#include "process.h"

/**
 * Main processing function
 * @param f_in - FILE with input data
 * @param f_out - FILE for output data
 * @param flag - flag for filter
 */
int go(FILE *f_in, FILE *f_out, int flag)
{
    int size;
    int *a, *ae = NULL; // initial array
    int *bb, *be = NULL; // array after filtering
    int error;

    size = file_error(f_in, f_out);
    if (size < 0)
        return size;

    a = (int*) malloc(size * sizeof(int));
    ae = a + size;

    if (a == NULL)
    {
        printf("Malloc error.\nSize: %d", size);
        return -2;
    }
    rewind(f_in);
    read_file(f_in, a);

    if (flag == 0) // check args for flag
    {
        float average = count_average(a, ae);
        int dst_size = new_size(a, ae, average);
        bb = (int*) malloc(dst_size * sizeof(int));
        error = key(a, a+size, bb);

        if (!error)
        {
            be = bb + dst_size;
            mysort(bb, be - bb, sizeof(*a), compare_int);
            fill_file(f_out, bb, be);
            free(bb);
        }
        else
            filter_error(error, f_out);
    }
    else
    {
        mysort(a, ae - a, sizeof(a[0]), compare_int);
        fill_file(f_out, a, &a[size]);
    }

    free(a);
    return 0;
}

/**
 * Checks input file for errors
 * @param f_in - FILE with input data
 * @param f_out - FILE for output data
 * @return size of file or error
 */
int file_error(FILE *f_in, FILE *f_out)
{
    if (f_in == NULL)
    {
        printf("File doesn't exist\n");
        fprintf(f_out, "File error");
        return -2;
    }

    int size = count_size(f_in);

    if (!size)
    {
        printf("File is empty\n");
        fprintf(f_out, "File is empty");
        return -3;

    }
    rewind(f_in);
    return size;
}

/**
 * Processes errors of filter function
 * @param error - error key
 * @param f_out - Output file
 */
void filter_error(int error, FILE *f_out)
{
    if (error == -1 )
    {
        printf("File is empty\n");
        fprintf(f_out, "File is empty");
    }
    else if (error == -2)
    {
        printf("Empty array after filtering\n");
        fprintf(f_out, "Empty array after filtering");
    }
    else if (error == -3)
        printf("Malloc error\n");
}
