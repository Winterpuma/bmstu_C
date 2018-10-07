#ifndef OPERATIONS_H
#define OPERATIONS_H

float **addition(float **matr1, float **matr2, int n, int m);
float **multiplication(float **matr1, float **matr2, float **res, int n1, int m1, int n2, int m2);

int max_in_col(float **matr, int col_index, int n);
void swap_rows(float **matr, int n1, int n2);
void triangulation(float **matr, int n);
float determinator(float **matr, int n);

int compare_zero(float num);
int compare_float(float num1, float num2);

#endif // OPERATIONS_H
