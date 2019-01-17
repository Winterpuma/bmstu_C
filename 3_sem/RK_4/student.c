#include <stdio.h>
#include <stdlib.h>
#include "student.h"
#include"list.h"

student *create_stud(char *name, int age, node *grades)
{
    student *stud = malloc(sizeof(struct student));

    if (stud)
    {
        stud->name = name;
        stud->age = age;
        stud->grades = grades;
    }
    return stud;
}

student *input_stud()
{
    student *stud;
    char *name = malloc(MAX_LEN);
    int age;
    node *grades = NULL;
    int cur_grade;
    int *tmp_grade;

    fflush(stdin);
    printf("Name:");
    fgets(name, MAX_LEN, stdin);
    printf("Age:");
    scanf("%d", &age);
    printf("Grades(1 2 3 s):");

    while (scanf("%d ", &cur_grade) == 1)
    {
        tmp_grade = malloc(sizeof(int));
        if (tmp_grade)
            *tmp_grade = cur_grade;

        push(&grades, (void *) tmp_grade, 0);
    }

    stud = create_stud(name, age, grades);
    return stud;
}


void print_stud(student* stud)
{
    printf("Name: %s", stud->name);
    printf("Age: %d\n", stud->age);
    printf("Grades: ");
    print(stud->grades, 0);
    printf("\n\n");
}

void free_stud(student *stud)
{
    if (stud)
    {
        if (stud->name)
            free(stud->name);
        free_list(stud->grades, 0);
        free(stud);
    }
}
