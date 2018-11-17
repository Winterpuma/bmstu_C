#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

#include "tests.h"
#include "process.h"
#include "my_str.h"
#include "test_my_str.h"

int main()
{
    puts("");
    test_str_replace_all();
    puts("");
    test("in1.txt", "out1.txt", "aa", "bbb", 1);
    test("in2.txt", "out2.txt", "0", "o", 2);
    return 0;
}

/**
 * @param f1[in] - file 1
 * @param f2[in] - file 2
 * @return 0 if two files are identical
 */
int compare_files(FILE *f1, FILE *f2)
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


/**
 * Simulates run of main; compares results
 *
 * @param in_name[in] - in file name
 * @param out_name [in] - out file name
 * @param search [in] - pointer to search string
 * @param replace [in] - pointer to replace string
 * @param tc [in] - test case number
 */
void test(const char *in_name, const char *out_name, const char *search, const char *replace, int tc)
{
    FILE *fin = fopen(in_name, "r");
    FILE *ftc = fopen(out_name, "r");
    FILE *fout = fopen("test_out.txt", "w+");

    process(fin, fout, search, replace);
    rewind(fout);

    if (!compare_files(ftc, fout))
        printf("Module test %d passed.\n", tc);
    else
        printf("Module test %d failed.\n", tc);

    fclose(fin);
    fclose(ftc);
    fclose(fout);
}
