/*
 * This program can create file and fill it in with random numbers;
 * output numbers that are in file, sort numbers in file.
 * Sorting method: bouble sort.
 * Type of numbers: int.
*/

#include "stdio.h"
#include "stdlib.h"
#include "time.h"

int create(FILE *f)
{
    int rand_num, quantity;

    printf("\nInput amount of random numbers in file: ");
    scanf("%d", &quantity);

    srand(time(NULL));
    for (int i=0; i<quantity; i++)
    {
        rand_num = rand() % 20;
        fwrite(&rand_num, sizeof(int), 1, f);
    }

    return quantity;
}


void print(FILE *f)
{
    int num;
    rewind(f);
    printf("\n");
    while (1)
    {
        fread(&num, sizeof(num), 1, f);
        if (feof(f))
            break;
        printf("%d ", num);
    }
}


int get_num_by_pos(FILE *f, int pos)
{
    int num;
    pos *= sizeof(int);
    fseek(f, pos, SEEK_SET);
    fread(&num, sizeof(int), 1, f);
    return num;
}


void put_num_by_pos(FILE *f, int pos, int num)
{
    pos *= sizeof(int);
    fseek(f, pos, SEEK_SET);
    fwrite(&num, sizeof(int), 1, f);
}


void sort(FILE *f, int n)
{
    int  a1, a2;
    for (int i=0; i<(n-1); i++)
        for (int j=0; j<(n-i-1); j++)
        {
            a1 = get_num_by_pos(f, j);
            a2 = get_num_by_pos(f, j+1);
            if (a1 > a2)
            {
                    put_num_by_pos(f, j, a2);
                    put_num_by_pos(f, j+1, a1);
            }
        }
}


int main()
{
    int n;
    FILE *f;

    f = fopen("data.dat", "wb");
    n = create(f);
    fclose(f);

    f = fopen("data.dat", "r+b");
    printf("Sqc:");
    print(f);

    sort(f, n);
    printf("\nSorted sqs: ");
    print(f);
    fclose(f);

    return 0;
}
