/*
Лабораторная #8

Способ выделения памяти:
3. Объединенный подход, способ 2
Формат файлов:
2. Координатный формат.
Операция:
8. Вычисление определителя методом Гаусса.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "input.h"
#include "memory.h"
#include "operations.h"
#include "output.h"
#include "process.h"

int main(int argc, char *argv[])
{
    int flag = check_args(argc, argv);

    if (flag > 0)
        process(argv, flag);

    return 0;
}

