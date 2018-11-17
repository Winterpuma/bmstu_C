#include <stdio.h>
#include <string.h>

#include "main.h"

int main()
{
    test("123567", '1', 1);
    test("555", 'm', 2);
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


/**
My realisation of strrchr

@param str [in]
@param ch [in] - char to find
@return index of last ch in str or null
*/
char *my_strrchr(const char *str, int ch)
{
    char *last_found = 0;
    while (*str)
    {
        if (*str == ch)
            last_found = (char *)str;

        str++;
    }
    return last_found ? last_found : NULL;
}
