#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "process.h"

/*
5. Модифицированная сортировка пузырьком I. Запоминайте, где произошел последний
обмен элементов, и при следующем проходе алгоритм не заходит за это место. Если
последними поменялись i-ый и i+1-ый элементы, то при следующем проходе алгоритм не
сравнивает элементы за i-м.

4. В массиве остаются элементы, которые больше среднего арифметического всех
элементов массива.
*/

int main(int argc, char *argv[])
{
    int flag = 0;

    FILE *f_in;
    FILE *f_out;

    if (argc < 3)
    {
        fprintf(stderr, "ERROR: Main got too few arguments.");
        return -1;
    }

    f_in = fopen(argv[1], "r");
    f_out = fopen(argv[2], "w");

    flag = go(f_in, f_out, strcmp(argv[argc - 1], "f"));

    fclose(f_in);
    fclose(f_out);

    return flag;
}

