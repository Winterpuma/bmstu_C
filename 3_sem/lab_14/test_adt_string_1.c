#include <stdio.h>

#include "test_adt_string_1.h"
#include "adt_string_all.h"

int main()
{
    test_str_compare("Test str_compare same:", "Happy", "Happy", 1);
    test_str_compare("Test str_compare different:", "new", "year!", 0);
    test_str_compare("Test str_compare different(same size):", "be", "ok", 0);
    puts("");
    test_str_concatenate_2strings("year", "++", "year++");
    test_str_concatenate_first();
    test_str_concatenate_second();
    puts("");
    test_str_replace_char("2018", '8', '9', "2019");
    test_str_edit_by_index("12", 0, '2', "22");
    puts("");
    show_feature("Have a great holidays!", 'a', '\0');
}

void verdict(string_t my, string_t correct)
{
    if (str_compare(my, correct))
        puts("Passed");
    else
    {
        printf("Failed (got:");
        str_print(my);
        printf("expected:");
        str_print(correct);
        printf(")");
    }
}

void test_str_compare(char msg[], char s1[], char s2[], int res)
{
    printf("%-50s", msg);

    string_t str1 = str_create(s1);
    string_t str2 = str_create(s2);

    if (str_compare(str1, str2) == res)
        puts("Passed");
    else
        puts("Failed");

    str_destroy(str1);
    str_destroy(str2);
}

void test_str_concatenate_2strings(char s1[], char s2[], char res[])
{
    char msg[] = "Test str_concatenate with 2 strings:";
    printf("%-50s", msg);

    string_t str1 = str_create(s1);
    string_t str2 = str_create(s2);
    string_t str_res = str_concatenate(str1, str2);
    string_t correct_res = str_create(res);

    verdict(str_res, correct_res);

    str_destroy(str1);
    str_destroy(str2);
    str_destroy(str_res);
    str_destroy(correct_res);
}

void test_str_concatenate_first()
{
    char msg[] = "Test str_concatenate(second str - NULL):";
    printf("%-50s", msg);

    string_t str1 = str_create("Heh.:)");
    string_t str_res = str_concatenate(str1, NULL);

    verdict(str_res, str1);

    str_destroy(str1);
    str_destroy(str_res);
}

void test_str_concatenate_second()
{
    char msg[] = "Test str_concatenate(first str - NULL):";
    printf("%-50s", msg);

    string_t str1 = str_create("Heh.:)");
    string_t str_res = str_concatenate(NULL, str1);

    verdict(str_res, str1);

    str_destroy(str1);
    str_destroy(str_res);
}

void test_str_replace_char(char s1[], char find, char replace_with, char res[])
{
    char msg[] = "Test str_replace_char:";
    printf("%-50s", msg);

    string_t str1 = str_create(s1);
    str_replace_char(str1, find, replace_with);
    string_t correct_res = str_create(res);

    verdict(str1, correct_res);

    str_destroy(str1);
    str_destroy(correct_res);
}

void test_str_edit_by_index(char s1[], int index, char replace_with, char res[])
{
    char msg[] = "Test str_edit_by_index:";
    printf("%-50s", msg);

    string_t str1 = str_create(s1);
    str_edit_by_index(str1, index, replace_with);
    string_t correct_res = str_create(res);

    verdict(str1, correct_res);

    str_destroy(str1);
    str_destroy(correct_res);
}

void show_feature(char s1[], char find, char replace_with)
{
    char msg[] = "Show feature of str_replace_char:\n";
    printf("%s", msg);

    string_t str1 = str_create(s1);
    printf("String before: ");
    str_print(str1);

    str_replace_char(str1, find, replace_with);
    printf("\nString after: ");
    str_print(str1);

    str_destroy(str1);
}
