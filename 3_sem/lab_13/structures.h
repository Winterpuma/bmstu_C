#ifndef LAB_13_STRUCTURES_H
#define LAB_13_STRUCTURES_H

#include <stdio.h>
#include "list.h"

#define LEN_NAME 20
#define MAX_SORT_INDEX 3
#define MAX_FILTER_INDEX 2

typedef struct Student* std_t;

struct Student
{
    char name[LEN_NAME];
    int sex; // 0-female 1-male
    int age;
    int average_grade;
    int admission_year;

    struct list_head sort[MAX_SORT_INDEX];
    struct list_head filter[MAX_FILTER_INDEX];

    struct Student *next;
};

std_t input_student();
std_t input_student_file(FILE *f);
void edit_student(std_t stud);
void output_student_console(struct Student stud);
void output_student_file(FILE *f, struct Student stud);

int compare_age(struct Student *a, struct Student *b);
int compare_grage(struct Student *a, struct Student *b);
int compare_year(struct Student *a, struct Student *b);

int input_list_from_file(std_t *head, char file_name[], struct list_head **arr_sort, struct list_head **arr_filter);
int output_list_to_file(std_t head, char file_name[]);

#endif //LAB_13_STRUCTURES_H
