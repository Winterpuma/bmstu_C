#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "input.h"
#include "memory.h"
#include "operations.h"
#include "output.h"
#include "process.h"

void process(char *argv[], int key)
{
    if (key == add)
        block_add(argv);
    else if (key == multiply)
        block_multiply(argv);
    else if (key == det)
        block_det(argv);
    else if (key == help)
        get_help();
}

void block_add(char *argv[])
{
    FILE *in1, *in2, *out;
    float **matr1, **matr2;
    int n1, m1, n2, m2;

    out = fopen(argv[4], "w");
    in1 = fopen(argv[2], "r");
    in2 = fopen(argv[3], "r");

    if (!in1 || !in2)
    {
        printf("File doesn't exist.");
        fprintf(out, "File doesn't exist.");
    }
    else
    {
        matr1 = input(in1, &n1, &m1);
        matr2 = input(in2, &n2, &m2);

        if (!matr1 || !matr2)
        {
            printf("Allocation error");
            fprintf(out, "Allocation error");
        }
        else if (n1 == n2 && m1 == m2)
        {
            matr1 = addition(matr1, matr2, n1, m2);
            print_mat(matr1, n1, m1);
            output(out, matr1, n1, m1);
        }
        else
        {
            printf("Addition error: wrong size of matrix");
            fprintf(out, "Addition error: wrong size of matrix");
        }

        free_mat(matr1);
        free_mat(matr2);
    }

    fclose(in1);
    fclose(in2);
    fclose(out);
}

void block_multiply(char *argv[])
{
    FILE *in1, *in2, *out;
    float **matr1 = NULL, **matr2 = NULL, **res = NULL;
    int n1, m1, n2, m2;

    out = fopen(argv[4], "w");
    in1 = fopen(argv[2], "r");
    in2 = fopen(argv[3], "r");

    if (!in1 || !in2)
    {
        printf("File doesn't exist.");
        fprintf(out, "File doesn't exist.");
    }
    else
    {
        matr1 = input(in1, &n1, &m1);
        matr2 = input(in2, &n2, &m2);

        if (!matr1 || !matr2)
        {
            printf("Allocation error");
            fprintf(out, "Allocation error");
        }
        else if (m1 == n2)
        {
            res = alloc_mat(n1, m2);
            res = multiplication(matr1, matr2, res, n1, m1, n2, m2);
            print_mat(res, n1, m2);
            output(out, res, n1, m2);
            free_mat(res);
        }
        else
        {
            printf("Multiplication error: wrong size of matrix");
            fprintf(out, "Multiplication error: wrong size of matrix");
        }
        free_mat(matr1);
        free_mat(matr2);
    }

    fclose(in1);
    fclose(in2);
    fclose(out);
}

void block_det(char *argv[])
{
    FILE *in, *out;
    float **matr = NULL;
    int n = 0, m = 0;
    float res;

    out = fopen(argv[3], "w");
    in = fopen(argv[2], "r");

    if (!in)
    {
        printf("File doesn't exist.");
        fprintf(out, "File doesn't exist.");
    }
    else
    {
        matr = input(in, &n, &m);
        if (!matr)
        {
            printf("Allocation error");
            fprintf(out, "Allocation error");
        }
        else if (n == m)
        {
            res = determinator(matr, n);
            printf("Det: %f", res);
            fprintf(out, "%f", res);
        }
        else
        {
            printf("Wrong size of matrix");
            fprintf(out, "Wrong size of matrix");
        }
        free_mat(matr);
    }

    fclose(in);
    fclose(out);
}

// Show help info in console
void get_help()
{
    puts("\nHello, friend.");
    puts("\nTo add two matrices you should use (a) operation flag:");
    puts("./app.exe a in1_file.txt in2_file.txt out_file.txt");

    puts("\nTo multiply two matrices you should use (m) operation flag:");
    puts("./app.exe m in1_file.txt in2_file.txt out_file.txt");

    puts("\nTo calculate determinator you should use (o) operation flag:");
    puts("./app.exe o in_file.txt out_file.txt");

    puts("\nStructure of input file:");
    puts("#rows #columns #non_zero_elements");
    puts("index_row index_column value");

    puts("\nProgram was made by Tanya Obergan");
}

// returns negative if error, positive - operation number
int check_args(int argc, char *argv[])
{
    int flag = 0;

    if (argc < 2)
    {
        printf("Too few arguments.");
        return -1;
    }

    if (!strcmp(argv[1], "a"))
    {
        if (argc == 5)
            flag = add;
        else
            flag = -1;
    }
    else if (!strcmp(argv[1], "m"))
    {
        if (argc == 5)
            flag = multiply;
        else
            flag = -1;
    }
    else if (!strcmp(argv[1], "o"))
    {
        if (argc == 4)
            flag = det;
        else
            flag = -1;
    }
    else if (!strcmp(argv[1], "h"))
    {
        flag = help;
    }
    else
    {
        printf("Wrong action");
        flag = -2;
    }

    if (flag == -1)
        printf("Too few arguments.");

    return flag;
}


