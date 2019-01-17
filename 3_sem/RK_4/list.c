#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "student.h"

void push(node **list, void *data, int index)
{
    struct node *tmp = malloc(sizeof(struct node));
    struct node *cur;

    if (!tmp)
        return;

    tmp->data = data;

    if (*list)
    {
        cur = *list;
        for (int i = 0; i < index; cur = cur->next, i++);
        tmp->next = cur;
        tmp->prev = cur->prev;
        tmp->next->prev = tmp;
        tmp->prev->next = tmp;
        if (!index) // if pushing to head
            *list = tmp;
    }
    else
    {
        tmp->next = tmp;
        tmp->prev = tmp;
        *list = tmp;
    }
}

node *pop(node *list_h, int index)
{
    struct node *cur = list_h;
    struct node *prev, *next;

    if (cur == cur->next)
    {
        free_stud((student *)cur->data);
        free (cur);
        return NULL;
    }

    for (int i = 0; i < index; cur = cur->next, i++);

    prev = cur->prev;
    next = cur->next;
    prev->next = cur->next;
    next->prev = cur->prev;
    free(cur);
    return index ? list_h :next;
}

void print(node *list, int flag_student)
{
    node *tmp = list;

    if (!list)
        printf("List is empty!\n\n");
    else
    {
        do
        {
            if (flag_student)
                print_stud((struct student *) tmp->data);
            else
                printf("%d ", *((int *)tmp->data));
            tmp = tmp->next;
        }
        while ((tmp != list) && tmp);
    }
}

void free_list(node *list, int flag_student)
{
    if (list)
    {
        node *cur = list, *beg = list->prev, *next = list->next;
        while (cur && (cur != beg))
        {
            if (flag_student)
                free_stud((student *)cur->data);
            else
                free(cur->data);

            free(cur);
            cur = next;
            next = cur->next;
        }
    }
}
