#include <stdlib.h>
#include <stdio.h>

#include "input.h"
#include "list.h"
#include "my_list.h"
#include "structures.h"

#define LEN_FILE_NAME 25
int print_menu();

int main()
{
    int operation;
    char file_name[LEN_FILE_NAME];

    std_t head = NULL;
    std_t tmp_stud = NULL;
    int tmp_n = 0;

    LIST_HEAD(sort_age);
    LIST_HEAD(sort_grade);
    LIST_HEAD(sort_year);
    struct list_head *arr_sort[MAX_SORT_INDEX] = {&sort_age, &sort_grade, &sort_year};

    LIST_HEAD(filter_sex);
    LIST_HEAD(filter_age);
    struct list_head *arr_filter[MAX_FILTER_INDEX] = {&filter_sex, &filter_age};

    do
    {
        print_menu();
        fflush(stdin);
        if ((scanf("%d", &operation) == 1) && operation)
            switch (operation)
            {
                case 1:
                    free_standard_list(&head);
                    null_berkeley(arr_sort, arr_filter);
                    input_string("Input file name: ", file_name, LEN_FILE_NAME);
                    if (input_list_from_file(&head, file_name, arr_sort, arr_filter) == -1)
                        puts("File error!");
                    break;
                case 2:
                    input_string("Input file name: ", file_name, LEN_FILE_NAME);
                    if (output_list_to_file(head, file_name))
                        puts("File error!");
                    break;
                case 3:
                    tmp_stud = input_student();
                    push_standard_list(&head, tmp_stud);
                    push_berkeley_all(tmp_stud, arr_sort, arr_filter);
                    break;
                case 4:
                    if (head)
                    {
                        input_number("Input index of student", &tmp_n, 0, list_size(head)-1);
                        tmp_stud = list_i(head, tmp_n);
                        pop_berkeley_all(tmp_stud);
                        edit_student(tmp_stud);
                        push_berkeley_all(tmp_stud, arr_sort, arr_filter);
                    }
                    else
                        puts("List is empty!");
                    break;
                case 5:
                    if (head)
                    {
                        input_number("Input index of student", &tmp_n, 0, list_size(head)-1);
                        tmp_stud = list_i(head, tmp_n);
                        if(tmp_stud)
                        {
                            pop_berkeley_all(tmp_stud);
                            pop_standard_list(&head, tmp_n);
                        }
                    }
                    else
                        puts("List is empty!");
                    break;
                case 6:
                    print_berkeley_sort(arr_sort, 0);
                    break;
                case 7:
                    print_berkeley_sort(arr_sort, 1);
                    break;
                case 8:
                    print_berkeley_sort(arr_sort, 2);
                    break;
                case 9:
                    print_berkeley_filter(arr_filter, 0);
                    break;
                case 10:
                    print_berkeley_filter(arr_filter, 1);
                    break;
                case 11:
                    print_standard_list(head);
                    break;
                default:
                    puts("Wrong input. Try again.");
                    break;
            }
    }
    while (operation);

    free_standard_list(&head);
    null_berkeley(arr_sort, arr_filter);

    return 0;
}

int print_menu()
{
    printf("\nMENU (choose operation):\n\t"
           "0 - Exit\n\t"
           "1 - Load from file\n\t"
           "2 - Save to file\n\n\t"
           "3 - Add record\n\t"
           "4 - Edit record by index\n\t"
           "5 - Remove record by index\n\n\t"
           "6 - Sort by age\n\t"
           "7 - Sort by average_grade\n\t"
           "8 - Sort by admission year\n\n\t"
           "9 - Filter - female\n\t"
           "10 - Filter - Age is less than 21\n\n\t"
           "11 - Print list\n");
    fflush(stdin);
}
