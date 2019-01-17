#include <stdlib.h>
#include "my_list.h"
#include "structures.h"

/**
 * Add element to tail of list
 * @param list - pointer to head of list
 * @param element - student to add
 */
void push_standard_list(std_t *list, std_t element)
{
    std_t curr;
    if (!*list)
        *list = element;
    else
    {
        for (curr = *list ; curr->next; curr = curr->next);
        curr->next = element;
    }
}

/**
 * Pop element by index from list
 * @param list - pointer to list head
 * @param i - index
 * @return 0 - if deleted successfully, -1 - else
 */
int pop_standard_list(std_t *list, int i)
{

    std_t curr = *list, prev = NULL;
    int j;
    int flag = -1;

    if (!*list)
        return -1;

    if (i == 0)
    {
        free(*list);
        *list = curr->next;
    }
    else
    {
        for (j = 0; j < i && curr->next; j++, prev = curr, curr = curr->next);
        if (i == j)
        {
            prev->next = curr->next;
            free(curr);
            flag = 0;
        }
    }
    return flag;
}

/**
 * Free memory of list
 * @param list - pointer to list head
 */
void free_standard_list(std_t *list)
{
    std_t tmp;
    for ( ; *list; *list = tmp)
    {
        tmp = (*list)->next;
        free(*list);
    }
}

/**
 * Print list of students to console
 * @param stud
 */
void print_standard_list(std_t stud)
{
    if (!stud)
        printf("List is empty.");
    else
    {
        for (int i = 0; stud; i++, stud = stud->next)
        {
            printf("\nIndex: %d", i);
            output_student_console(*stud);
        }
    }
}

/**
 * Go to i'th term in list
 * @param list - list head
 * @param i - term number
 * @return - pointer to i'th term
 */
std_t list_i(std_t list, int i)
{
    int j;
    for (j = 0; j < i && list; j++, list = list->next);

    return (i == j) ? list : NULL;
}

/**
 * Find out standard list size
 * @param list - list head
 * @return - size
 */
int list_size(std_t list)
{
    int size = 0;
    for ( ; list; list = list->next, size++);
    return size;
}


/**
 * Push student to sorter Berkeley list
 * @param stud - student
 * @param head - head of sort list
 * @param field - field number of sort list
 * @param cmp - function for comparison
 */
void push_berkeley_sorted(std_t stud, struct list_head *head, int field, int (*cmp)(std_t, std_t))
{
    std_t item = NULL;
    struct list_head *iter;
    struct list_head *insert_el = &(stud->sort[field]);

    list_for_each(iter, head)
    {
        item = list_entry(iter, struct Student, sort[field]);
        if (cmp(item, stud) > 0)
        {
            insert_el->prev = iter->prev;
            iter->prev->next = insert_el;
            insert_el->next = iter;
            iter->prev = insert_el;
            break;
        }
        else if (iter->next == head)
        {
            list_add_tail(insert_el, head);
            break;
        }
    }

    if (!item)
        list_add_tail(insert_el, head);
}

/**
 * Push students to all Berkeley lists
 * @param stud - student
 * @param sort - array with heads of sorted lists
 * @param filter - array with heads of filtered lists
 */
void push_berkeley_all(std_t stud, struct list_head **sort, struct list_head **filter)
{
    push_berkeley_sorted(stud, sort[0], 0, compare_age);
    push_berkeley_sorted(stud, sort[1], 1, compare_grage);
    push_berkeley_sorted(stud, sort[2], 2, compare_year);
    if (stud->sex == FILTER_GENDER)
        list_add_tail(&(stud->filter[0]), filter[0]);
    if (stud->age <= FILTER_AGE)
        list_add_tail(&(stud->filter[1]), filter[1]);
}

/**
 * Pop student from all Berkeley lists
 * @param stud - pointer to student
 */
void pop_berkeley_all(std_t stud)
{
    for (int i = 0; i < MAX_SORT_INDEX; i++)
        list_del(&(stud->sort[i]));

    for (int i = 0; i< MAX_FILTER_INDEX; i++)
        if (stud->filter[i].next)
            list_del(&(stud->filter[i]));
}

/**
 * Print berkley list of students (for sort lists)
 * @param array_of_lists - array with sort lists
 * @param field - field number of sort list
 */
void print_berkeley_sort(struct list_head **array_of_lists, int field)
{
    std_t item = NULL;

    list_for_each_entry(item, array_of_lists[field], sort[field])
        output_student_console(*item);
}

/**
 * Print berkley list of students (for filter lists)
 * @param array_of_lists - array with filter lists
 * @param field - field number of filter list
 */
void print_berkeley_filter(struct list_head **array_of_lists, int field)
{
    std_t item = NULL;

    list_for_each_entry(item, array_of_lists[field], filter[field])
        output_student_console(*item);
}

/**
 * Empty Berkeley list
 * @param arr_sort - array with heads of sorted lists
 * @param arr_filter - array with heads of filtered lists
 */
void null_berkeley(struct list_head **arr_sort,  struct list_head **arr_filter)
{
    for (int i = 0; i < MAX_SORT_INDEX; i++)
    {
        arr_sort[i]->next = arr_sort[i];
        arr_sort[i]->prev = arr_sort[i];
    }

    for (int i = 0; i < MAX_FILTER_INDEX; i++)
    {
        arr_filter[i]->next = arr_filter[i];
        arr_filter[i]->prev = arr_filter[i];
    }
}
