#include <stdio.h>
#include <string.h>

#include "main.h"
#include "mystring.h"

int main()
{
    test("123567", '1', 1);
    test("555", '\0', 2);
    test("1212121", '1', 3);
    test("", '5', 4);
    return 0;
}

void test(char str[], int ch, int tc)
{

    char *org_res = strrchr(str, ch);
    char *my_res = my_strrchr(str, ch);

    if (org_res == my_res)
        printf("Test %d passed\n", tc);
    else
        printf("Test %d failed\n", tc);
}
