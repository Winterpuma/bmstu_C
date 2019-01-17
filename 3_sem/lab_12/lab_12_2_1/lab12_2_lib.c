#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "lab12_2_lib.h"

/*
 * Вариант 1
1. Реализовать функцию циклического сдвига массива на k позиций влево.
2. Реализовать функцию, которая из одного массива помещает в другой элементы
первого, которые являются полными квадратами.
 */

void print_arr(int *arr, int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
}

/**
 * Shift array to left by k positions.
 * @param arr - array
 * @param n  - array size
 * @param k - shift distance
 */
void shift_array(int *arr, int n, int k)
{
    if (k < 0)
        return;
    int tmp;

    k = k % n;
    for ( ; k; k--)
    {
        tmp = arr[0];
        for (int j = 0; j < n - 1; j++)
            arr[j] = arr[j + 1];
        arr[n - 1] = tmp;
    }
}

/**
 * Check out if n is square number
 * @param n - number
 * @return 1 if square number, 0 - else
 */
int is_square_num(int n)
{
    double sq_root = sqrt(n);
    return (floor(sq_root) == sq_root) ? 1 : 0;
}

/**
 * Creates new array with only square numbers from elements
 * of existing array.
 * @param arr - array with numbers
 * @param n - size of array
 * @param res_n - pointer to new size of new array
 * @return new array
 */
int *square_numbers(int *arr, int n, int *res_n)
{
    int *res = malloc(n * sizeof(int));
    *res_n = 0;

    for (int i = 0; i < n; i++)
        if (is_square_num(arr[i]))
            res[(*res_n)++] = arr[i];

    return res;
}
