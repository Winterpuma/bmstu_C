#include <stdio.h>
#include <string.h>

void convert(FILE *f, char m1[], char m2[], float m2_num)
{
    if(!strcmp(m1,"cm") && !strcmp(m2,"m"))
    {
        printf("%f cm", m2_num*100);
        fprintf(f, "%f cm", m2_num*100);
    }
    else if(!strcmp(m1,"g") && !strcmp(m2,"kg"))
    {
        printf("%f g", m2_num*1000);
        fprintf(f, "%f g", m2_num*1000);
    }
    else if(!strcmp(m1,"ml") && !strcmp(m2,"l"))
    {
        printf("%f ml", m2_num*1000);
        fprintf(f, "%f ml", m2_num*1000);
    }
    else
    {
        printf("Input error.");
        fprintf(f, "Input error.");
    }
}


int main()
{
    FILE *f;
    f = fopen("data.txt", "w");

    char m1[3];
    char m2[3];
    float m2_num;
    int flag;

    flag = scanf("how many %s in %f %s", m1, &m2_num, m2);
    if (flag == 3)
    {
        convert(f, m1, m2, m2_num);
    }
    else
    {
        printf("Input error.");
        fprintf(f, "Input error.");
    }

    fclose(f);
    return 0;
}
