#include <stdio.h>
#include <string.h>

#include "test.h"
#include "operations.h"
#include "process.h"

int main()
{
    char *test1_argv[] = {"test.exe", "a", "TC/in1_1.txt", "TC/in1_2.txt", "TC/out0.txt"};
    test(5, test1_argv, '1', 1);

    char *test2_argv[] = {"test.exe", "m", "TC/in2_1.txt", "TC/in2_2.txt", "TC/out0.txt"};
    test(5, test2_argv, '2', 1);

    char *test3_argv[] = {"test.exe", "o", "TC/in3.txt", "TC/out0.txt"};
    test(4, test3_argv, '3', 1);

    test_args(2, test1_argv, '4', -1);
    test_args(3, test3_argv, '5', -1);

    char *test6_argv[] = {"test.exe", "m", "TC/in6_1.txt", "TC/in6_2.txt", "TC/out0.txt"};
    test(5, test6_argv, '6', 0);

    char *test7_argv[] = {"test.exe", "a", "TC/in7_1.txt", "TC/in7_2.txt", "TC/out0.txt"};
    test(5, test7_argv, '7', 0);

    char *test8_argv[] = {"test.exe", "o", "TC/in8.txt", "TC/out0.txt"};
    test(4, test8_argv, '8', 0);

    return 0;
}

/* Simulates run of main with args and compares results
 * TC - TC number, compare_type - comparison of results type flag */
void test(int argc, char *argv[], char TC, int compare_type)
{
    FILE *ftc; // correct ftc
    FILE *fres; // result of calculations

    //simulate run of program
    int flag = check_args(argc, argv);

    if (flag > 0)
        process(argv, flag);

    char out_name[12] = "TC/out0.txt";
    fres = fopen(out_name, "r");
    out_name[6] = TC;
    ftc = fopen(out_name, "r");

    if ((compare_type) ? (!compare_files(ftc, fres, flag)) : (!compare_err(ftc, fres)))
        printf("\nTest %c passed.\n\n", TC);
    else
        printf("\nTest %c failed.\n\n", TC);

    fclose(fres);
    fclose(ftc);
}

/* Check check_args function
 * TC - TC number, flag - expected result*/
void test_args(int argc, char *argv[], char TC, int flag)
{

    int flag_res = check_args(argc, argv);

    if (flag_res == flag)
        printf("\nTest %c passed.\n\n", TC);
    else
        printf("\nTest %c failed.\n\n", TC);

}

/* returns 0 if two files are identical
 * f1, f2 - files, fl_det - compare determinator files */
int compare_files(FILE *f1, FILE *f2, int fl_det)
{
    int flag = 0;

    int i1, j1, i2, j2, nz1, nz2;
    float c1, c2;

    if ((f1 == NULL && f2 != NULL) || (f1 != NULL && f2 == NULL))
    {
        flag = 1;
    }
    else if (f1 == NULL && f2 == NULL)
    {
        flag = 0;
    }
    else
    {
        if (fl_det == det)
        {
            fscanf(f1, "%f", &c1);
            fscanf(f2, "%f", &c2);
            return compare_float(c1, c2);
        }
        fscanf(f1, "%d %d %d", &i1, &j1, &nz1);
        fscanf(f2, "%d %d %d", &i2, &j2, &nz2);

        if (i1 != i2 || j1 != j2 || nz1 != nz2)
        {
            puts("3");
            printf("%d %d %d %d %d %d", i1, i2, j1, j2, nz1, nz2);
            return 1;
        }
        while (fscanf(f1, "%d %d %f", &i1, &j1, &c1) == 3 && fscanf(f2, "%d %d %f", &i2, &j2, &c2) == 3)
        {
            if (i1 != i2 || j1 != j2 || compare_float(c1, c2))
            {
                printf("%d %d %d %d %f %f", i1, i2, j1, j2, c1, c2);
                flag = 1;
                break;
            }
        }
    }
    return flag;
}

/* returns 0 if two files are identical
 * f1, f2 - files to compare */
int compare_err(FILE *f1, FILE *f2)
{
    int flag = 0;

    char  ch1;
    char ch2;

    if ((f1 == NULL && f2 != NULL) || (f1 != NULL && f2 == NULL))
        flag = 1;
    else if (f1 == NULL && f2 == NULL)
        flag = 0;
    else
        while (1)
        {
            ch1 = getc(f1);
            ch2 = getc(f2);

            if (feof(f1) && feof(f2))
                break;
            else if (feof(f1) || feof(f2) || ch1 != ch2)
            {
                flag = 1;
                break;
            }
        }
    return flag;
}
