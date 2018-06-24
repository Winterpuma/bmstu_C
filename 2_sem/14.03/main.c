/*
 * This programm allows to add, edit, find rows in constant-size array.
*/

#include "stdio.h"
#include "string.h"


//This function prints out array.
void print(int pointer, int n, char array[n][5])
{
    printf("\n");
    for (int i = 0; i < (pointer + 1); i++)
    {
        for (int j = 0; j < 4; j++)
            printf("%c ",array[i][j]);
        printf("\n");
    }

}

// This function adds rows to array.
void new_row(int pointer,int n, char array[n][5])
{
    printf("\nInput new row: ");
    scanf("%s", array[pointer]);
}

// This function edits row in array.
void edit_row(int n, char array[n][5])
{
    int row_num;
    printf("\nWhat row # you want to change?(0 to length - 1): ");
    scanf("%d", &row_num);
    printf("\nInput new row: ");
    scanf("%s", array[row_num]);
    print(n, n, array);
}

// This function finds simmular rows.
void find_row(int n, char array[n][5])
{
    int count = 0;
    char string[5];
    printf("What string do you want to find in array?: ");
    scanf("%s", string);
    for (int i = 0; i < n; i++)
            if (strcmp(array[i], string) == 0)
                count += 1;
    printf("This string founded %d times.", count);
}

int main()
{
    int n;
    printf("4 column array.\n");
    printf("How many rows do you want to have?:  ");
    scanf("%d", &n);

    char array[n][5];
    int pointer = 0;

    while (pointer < n)
    {
        new_row(pointer, n, array);
        print(pointer, n, array);
        pointer++;
    }

    edit_row(n, array);
    find_row(n, array);
    return 0;
}
