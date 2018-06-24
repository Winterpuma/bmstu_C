/*
 * This program counts down dispersion value for sqc.
*/

#include "stdio.h"

float expected_value(FILE *f)
{
    float current, sum = 0;
    int count = 0;

    while (1)
    {
        fscanf(f, "%f", &current);
        if (feof(f))
            break;
        sum += current;
        count += 1;
    }
    return (sum / count);
}

float dispersion(FILE *f, float ex_value)
{
    float current, sum = 0, disp;
    int count = 0;

    while (1)
    {
        fscanf(f, "%f", &current);
        if (feof(f))
            break;
        sum += (current - ex_value)*(current - ex_value);
        count += 1;
    }
    disp = sum / count;
    return disp;
}


int main(int argc, char **argv)
{
    FILE *f;
    float ex_value, disp;

    if (argc != 2)
    {
        printf("You forgot about file name.");
        return -1;
    }

    f = fopen(argv[1], "r");

    if (f == NULL)
    {
        printf("File doesn't exist.");
        return -2;
    }

    ex_value = expected_value(f);
    printf("Expected value: %f\n", ex_value);

    rewind(f);
    disp = dispersion(f, ex_value);
    printf("Dispersion for this sqc is: %f.", disp);
    fclose(f);
    return 0;
}

