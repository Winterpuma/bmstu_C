#ifndef LAB_11_TEST_H
#define LAB_11_TEST_H

#include "my_snprintf.h"
#include <stdio.h>
#include <stdarg.h>

#define SIZE 50
#define ARGS_CORRECT_DEC  -30, 255, 0, -30, 255, 0
#define ARGS_CORRECT_HEX 255, 255, 0x100, 0x100, 0, 0 , 33, 33
#define ARGS_CORRECT_STR "", "a", "qwerty78"
#define ARGS_MORE_ARGS "Denis", "Alexander", "someone"

void test_my_snprintf_correct_dec();
void test_my_snprintf_correct_hex();
void test_my_snprintf_correct_str();

void test_my_snprintf_more_args();
void test_my_snprintf_without_args(char msg[], char format[], size_t n);

void free_results(char *res1, char *res2);

#endif //LAB_11_TEST_H
