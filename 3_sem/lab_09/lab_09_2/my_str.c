#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

#include "my_str.h"

#define BUF_SIZE 10
#define MALLOC_STEP 10

/**
 * Get one line from steam
 * @param lineptr - pointer to pointer to line
 * @param n - pointer to size of line
 * @param stream[in] - file
 * @return size of readed line
 */
ssize_t my_getline(char **lineptr, size_t *n, FILE *stream)
{
    if (!stream)
        return -1;

    int flag = 1;
    char buf[BUF_SIZE];
    size_t buf_size = 0;

    *lineptr = NULL;
    *n = 0;

    while(flag && fgets(buf, BUF_SIZE, stream))
    {
        buf_size = strlen(buf);

        *lineptr = (char *)realloc(*lineptr, *n + buf_size + 1);
        if (!(*lineptr))
        {
            flag = 0;
            *n = 0;
        }
        else
        {
            memcpy(*lineptr + *n, buf, buf_size);
            *n += buf_size;

            (*lineptr)[(*n)] = 0;

            if ((*lineptr)[(*n)-1] == '\n')
                flag = 0;
        }
    }

    return *n;
}

/**
 * Add char to my_str from str or replace.
 * @param str [in] - pointer to original string
 * @param search [in] - pointer to search string
 * @param replace [in] - pointer to replace string
 * @param my_str [in/out] - pointer to pointer to my string to write chars in
 * @param max_size[in/out] - max size of line
 * @param curr_size[in/out] - current size of line
 * @param i[in/out] - pointer to current position
 * @return 0 if everything is ok
 */
int add_char(const char *str, const char *search, const char *replace, char **my_str, int *max_size, int *curr_size, int *i)
{

    int search_size = strlen(search);
    int replace_size = strlen(replace);

    int flag_same = 1;
    int flag_error = 0;

    for (int j = 0; j < search_size && flag_same; j++)
    {
        if (*(str+*i+j) != *(search+j))
            flag_same = 0;
    }

    if (flag_same)
    {
        if (*max_size - *curr_size < replace_size + 1)
        {
            realloc_str(my_str, max_size, replace_size, 1);
            if (!(*my_str))
                flag_error = -1;
        }
        if (!flag_error)
        {
            memcpy(*my_str + *curr_size, replace, replace_size+1);
            *curr_size += replace_size;
            *i += search_size - 1;
        }
    }
    else
    {
        if (*max_size - *curr_size < 2)
        {
            realloc_str(my_str, max_size, MALLOC_STEP, 0);
            if (!(*my_str))
                flag_error = -1;
        }
        if (!flag_error)
        {
            (*my_str)[*curr_size] = str[*i];
            (*my_str)[*curr_size+1] = 0;
            (*curr_size)++;
        }
    }
    return flag_error;
}

/**
 * Realloc string. Allocation check should be on calling side.
 * @param str - pointer to pointer to str
 * @param max_size pointer to max_size of str
 * @param size - how mush memory to add
 * @param flag - extra bit for '\0'
 */
void realloc_str(char **str, int *max_size, int size, int flag)
{
    *str = (char *)realloc(*str, *max_size + size + flag);
    *max_size += size;
}

/**
 * @brief str_replace
 * @param str [in] - pointer to original string
 * @param search [in] - pointer to search string
 * @param replace [in] - pointer to replace string
 * @return pointer to new string
 */
char *str_replace(const char *str, const char *search, const char *replace)
{
    size_t str_size = strlen(str);
    char *new_str = NULL;

    if (!strlen(search))
    {
        new_str = calloc(1, sizeof(char));
        return new_str;
    }

    new_str = malloc(MALLOC_STEP);
    int max_size = MALLOC_STEP;
    int curr_size = 0;

    for (int i = 0; i < str_size; i++)
    {
        add_char(str, search, replace, &new_str, &max_size, &curr_size, &i);
    }

    return new_str;
}
