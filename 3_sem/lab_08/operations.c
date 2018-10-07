#include <stdio.h>
#include <math.h>
#include "operations.h"
#include "output.h"

#define EPS 0.001

// Will add elements of second matrix to first
float **addition(float **matr1, float **matr2, int n, int m)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            matr1[i][j] += matr2[i][j];
    return matr1;
}


// Multiply two matrices and return resulted matrix
float **multiplication(float **matr1, float **matr2, float **res, int n1, int m1, int n2, int m2)
{
    //m1 == n2!
    //size of new N1xM2
    float tmp;
    for (int i = 0; i < n1; i++)
        for (int j = 0; j < m2; j++)
        {
            tmp = 0;
            for (int k = 0; k < m1; k++)
                tmp += matr1[i][k] * matr2[k][j];
            res[i][j] = tmp;
        }
    return res;
}

// Swap two rows in matrix
void swap_rows(float **matr, int n1, int n2)
{
    float *tmp = matr[n1];
    matr[n1] = matr[n2];
    matr[n2] = tmp;
}

// Will find max element in column and return row index of that element
int max_in_col(float **matr, int col_index, int n)
{
    int max_row = col_index;
    for (int i = col_index; i < n; i++)
    {
        if (fabs(matr[i][col_index]) > fabs(matr[max_row][col_index]))
            max_row = i;
    }
    return max_row;
}

// Add row1 to row2 multiplied by multiplier
void add_rows(float **matr, int n, int row1, int row2, float multiplier)
{
    for (int i = 0; i < n; i++)
        matr[row2][i] += matr[row1][i] * multiplier;
}

// Triangulate given matrix
void triangulation(float **matr, int n)
{
    float multiplier;
    int imax;

    for (int i = 0; i < n; i++)
    {
        imax = max_in_col(matr, i, n);
        if (!matr[imax][i])
            break;
        swap_rows(matr, i, imax);
        for (int j = i+1; j < n; j++)
        {
            multiplier = -1 * matr[j][i] / matr[i][i];
            add_rows(matr, n, i, j, multiplier);
        }
    }
}

// Counts determinator of matrix
float determinator(float **matr, int n)
{
    float det = 1;
    triangulation(matr, n);
    for (int i = 0; i < n; i++)
        det *= matr[i][i];
    return det;
}

// returns 0 if number is in [-EPS; +EPS] range
int compare_zero(float num)
{
    int flag = 1;

    if (fabs(num) < EPS)
        flag = 0;

    return flag;
}

// returns 0 if |num1-num2| < EPS
int compare_float(float num1, float num2)
{
    num1 -= num2;
    return compare_zero(num1);
}

