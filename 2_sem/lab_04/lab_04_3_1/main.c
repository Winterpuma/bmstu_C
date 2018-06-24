/*
 * This program takes array, creates new one and pastes Fib numbers
 * after every element of array that is divisible by 3.
*/
#include "stdio.h"

// This function adds Fibb numbers after all numbers divisible by 3
void new_array(int old_m[], int *new_m, int size_old)
{
    int j = 0;
    int fib1 = 0, fib2 = 1, tmp;

    for (int i=0; i<size_old; i++)
    {
        new_m[j] = old_m[i];
        j++;
        if ((old_m[i] % 3 == 0) && (old_m[i] != 0))
        {
            new_m[j] = fib1;
            j++;
            tmp = fib1;
            fib1 = fib2;
            fib2 += tmp;
        }
    }
}

int main()
{
    int num, m[10];
    int count_len = 0, count_div = 0;

    printf("Input sqc: ");
    while (scanf("%d", &num))
    {
        m[count_len] = num;
        count_len++;
        if ((num % 3 == 0) && (num != 0))
            count_div++;
        if (count_len == 10)
            break;
    }

    printf("\nInput finished.\n");
    if (!count_len)
        printf("\nYou must enter at least one number.");
    else
    {
        if (!count_div)
            printf("\nNo numbers divisible by 3 inputed.");
        printf("\nNew array: ");

        int new_m[count_div+count_len];

        new_array(m, new_m, count_len);
        for (int i=0; i<(count_div+count_len); i++)
        {
            printf("%d ", new_m[i]);
        }
    }
    return 0;
}
