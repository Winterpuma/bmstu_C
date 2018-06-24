/*
 * In this program you will input a sqc, program will print out product of odd numbers.
*/

#include "stdio.h"

//This function takes sqc of numbers and prints out product of odd numbers.
void product(int m[], int size)
{
    int p = 1;
    int flag = 0;

    for(int i = 0; i<size; i++)
    {
       if ((m[i] % 2 == 1) || (m[i] % 2 == -1))
       {
           flag = 1;
           p *= m[i];
       }
    }
    if (flag)
        printf("\nProduct of odd numbers is: %d", p);
    else
        printf("\nNo odd numbers in sqc.");
}

int main()
{
    int num, m[10];
    int count = 0;

    printf("Input sqc: ");
    while (scanf("%d", &num))
    {
        m[count] = num;
        count++;
        if (count == 10)
            break;
    }

    printf("\nInput finished.");
    if (!count)
        printf("\nYou must enter at least one number.");
    else
        product(m, count);

    return 0;
}
