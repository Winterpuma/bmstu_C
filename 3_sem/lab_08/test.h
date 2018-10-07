#ifndef TEST_H
#define TEST_H

void test(int argc, char *argv[], char TC, int key);
void test_args(int argc, char *argv[], char TC, int flag);
int compare_files(FILE *f1, FILE *f2, int fl_det);
int compare_err(FILE *f1, FILE *f2);

#endif // TEST_H
