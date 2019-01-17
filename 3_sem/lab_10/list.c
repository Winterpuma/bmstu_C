#include <stdlib.h>
#include <stdio.h>

#include "list.h"

/**
 * Free all list including data
 * @param head - list head
 */
void free_list_all(node_t **head)
{
    node_t *tmp;
    for ( ; *head; *head = tmp)
    {
        tmp = (*head)->next;
        if ((*head)->data)
            free((*head)->data);
        free(*head);
    }
}

/**
 * Read int list from file
 * @param f file
 * @return head of list
 */
node_t *read_from_file(FILE *f)
{
    node_t *head = NULL;
    node_t *cur;
    int *tmp = malloc(sizeof(int));

    while (fscanf(f, "%d\n", tmp) == 1)
    {
        cur = create_node((void *)tmp);
        insert(&head, cur, NULL);
        tmp = malloc(sizeof(int));
    }
    free(tmp);
    return head;
}

/**
 * Outputs list with int data to file
 * @param f file
 * @param head - list head
 */
void write_to_file(FILE *f, node_t *head)
{
    for ( ; head; head = head->next)
        fprintf(f, "%d\n", *((int *)head->data));
}


/**
 * Prints list with data of type int
 * @param head - list head
 */
void print_int_list(node_t *head)
{
    for ( ; head; head = head->next)
    {
        printf("%d ", *((int *)head->data));
    }
    printf("\n");
}

/**
 * Allocate memory for node
 * @return node address
 */
node_t *create_node(void *data)
{
    node_t *node = calloc(1, sizeof(node_t));
    node->data = data;
    return node;
}


/**
 * Pop back node from list
 * @param head - pointer to head element of list
 */
void *pop_back(node_t **head)
{
    void *data = NULL;

    node_t *tmp = *head;
    if (tmp)
    {
        if (tmp->next)
        {
            for (; tmp->next->next; tmp = tmp->next);
            data = tmp->next->data;
            free(tmp->next);
            tmp->next = NULL;
        }
        else
        {
            data = tmp->data;
            free(tmp);
            *head = NULL;
        }
    }

    return data;
}


/**
 * Insert node elem to list before before
 * @param head - pointer to list head
 * @param elem - node to insert
 * @param before - insert before "before" node
 */
void insert(node_t **head, node_t *elem, node_t *before)
{
    node_t *tmp = *head;

    if (!*head)
    {
        if(!before)
            *head = elem;
    }
    else if (*head == before)
    {
        elem->next = before;
        *head = elem;
    }
    else
    {
        if (tmp->next && tmp->next != before)
        {
            for (; tmp->next->next && (tmp->next->next != before); tmp = tmp->next);

            if (tmp->next->next == before)
                tmp = tmp->next;

        }

        if ((tmp ->next) == before)
        {
            tmp->next = elem;
            elem->next = before;
        }
    }
}

/**
 * Reverses list using 3 pointers
 * @param head - head of list
 * @return new head
 */
node_t* reverse(node_t *head)
{
    if (!head)
        return NULL;

    node_t *new_head = head, *cur = head;

    if (head->next)
    {
        for ( ; new_head->next; new_head = new_head->next);

        //create loop
        for( ; cur->next != new_head; cur = cur->next);
        new_head->next = cur;

        while (head->next->next != head)
        {
            cur = head;
            for( ; cur->next != cur->next->next->next; cur = cur->next); // go to loop
            cur->next->next = cur;
        }

        head->next = NULL;
    }

    return new_head;
}

/**
 * Compare two integers
 * @param a - pointer to first int
 * @param b - pointer to second int
 * @return >0 if a > b, <0 a < b
 */
int comparator_int(const void *a, const void *b)
{
    return *((int *) a) - *((int *) b);
}

/**
 * Insertion sort of list
 * @param head - list head
 * @param comparator - function for comparison
 * @return - head of sorted list
 */
node_t* sort(node_t *head, int (*comparator)(const void *, const void *))
{
    node_t *new_head = NULL;
    node_t *next_cur = NULL;

    if (head)
    {
        for ( ; head; head = next_cur)
        {
            next_cur = head->next;
            sorted_insert(&new_head, head, comparator);
        }
    }

    return new_head;
}


/**
 * Insert node to sorted list
 * @param head - pointer to list head
 * @param element - node to insert
 * @param comparator - function of comparison
 */
void sorted_insert(node_t **head, node_t *element, int (*comparator)(const void *, const void *))
{
    node_t *cur = *head;
    if (!cur)
    {
        element->next = NULL;
        *head = element;
    }
    else
    {
        while (cur && comparator(cur->data, element->data) < 0)
            cur = cur->next;

        insert(head, element, cur);
    }
}
