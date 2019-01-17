#include <string.h>
#include "test.h"

int main()
{
    puts("Lets test my_snprintf.");

    puts("\nTest with correct data:");
    test_my_snprintf_correct_dec();
    test_my_snprintf_correct_hex();
    test_my_snprintf_correct_str();

    puts("\nTest specifier exceptions:");
    test_my_snprintf_without_args("Test (%%):", "%%", SIZE);

    puts("\nTest messing with args:");
    test_my_snprintf_without_args("Test (no args):", "doesn't matter", SIZE);
    test_my_snprintf_more_args();

    puts("\nTest other:");
    test_my_snprintf_without_args("Test (empty format):", "", SIZE);
    test_my_snprintf_without_args("Test (short string):", "12345666789", 3);

    return 0;
}

void print_check(int returned1, int returned2, char *res1, char *res2)
{
    if (!strcmp(res1, res2) && returned1 == returned2)
        printf("Passed\n");
    else
        printf("Failed %d|%d: %s|%s\n", returned1, returned2, res1, res2);
}

void test_my_snprintf_correct_dec()
{
    char msg[] = "Test (dec numbers):";
    printf("%-30s", msg);

    char format[] = "%d %d %d %hd %hd %hd";

    size_t n = SIZE;
    char *res1 = malloc(SIZE *sizeof(char));
    char *res2 = malloc(SIZE *sizeof(char));

    int returned1 = my_snprintf(res1, n, format, ARGS_CORRECT_DEC);
    int returned2 = snprintf(res2, n, format, ARGS_CORRECT_DEC);

    print_check(returned1, returned2, res1, res2);
    free_results(res1, res2);
}

void test_my_snprintf_correct_hex()
{
    char msg[] = "Test (hex numbers):";
    printf("%-30s", msg);

    char format[] = "%x %hX %hx %x %hx %x %hx";

    size_t n = SIZE;
    char *res1 = malloc(SIZE *sizeof(char));
    char *res2 = malloc(SIZE *sizeof(char));

    int returned1 = my_snprintf(res1, n, format, ARGS_CORRECT_HEX);
    int returned2 = snprintf(res2, n, format, ARGS_CORRECT_HEX);

    print_check(returned1, returned2, res1, res2);
    free_results(res1, res2);
}

void test_my_snprintf_correct_str()
{
    char msg[] = "Test (string arg):";
    printf("%-30s", msg);

    char format[] = "%s %s %s";

    size_t n = SIZE;
    char *res1 = malloc(SIZE *sizeof(char));
    char *res2 = malloc(SIZE *sizeof(char));

    int returned1 = my_snprintf(res1, n, format, ARGS_CORRECT_STR);
    int returned2 = snprintf(res2, n, format, ARGS_CORRECT_STR);

    print_check(returned1, returned2, res1, res2);
    free_results(res1, res2);
}

void test_my_snprintf_more_args()
{
    char msg[] = "Test (more args):";
    printf("%-30s", msg);

    char format[] = "Hello %s, %s";

    size_t n = SIZE;
    char *res1 = malloc(SIZE *sizeof(char));
    char *res2 = malloc(SIZE *sizeof(char));

    int returned1 = my_snprintf(res1, n, format, ARGS_MORE_ARGS);
    int returned2 = snprintf(res2, n, format, ARGS_MORE_ARGS);

    print_check(returned1, returned2, res1, res2);
    free_results(res1, res2);
}


void test_my_snprintf_without_args(char msg[], char format[], size_t n)
{
    printf("%-30s", msg);

    char *res1 = malloc(SIZE *sizeof(char));
    char *res2 = malloc(SIZE *sizeof(char));

    int returned1 = my_snprintf(res1, n, format);
    int returned2 = snprintf(res2, n, format);

    print_check(returned1, returned2, res1, res2);
    free_results(res1, res2);
}

void free_results(char *res1, char *res2)
{
    if (res1)
        free(res1);
    if (res2)
        free(res2);
}