#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

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

    char buf[BUF_SIZE];
    size_t buf_size = 0;

    *lineptr = NULL;
    *n = 0;

    while(fgets(buf, BUF_SIZE, stream))
    {
        buf_size = strlen(buf);

        *lineptr = (char *)realloc(*lineptr, *n + buf_size + 1);

        memcpy(*lineptr + *n, buf, buf_size);
        *n += buf_size;

        (*lineptr)[(*n)] = 0;

        if ((*lineptr)[(*n)-1] == '\n')
            break;
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


    for (int j = 0; j < search_size && flag_same; j++)
    {
        if (*(str+*i+j) != *(search+j))
            flag_same = 0;
    }

    if (flag_same)
    {
        if (*max_size - *curr_size < replace_size + 1)
        {
            *my_str = (char *)realloc(*my_str, *max_size + replace_size + 1);
            *max_size += replace_size;
            if (!my_str)
                return -1;
        }
        memcpy(*my_str + *curr_size, replace, replace_size+1);
        *curr_size += replace_size;
        *i += search_size - 1;
    }
    else
    {
        if (*max_size - *curr_size < 2)
        {
            *my_str = (char *)realloc(*my_str, *max_size + MALLOC_STEP);
            *max_size += MALLOC_STEP;
            if (!my_str)
                return -1;
        }
        (*my_str)[*curr_size] = str[*i];
        (*my_str)[*curr_size+1] = 0;
        (*curr_size)++;
    }

    return 0;
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
