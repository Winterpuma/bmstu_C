#ifndef LAB_13_MY_LIST_H
#define LAB_13_MY_LIST_H

#include "structures.h"

#define FILTER_GENDER 0
#define FILTER_AGE 21

void push_standard_list(struct Student **list, struct Student *element);
int pop_standard_list(std_t *list, int index);
void print_standard_list(std_t stud);
void free_standard_list(std_t *list);
std_t list_i(std_t list, int i);
int list_size(std_t list);

void push_berkeley_sorted(std_t stud, struct list_head *head, int field, int (*cmp)(std_t, std_t));
void push_berkeley_all(std_t stud, struct list_head **sort, struct list_head **filter);
void pop_berkeley_all(std_t stud);

void print_berkeley_sort(struct list_head **array_of_lists, int field);
void print_berkeley_filter(struct list_head **array_of_lists, int field);
void null_berkeley(struct list_head **arr_sort,  struct list_head **arr_filter);

#endif //LAB_13_MY_LIST_H
