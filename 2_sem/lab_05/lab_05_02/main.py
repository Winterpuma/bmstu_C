/*
 * This program takes array from file. And returns anser to 
 * x[0] + x[0]*x[1] + ... + x[0]*x[1]*x[2] ... x[m]
 * where m - index of first negative number
*/


#include <stdio.h>
#include <stdlib.h>
#define N 100


float func(const float *ab, const float *ae)
{
    float element = 1;
    float sum = 0;
    while (ab < ae)
    {
        element *= *ab;
        sum += element;
        if (*ab < 0)
            break;
        ab++;
    }
    return sum;
}

int main()
{
    FILE *f = fopen("data.txt", "r");
    float a[N];
    float *ae;
    ae = a;
    float result;
    while (fscanf(f, "%f", ae))
    {
        if (feof(f))
            break;
        ae++;
        if ((ae - a) == N)
            break;
    }
    result = func(a, ae);
    printf("\nResult: %f", result);
    return 0;
}
