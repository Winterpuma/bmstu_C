#ifndef MAIN_H
#define MAIN_H

int go(FILE *f_in, FILE *f_out, int flag);
int file_error(FILE *f_in, FILE *f_out);
void filter_error(int error, FILE *f_out);

#endif // MAIN_H
