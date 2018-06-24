#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void array()
{
    srand(time(NULL));

    int size, new_size;
    char sep;
    char **m;
    int upper, lower;

    printf("Input size of array and seperator: ");
    scanf("%d %c", &size, &sep);

    m = (char**)malloc(size*sizeof(char*));
    for (int i=0; i<size; i++)
        m[i] = (char*)malloc(size*sizeof(char));

    for (int i=0; i<size; i++)
    {
        for (int j=0; j<size; j++)
        {
            if (rand()%2)
                m[i][j] = 'a' + (rand()%26);
            else
                m[i][j] = 'A' + (rand()%26);
        }
        m[i][rand()%size] = sep;

        for (int j=0; j<size; j++)
        {
            printf("%c", m[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    new_size = size;
    for (int i = 0; i < new_size; i++)
    {
        upper = 0;
        lower = 0;
            for (int j = 0; j < new_size; j++)
            {
                if (m[i][j] == sep)
                    break;
                else
                {
                    if (('a' <= m[i][j]) && (m[i][j] <= 'z'))
                        lower++;
                    else
                        upper++;
                }
            }

            if (lower < upper)
            {
                char *tmp = m[i];
                for(int j = i; j < new_size; j++)
                    m[j] = m[j+1];
                m[new_size] = NULL;
                free(tmp);
                new_size--;
                i--;
            }
    }

    for (int i = 0; i<new_size; i++)
    {
        for (int j = 0; j<size; j++)
        {
            printf("%c", m[i][j]);
        }
        printf("\n");
    }

    for (int i=0; i<size; i++)
        free(m[i]);
    free(m);
}

int main()
{
    array();
    return 0;
}