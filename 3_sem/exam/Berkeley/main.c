#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "list.h"

#define N 10

// !!!
// сгенерировать числа.
// В один список Беркли поместить четные в другой - нечетные, вывод, освобождение памяти
// gcc main.c
// ./a.exe
// !!!!

struct element
{
    int n;
    struct list_head list;
};

int main()
{
    srand(time(NULL));
    LIST_HEAD(odd);
    LIST_HEAD(even);

    struct element *item;
    for (int i = 0; i < N; i++)
    {
        item = malloc(sizeof(struct element));
        if (!item)
            break;

        item->n = rand()%20;
        if (item->n % 2)
        {
            item->list = odd;
            list_add_tail(&(item->list), &odd);
        }
        else
        {
            item->list = even;
            list_add_tail(&(item->list), &even);
        }
    }

    // PRINT
    puts("Odd: ");
    list_for_each_entry(item, &odd, list)
        printf("%d ", item->n);
    puts("\nEven: ");
    list_for_each_entry(item, &even, list)
        printf("%d ", item->n);

    // FREE
    struct list_head *iter;
    struct list_head *iter_safe;

    list_for_each_safe(iter, iter_safe, &odd)
    {
        item = list_entry(iter, struct element, list);
        list_del(iter); // Удаляем элемент списка
        free(item);
    }

    list_for_each_safe(iter, iter_safe, &even)
    {
        item = list_entry(iter, struct element, list);
        list_del(iter);
        free(item);
    }

    printf("\n");

    return 0;
}
