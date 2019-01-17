#ifndef LAB_14_ADT_STRING_ALL_H
#define LAB_14_ADT_STRING_ALL_H

typedef struct node* node_t;
typedef struct string_type* string_t;

string_t str_create(char *str);
void str_destroy(string_t s);

string_t str_concatenate(string_t s1, string_t s2);
int str_compare(string_t s1, string_t s2);
void str_replace_char(string_t s, char find, char replace_with);
void str_edit_by_index(string_t s, int index, char replace_with);

void str_print(string_t s);
size_t str_len(string_t s);

#endif //LAB_14_ADT_STRING_ALL_H
