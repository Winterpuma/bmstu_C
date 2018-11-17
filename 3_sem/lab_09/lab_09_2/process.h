#ifndef PROCESS_H
#define PROCESS_H

void process(FILE *f_in, FILE *f_out, const char *search, const char *replace);
int check_args(int argc, char *argv[]);

#endif // PROCESS_H
