#ifndef STUDENT_H
#define STUDENT_H

#include "list.h"

#define MAX_LEN 50

typedef struct student
{
    char *name;
    int age;
    struct node *grades;
} student;

student *create_stud(char *name, int age, node *grades);
student *input_stud();
void print_stud(student* stud);
void free_stud(student *stud);

#endif
