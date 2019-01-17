#include <stdio.h>
#include <stdlib.h>
#include "structures.h"
#include "input.h"
#include "my_list.h"

/**
 * Input student by hand
 * @param stud already allocated student
 * @return
 */
std_t input_student()
{
    std_t stud = calloc(1, sizeof(struct Student));

    if (stud)
    {
        input_string("Input Name:", stud->name, LEN_NAME);
        input_bool("Input sex (0-female, 1-male): ", &(stud->sex));
        input_number("Input age", &(stud->age), 10, 70);
        input_number("Input average grade", &(stud->average_grade), 0, 100);
        input_number("Input admission_year", &(stud->admission_year), 1500, 2019);
    }
    return stud;
}

/**
 * Input student from file
 * @param f file
 * @return pointer to new student
 */
std_t input_student_file(FILE *f)
{
    std_t stud = calloc(1, sizeof(struct Student));
    int flag = 0;

    if (stud)
    {
        if (fscanf(f, "%[^\n]\n", stud->name) != 1) flag = -1;
        if (fscanf(f, "%d", &stud->sex) != 1) flag = -1;
        if (fscanf(f, "%d", &stud->age) != 1) flag = -1;
        if (fscanf(f, "%d", &stud->average_grade) != 1) flag = -1;
        if (fscanf(f, "%d", &stud->admission_year) != 1) flag = -1;

        if (flag == -1)
        {
            free(stud);
            stud = NULL;
        }
    }
    return stud;
}

/**
 * Edit params of student
 * @param stud - pointer to student
 */
void edit_student(std_t stud)
{
    printf("Going to change:");
    output_student_console(*stud);

    input_number("Input new age", &(stud->age), 10, 70);
    input_number("Input new average grade", &(stud->average_grade), 0, 100);
    input_number("Input new admission_year", &(stud->admission_year), 1500, 2019);

}

/**
 * Output student to console
 * @param stud student
 */
void output_student_console(struct Student stud)
{
    printf("\nStudent: %s\n", stud.name);

    printf("Sex: ");
    if (stud.sex)
        printf("male\n");
    else
        printf("female\n");

    printf("Age: %d\n", stud.age);
    printf("Average grade: %d\n", stud.average_grade);
    printf("Admission_year: %d\n", stud.admission_year);
}

/**
 * Output student to file
 * @param f file
 * @param stud student
 */
void output_student_file(FILE *f, struct Student stud)
{
    fprintf(f, "%s\n", stud.name);
    fprintf(f, "%d\n", stud.sex);

    fprintf(f, "%d\n", stud.age);
    fprintf(f, "%d\n", stud.average_grade);
    fprintf(f, "%d\n", stud.admission_year);

    fprintf(f, "\n");
}

int compare_age(struct Student *a, struct Student *b)
{
    return a->age - b->age;
}
int compare_grage(struct Student *a, struct Student *b)
{
    return a->average_grade - b->average_grade;
}
int compare_year(struct Student *a, struct Student *b)
{
    return a->admission_year - b->admission_year;
}

/**
 * Input list of students from file
 * @param head - list head
 * @param file_name - name of file with data
 * @param arr_sort - array with heads of sorted lists
 * @param arr_filter - array with heads of filtered lists
 * @return -1 if file error, 0 - Ok
 */
int input_list_from_file(std_t *head, char file_name[], struct list_head **arr_sort, struct list_head **arr_filter)
{
    FILE *f = fopen(file_name, "r");
    std_t tmp_stud;

    if (!f)
        return -1;

    tmp_stud = input_student_file(f);
    while (tmp_stud)
    {
        push_standard_list(head, tmp_stud);
        push_berkeley_all(tmp_stud, arr_sort, arr_filter);
        fscanf(f, "\n");
        tmp_stud = input_student_file(f);
    }

    fclose(f);
    return 0;
}

/**
 * Output list of students to file
 * @param head - list head
 * @param file_name - name of file to output data
 * @return -1 - file error, 0 - Ok
 */
int output_list_to_file(std_t head, char file_name[])
{
    FILE *f = fopen(file_name, "w");

    if (!f)
        return -1;

    for ( ; head; head = head->next)
        output_student_file(f, *head);

    fclose(f);
    return 0;
}
