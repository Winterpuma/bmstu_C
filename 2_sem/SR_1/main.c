#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "math.h"

void result(int a1, int a2, int a3, int a4, int mask)
{
    int m1[4] = {a1, a2, a3, a4};
    int m2[4];
    int m3[4];

    for (int i=0; i<4; i++)
    {
        if (mask >= 8)
        {
            m2[i] = 255;
            mask -= 8;
        }
        else if (mask > 0)
        {
            m2[i] = pow(2, mask) - 1;
            mask = 0;
        }
        else
        {
            m2[i] = 0;
        }
    }

    for (int i=0; i<4; i++)
    {
        m3[i] = m1[i] & m2[i];
    }

    printf("\n%d.%d.%d.%d\n", m3[0], m3[1], m3[2], m3[3]);
}

int main()
{
    FILE *f;
    int a1, a2, a3, a4;
    int mask;

    f = fopen("data.txt", "r");
    if (f == NULL)
    {
        printf("Coundn't open file.");
    }
    else
    {
        fscanf(f, "%d.%d.%d.%d/%d", &a1, &a2, &a3, &a4, &mask);

        printf("%d.%d.%d.%d", a1, a2, a3, a4);
        printf("\nMask: %d", mask);

        result(a1, a2, a3, a4, mask);
    }

    fclose(f);
    return 0;
}
