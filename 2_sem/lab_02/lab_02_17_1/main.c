/*
 * This program takes 1 positive number and prints it out by numerals.
*/
#include <stdio.h>

void split(int number)
{
    int number2, numeral;
    int decimal = 1;

    number2 = number;
    while (number2)
    {
        number2 /= 10;
        decimal = decimal * 10;
    }
    decimal = decimal / 10;

    printf("Numerals: ");
    while (decimal)
    {
        numeral = number / decimal;
        number = number % decimal;
        printf(" %d", numeral);
        decimal = decimal/10;
    }
}

int main()
{
    int number1;

    printf("Input number: ");
    scanf("%d", &number1);

    if (number1 > 0)
    {
        split(number1);
    }
    else if(number1 < 0)
    {
        printf("Number must be positive.");
    }
    else
    {
        printf("Wrong input.");
    }

   return 0;
}
