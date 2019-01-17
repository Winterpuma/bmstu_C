#ifndef LAB_14_TEST_ADT_STRING_1_H
#define LAB_14_TEST_ADT_STRING_1_H

#include "adt_string_all.h"

void verdict(string_t my, string_t correct);

void test_str_compare(char msg[], char s1[], char s2[], int res);
void test_str_concatenate_2strings(char s1[], char s2[], char res[]);
void test_str_concatenate_first();
void test_str_concatenate_second();
void test_str_replace_char(char s1[], char find, char replace_with, char res[]);
void test_str_edit_by_index(char s1[], int index, char replace_with, char res[]);

void show_feature(char s1[], char find, char replace_with);

#endif //LAB_14_TEST_ADT_STRING_1_H
