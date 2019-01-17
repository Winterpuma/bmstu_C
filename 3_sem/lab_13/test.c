#include <stdio.h>
#include "test.h"
#include "list.h"
#include "my_list.h"
#include "structures.h"

/**
 * Test Berkeley sort
 * @return 0 if OK
 */
int test_sort()
{
    int err = 0;

    LIST_HEAD(sort_age);
    LIST_HEAD(sort_grade);
    LIST_HEAD(sort_year);
    struct list_head *arr_sort[MAX_SORT_INDEX] = {&sort_age, &sort_grade, &sort_year};

    LIST_HEAD(sort_age1);
    LIST_HEAD(sort_grade1);
    LIST_HEAD(sort_year1);
    struct list_head *arr_sort1[MAX_SORT_INDEX] = {&sort_age, &sort_grade, &sort_year};

    LIST_HEAD(filter_sex);
    LIST_HEAD(filter_age);
    struct list_head *arr_filter[MAX_FILTER_INDEX] = {&filter_sex, &filter_age};

    std_t  head_to_sort = NULL, head_result = NULL;
    input_list_from_file(&head_to_sort, "TC/in1.txt", arr_sort, arr_filter);
    input_list_from_file(&head_result, "TC/out1.txt", arr_sort1, arr_filter);

    struct list_head *iter;
    std_t  cur_to_sort = NULL, cur_result = head_result;
    list_for_each(iter, arr_sort[0])
    {
        cur_to_sort = list_entry(iter, struct Student, sort[0]);
        if (cur_to_sort->age != cur_result->age)
            err = 1;
        if (cur_result->next)
            cur_result = cur_result->next;
    }

    free_standard_list(&head_to_sort);
    free_standard_list(&head_result);
    null_berkeley(arr_sort, arr_filter);

    return err;
}

/**
 * Test Berkeley filter
 * @return 0 if OK
 */
int test_filter()
{
    int err = 0;

    LIST_HEAD(sort_age);
    LIST_HEAD(sort_grade);
    LIST_HEAD(sort_year);
    struct list_head *arr_sort[MAX_SORT_INDEX] = {&sort_age, &sort_grade, &sort_year};

    LIST_HEAD(filter_sex);
    LIST_HEAD(filter_age);
    struct list_head *arr_filter[MAX_FILTER_INDEX] = {&filter_sex, &filter_age};

    std_t  head_to_sort = NULL;
    input_list_from_file(&head_to_sort, "TC/in2.txt", arr_sort, arr_filter);

    struct list_head *iter;
    std_t  cur_to_sort = NULL;
    list_for_each(iter, arr_filter[0])
    {
        cur_to_sort = list_entry(iter, struct Student, filter[0]);
        if (cur_to_sort->sex != 0)
            err = 1;
    }

    free_standard_list(&head_to_sort);
    null_berkeley(arr_sort, arr_filter);

    return err;
}

void output_res(char *msg, int res)
{
    printf("%-20s: ", msg);
    if (res)
        puts("Failed");
    else
        puts("Passed");
}

int main()
{
    output_res("Test sort", test_sort());
    output_res("Test filter", test_filter());
}
