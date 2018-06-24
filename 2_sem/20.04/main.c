#include "stdio.h"
#include "string.h"

int length_of_hex(int number)
{
    int count = 0;
    while (number/16)
    {
        count++;
        number /= 16;
    }
    return count;
}

void convert(int num)
{
    int len, i;
    len = length_of_hex(num);
    i = length_of_hex(num);

    char m[len];
    while(num>0)
    {
        switch (num%16)
        {
        case 10:
            m[i] = 'A';
            break;
        case 11:
            m[i] = 'B';
            break;
        case 12:
            m[i] = 'C';
            break;
        case 13:
            m[i] = 'D';
            break;
        case 14:
            m[i] = 'E';
            break;
        case 15:
            m[i] = 'F';
            break;
        default:
            m[i] = num%16;
            break;
        }
        num /= 16;
        i--;
    }

    for (int i=0; i<len+1; i++)
    {
        if (m[i] < 10)
            printf("%d", m[i]);
        else
            printf("%c", m[i]);
    }

}

int main()
{
    int dec;
    printf("Input dec: ");
    scanf("%d", &dec);

    printf("\nHex: ");
    if (dec == 0)
        printf("0");
    else
    {
        if (dec < 0)
        {
            printf("-");
            dec *= -1;
        }
        convert(dec);
    }
    return 0;
}
