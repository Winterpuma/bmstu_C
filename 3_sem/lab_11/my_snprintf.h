#ifndef LAB_11_MY_SNPRINTF_H
#define LAB_11_MY_SNPRINTF_H

#include <stdlib.h>

int my_snprintf(char *s, size_t n, const char *format, ...);

int handle_numbers(const char **format, char **s, int *s_len, int num);
void add_num(char **s, int *s_len, int num, char alphabet[]);
void check_negative(char **s, int *s_len, int *num);
int count_len(int num, int base);

void move_ptr(char **ptr, int *ptr_len, int step);

#endif //LAB_11_MY_SNPRINTF_H
