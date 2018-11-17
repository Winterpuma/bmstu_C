#ifndef TESTS_H
#define TESTS_H

int compare_files(FILE *f1, FILE *f2);
void test(const char *in_name, const char *out_name, const char *search, const char *replace, int tc);

#endif // TESTS_H
