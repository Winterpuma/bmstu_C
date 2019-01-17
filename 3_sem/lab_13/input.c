#include "input.h"
#include <stdio.h>
#include <string.h>

void input_bool(char *msg, int *num)
{
    printf("%s", msg);
    while (scanf("%d", num) == 0 || !(*num == 0 || *num == 1))
    {
        printf("ERR. Wrong input. Try again: ");
        fflush(stdin);
    }
}

void input_number(char *msg, int *num, int beg, int end)
{
    printf("%s (range [%d; %d]): ", msg, beg, end);
    while (scanf("%d", num) == 0 || !(*num <= end && *num >= beg))
    {
        printf("ERR. Wrong input. Try again: ");
        fflush(stdin);
    }
}

void input_string(char *msg, char *str, int max_len)
{
    char c;
    int ended = 0;
    int wrong = 1;

    fflush(stdin);
    while (wrong)
    {
        printf("%s", msg);
        printf("(Max %d characters)\n", max_len - 1);

        printf("|");
        for (int i = 0; i < max_len - 2; i++)
            printf("-");
        printf("|\n");

        for (int i = 0; i < max_len; i++)
        {
            if (scanf("%c", &c) == 1)
            {
                if (c != '\n')
                    str[i] = c;
                else
                {
                    str[i] = 0;
                    ended = 1;
                    break;
                }
            }
            else
            {
                str[i] = 0;
                ended = 1;
                break;
            }
        }

        fflush(stdin);
        if (!ended)
            printf("ERR: Too much characters. Try again.\n");
        else if (!str[0])
        {
            printf("ERR: Empty input. Try again.\n");
            ended = 0;
        }
        else
            wrong = 0;
    }
}
