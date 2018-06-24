/*
 * Program takes inputed array and sorts it.
*/
#include "stdio.h"

// This finction sorts array. (insertion sort)
void sort(int *array, int len)
{
    int tmp;
    int j;

    for (int i=1; i<len; i++)
    {
        tmp = array[i];
        j = i-1;
        while ((j >= 0) && (array[j] > tmp))
        {
            array[j+1] = array[j];
            j -= 1;
        }
        array[j+1] = tmp;
    }

}

int main()
{
    int num, m[10];
    int len = 0;

    printf("Input sqc: ");
    while (scanf("%d", &num))
    {
        m[len] = num;
        len++;
        if (len == 10)
            break;
    }

    printf("\nInput finished.\n");
    if (!len)
        printf("\nYou must enter at least one number.");
    else if (len == 1)
        printf("\nNew array: %d", m[0]);
    else
    {
        printf("\nNew array: ");

        sort(m, len);

        for (int i=0; i<len; i++)
        {
            printf("%d ", m[i]);
        }
    }
    return 0;
}
