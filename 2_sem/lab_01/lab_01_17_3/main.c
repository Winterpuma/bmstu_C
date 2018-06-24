#include <stdio.h>

int main()
{
    float R1, R2, R3, R;
    
    printf("Input R1 R2 R3: ");
    scanf("%f%f%f", &R1, &R2, &R3);

    R = 1/((1/R1)+(1/R2)+(1/R3));

    printf("Total resistance: %f", R);

    return 0;
}