#ifndef MY_STR_H
#define MY_STR_H

ssize_t my_getline(char **lineptr, size_t *n, FILE *stream);
int add_char(const char *str, const char *search, const char *replace, char **my_str, int *max_size, int *curr_size, int *i);
char *str_replace(const char *str, const char *search, const char *replace);
void realloc_str(char **str, int *max_size, int size, int flag);

#endif // MY_STR_H
