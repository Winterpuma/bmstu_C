/*
 * RK#3 C
 * Obergan Tanya
 * task 2.3
*/

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <limits.h>
#include <math.h>

#define SIZE 101
#define BUF_SIZE 20
#define STEP 20

void write_el_to_matr(char **ptr_b, int *matr, int i);
int num_correct(const char *str);
int char_is_num(char c);
int count_n(const char *str);
int word_len(const char *str);
int str_to_int(char *str, int len);
void skip_space(char **ptr_b, const char *ptr_e);
int my_getline(FILE *f, char *str);
void print_matrix(int *matr, int n, int m);

int main()
{
    char *line = malloc(SIZE);
    char *ptr, *ptr_e;
    int line_size = 0;

    //int matr[STEP] = {};
    int *matr = malloc(STEP * sizeof(int));
    int matr_max_size = STEP;

    int n = 0, m = 0;
    int index = 0;

    FILE *f = fopen("data.txt", "r");

    if (!f)
        return -1;

    while (line_size = my_getline(f, line))
    {

        printf("line: %s", line);

        ptr = line;
        ptr_e = ptr + line_size;

        if (!n)
            n = count_n(line);

        for (int i = 0; i < n; i++)
        {
            if (index == matr_max_size)
            {
                matr_max_size += STEP;
                matr = realloc(matr, sizeof(int) * matr_max_size);
            }
            write_el_to_matr(&ptr, matr, index);
            skip_space(&ptr, ptr_e);
            index++;
        }
        m++;
    }

    free(line);

    printf("\n\nResult matrix:\n");
    print_matrix(matr, m, n);
    free(matr);

    return 0;
}

void skip_space(char **ptr_b, const char *ptr_e)
{
    while (**ptr_b == ' ' && *ptr_b != ptr_e)
        (*ptr_b)++;
}

void write_el_to_matr(char **ptr_b, int *matr, int i)
{
    int num_len = 0;
    num_len = num_correct(*ptr_b);
    if (num_len != -1)
    {
        matr[i] = str_to_int(*ptr_b, num_len);
        *ptr_b += num_len;
    }
    else
    {
        *ptr_b += word_len(*ptr_b);
        matr[i] = INT_MAX;
    }
}

int str_to_int(char *str, int len)
{
    int number = 0;

    for (int i = len - 1; i >= 0; i--)
    {
        number += (*str - '0') * pow(10, i);
        str++;
    }

    return number;
}

/**
 * @param str
 * @return len of number or -1 if not a number
 */
int num_correct(const char *str)
{
    int i = 0;

    while (*(str+i) && *(str+i) != ' ' && *(str+i) != '\n' && i != -1)
    {
        if (!char_is_num(*(str+i)))
            i = -2;
        i++;
    }
    return i;
}

int char_is_num(char c)
{
    return !(c > '9' || c < '0');
}

int word_len(const char *str)
{
    int i = 0;
    while (*(str+i) && *(str+i) != ' ')
        i++;

    return i+1;
}

int count_n(const char *str)
{
    int n = 0;
    int i = 0;

    while(*(str+i))
    {
        if (*(str+i) == ' ')
        {
            // NOTE
            n++;
        }
        i++;
    }
    return n+1;
}

int my_getline(FILE *f, char *str)
{
    char buf[BUF_SIZE];
    int size = 0;

    int n = 0;

    while (fgets(buf, BUF_SIZE, f))
    {
        size = strlen(buf);
        memcpy(str + n, buf, size);

        n += size;
        str[n] = 0;

        if (str[(n)-1] == '\n')
            break;
    }

    return n;
}

void print_matrix(int *matr, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            printf("%d ", matr[i*m + j]);
        printf("\n");
    }
}
