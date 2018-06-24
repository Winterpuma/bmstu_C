#include "stdio.h"
#include "math.h"

// Takes natural number, returns sum of first and last digit.
void sum(int num)
{
    int first_d, last_d;
    int sum;

    if (num < 10)
        printf("Number have to be positive, at contain at least 2 digits");
    else
    {
        first_d = num;
        last_d = num % 10;
        while (first_d > 10)
            first_d /= 10;
        sum = first_d + last_d;
        printf("\n\nFirst digit is: %d", first_d);
        printf("\nLast digit is: %d", last_d);
        printf("\nTheir sum is: %d", sum);
    }
}

// sqc of 3 digit numbers; finds out max odd number; sum of negative nums
void sqc()
{
    int number, sum = 0, max;
    int flag = 1, flag_char;

    printf("\nInput sqc of 3-digit numbers: ");
    while (1)
    {
        flag_char = scanf("%d", &number);
        if (!flag_char)
            break;
        if (number == 349)
            break;
        if ((abs(number) < 100) ||  (abs(number) > 999))
            break;
        if (number < 0)
            sum += number;
        if ((number % 2 == 1) || (number % 2 == -1))
        {
            if (flag)
            {
                max = number;
                flag = 0;
            }
            if (number > max)
            max = number;
        }

    }
    printf("\nInput finished.");
    printf("\nSum of negative numbers is: %d", sum);
    if (flag)
        printf("\nNo odd numbers in sqc.");
    else
        printf("\nMax odd number is: %d", max);
}

// this function prints out all numbers in file that are divisible by 7
void file(FILE *f)
{
    int num;
    int flag = 0;
    if (f == NULL)
        printf("No such file.");
    else
    {
        while (1)
        {
            fscanf(f, "%d", &num);
            if (feof(f))
                break;
            if ((num != 0) && (num % 7 == 0))
            {
                flag = 1;
                printf("%d ", num);
            }
        }
        if (!flag)
            printf("No numbers divisible by 7 in file.");
    }
}
int main()
{
    FILE *f;
    f = fopen("test.txt", "r");

    file(f);
    sqc();
    sum(923298);

    return 0;
}
