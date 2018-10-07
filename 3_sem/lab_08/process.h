#ifndef PROCESS_H
#define PROCESS_H

enum OPERATION {add = 1, multiply = 2, det = 3, help = 4};

void process(char *argv[], int key);
void block_add(char *argv[]);
void block_multiply(char *argv[]);
void block_det(char *argv[]);
void get_help();

int check_args(int argc, char *argv[]);

#endif // PROCESS_H
