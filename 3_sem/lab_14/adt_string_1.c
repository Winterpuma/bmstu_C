#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "adt_string_all.h"

struct string_type
{
    char *data;
    size_t len;
};

/**
 * Create new string
 * @param str array of char
 * @return new string
 */
string_t str_create(char *str)
{
    size_t len;
    string_t s = malloc(sizeof(struct string_type));
    if (s)
    {
        len = strlen(str);
        s->data = malloc((len + 1) * sizeof(char));

        if (s->data)
        {
            strcpy(s->data, str);
            s->len = len;
        }
        else
        {
            free(s);
            s = NULL;
        }
    }
    return s;
}

/**
 * Free memory of string
 * @param s string
 */
void str_destroy(string_t s)
{
    free(s->data);
    free(s);
}

/**
 * Concatenate two strings
 * @param s1 string 1
 * @param s2 string 2
 * @return new string
 */
string_t str_concatenate(string_t s1, string_t s2)
{
    string_t res;
    char *new_str;

    if (!s1 && !s2)
        res = NULL;
    else if (!s1)
        res = str_create(s2->data);
    else if (!s2)
        res = str_create(s1->data);
    else
    {
        new_str = malloc((s1->len + s2->len + 1) * sizeof(char));
        strcpy(new_str, s1->data);
        strcpy((new_str + s1->len), s2->data);
        res = str_create(new_str);
        free(new_str);
    }
    return res;
}
/**
 * Compares two strings
 * @param s1 first string
 * @param s2 second string
 * @return 1 - if equal, 0 - else
 */
int str_compare(string_t s1, string_t s2)
{
    int res = 1;

    if ((!s1 && s2) || (!s2 && s1))
        res = 0;
    else if (s1 && s2)
    {
        if (s1->len == s2->len)
        {
            for (int i = 0; i < s1->len && res; i++) {
                if (s1->data[i] != s2->data[i])
                    res = 0;
            }
        }
        else
            res = 0;
    }

    return res;
}

/**
 * Replace char find with replace_with char in s
 * @param s string
 * @param find char to replace
 * @param replace_with new char
 */
void str_replace_char(string_t s, char find, char replace_with)
{
    if (!s)
        return;

    char *str = s->data;

    for (int i = 0; i < s->len; i++)
    {
        if (str[i] == find)
            str[i] = replace_with;
    }
}

/**
 * Replace char of string with given index by another char
 * @param s - string
 * @param index - index to replace
 * @param replace_with - new char
 */
void str_edit_by_index(string_t s, int index, char replace_with)
{
    if (!s || (s->len <= index))
        return;

    (s->data)[index] = replace_with;
}

/**
 * Print string
 * @param s string
 */
void str_print(string_t s)
{
    if (!s)
    {
        puts("String doesn't exist.");
        return;
    }

    char *str = s->data;
    if (!s->len)
        puts("String is empty.");


    for (int i = 0; i < s->len; i++)
    {
        switch (str[i])
        {
            case '\0':
                printf("\\0");
                break;
            case '\n':
                printf("\\n");
                break;
            case '\t':
                printf("\\t");
                break;
            default:
                printf("%c", str[i]);
                break;
        }
    }
}

/**
 * Return len of string
 * @param s string
 * @return size
 */
size_t str_len(string_t s)
{
    if (s)
        return s->len;
    else
        return 0;
}
