/*
 * This program takes numbers, writes them down to array,
 * creates new array with only prime numbers.
*/
#include "stdio.h"

// This function takes number, returns weather it prime or not
int prime(int num)
{
    if (num < 1)
        return 0;
    if (num == 1)
        return 1;
    else
        for (int i=2; i<num; i++)
        {
            if (num % i == 0)
                return 0;
        }
    return 1;
}

// This function fills new array with only prime numbers
void new_array(int old_m[], int *new_m, int size_old)
{
    int j = 0;
    for (int i=0; i<size_old; i++)
    {
        if (prime(old_m[i]))
        {
            new_m[j] = old_m[i];
            j++;
        }

    }
}


int main()
{
    int num, m[10];
    int count_len = 0, count_prime = 0;

    printf("Input sqc: ");
    while (scanf("%d", &num))
    {
        m[count_len] = num;
        count_len++;
        if (prime(num))
            count_prime++;
        if (count_len == 10)
            break;
    }

    printf("\nInput finished.\n");
    if (!count_len)
        printf("\nYou must enter at least one number.");
    else if (!count_prime)
        printf("\nNo prime numbers inputed.");
    else
    {
        int new_m[count_prime];
        new_array(m, new_m, count_len);
        for (int i=0; i<count_prime; i++)
        {
            printf("%d ", new_m[i]);
        }
    }
    return 0;
}
