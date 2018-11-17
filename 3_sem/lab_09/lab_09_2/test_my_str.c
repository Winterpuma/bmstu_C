#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

#include "my_str.h"
#include "test_my_str.h"

/**
 * Test string replacement function
 *
 * @param str [in] - pointer to original string
 * @param search [in] - pointer to search string
 * @param replace [in] - pointer to replace string
 * @param true_res [in] - expected result
 * @param tc [in] - test case number
 */
void test_str_replace(const char *str, const char *search, const char *replace, const char *true_res, int tc)
{
    char *my_res = NULL;

    my_res = str_replace(str, search, replace);
    if (!strcmp(my_res, true_res))
        printf("Test_str_replace %d passed\n", tc);
    else
        printf("Test_str_replace %d failed\n", tc);
}

/**
 * Do testing of str_replace all at once.
 */
void test_str_replace_all()
{
    test_str_replace("Test string", "str", "shower", "Test showering", 1);
    test_str_replace("BMSTU IU75", "5", "", "BMSTU IU7", 2);
    test_str_replace("Not Here", "gg", "oops", "Not Here", 3);
    test_str_replace("Something wrong", "", "replace", "", 4);
}
