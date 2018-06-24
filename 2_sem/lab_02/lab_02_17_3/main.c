/*
 * This program counts approximate value of the function s(x),
 * exact value of the function f(x), absolute and relative errors
 * of the approximate values.
*/

#include "stdio.h"
#include "math.h"

/*
 * This function takes x and counts down approximate value of
 * function based on eps.
 * term - current sum element.
*/
double s(double x, double eps)
{
    double term = 1;
    double sum = 0;
    double t = x*x;
    int count = 1;

    while (term > eps)
    {
        sum += term;
        term *= (count * t) / (count + 1);
        count += 2;
    }
    return sum;
}

int main()
{
    double x, Fx, Sx;
    double eps;
    double absolute_err, relative_err;

    printf("Function: 1 / sqrt(1 - x*x)\n\n");
    printf("Input x, eps: ");
    scanf("%lf%lf", &x, &eps);

    if (eps <= 0)
    {
        printf("Program takes onle positive eps.");
    }
    else if ((x > -1) && (x < 1))
    {
        Fx = 1/(sqrt(1-(x*x)));
        Sx = s(x, eps);
        printf("\nFx: %lf \nSx: %lf", Fx, Sx);
        absolute_err = fabs(Fx - Sx);
        relative_err = fabs(absolute_err / Fx);
        printf("\n\nAbsolute error: %lf", absolute_err);
        printf("\nRelative error: %lf", relative_err);
    }
    else
    {
        printf("|x| must be < 1!");
    }
    return 0;
}
