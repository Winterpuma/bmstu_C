#include <stdio.h>
#include "math.h"

int main()
{
    float xa, ya, xb, yb, xc, yc;
    float ab, ac, bc;
    float perimetr, p, s;

    printf("Input coords xa ya xb yb xc yc: ");
    scanf("%f%f%f%f%f%f", &xa, &ya, &xb, &yb, &xc, &yc);

    ab = sqrt((xa-xb)*(xa-xb)+(ya-yb)*(ya-yb));
    ac = sqrt((xa-xc)*(xa-xc)+(ya-yc)*(ya-yc));
    bc = sqrt((xb-xc)*(xb-xc)+(yb-yc)*(yb-yc));

    perimetr = ab + ac + bc;
    printf("Perimetr: %f\n", perimetr);

    return 0;
}
