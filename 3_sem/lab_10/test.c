#include "test.h"
#include "list.h"
#include "process.h"

/*
TEST CASES

1) in/out from file

2) sort 0 elements
3) sort 1 element
4) sort sorted
5) sort reversed

6) remove last element (len 1)
7) remove last element (len 3)

8) reverse list
 */

int main()
{
    puts("");
    test("TC/in1.txt", "TC/out1.txt", 0, 1);
    test("TC/in2.txt", "TC/out2.txt", c_sort, 2);
    test("TC/in3.txt", "TC/out3.txt", c_sort, 3);
    test("TC/in4.txt", "TC/out4.txt", c_sort, 4);
    test("TC/in5.txt", "TC/out5.txt", c_sort, 5);
    test("TC/in6.txt", "TC/out6.txt", c_remove_last, 6);
    test("TC/in7.txt", "TC/out7.txt", c_remove_last, 7);
    test("TC/in8.txt", "TC/out8.txt", c_reverse, 8);
}

/**
 * Simulate run of program with operation given
 * @param in_name - file in name
 * @param out_name - file out (correct) name
 * @param operation - operation to do
 * @param TC - test case number
 */
void test(char in_name[], char out_name[], int operation, int TC)
{
    char result_name[] = "TC/out0.txt";
    FILE *f_in = fopen(in_name, "r");
    node_t *head = read_from_file(f_in);
    fclose(f_in);

    //simulate run of program
    if (operation)
        process(&head, operation);

    FILE *ftc = fopen(out_name, "r"); // correct ftc
    FILE *fres = fopen(result_name, "w"); // result of work

    write_to_file(fres, head);
    fclose(fres);
    fres = fopen(result_name, "r");

    if (!compare_files(ftc, fres))
        printf("Test %d passed.\n", TC);
    else
        printf("Test %d failed.\n", TC);

    free_list_all(&head);
    fclose(fres);
    fclose(ftc);
}

/**
 * Function to compare two files
 * @param f1 - file 1
 * @param f2 - file 2
 * @return 0 if two files are identical
 */
int compare_files(FILE *f1, FILE *f2)
{
    int flag = 0;

    int a, b;

    if ((f1 == NULL && f2 != NULL) || (f1 != NULL && f2 == NULL))
        flag = 1;
    else if (f1 == NULL && f2 == NULL)
        flag = 0;
    else
        while (1)
        {
            fscanf(f1, "%d\n", &a);
            fscanf(f2, "%d\n", &b);

            if (feof(f1) && feof(f2))
                break;
            else if (feof(f1) || feof(f2) || a != b)
            {
                flag = 1;
                break;
            }
        }
    return flag;
}