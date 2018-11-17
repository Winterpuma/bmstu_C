#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

#include "my_str.h"
#include "process.h"

int main(int argc, char *argv[])
{
    if (check_args(argc, argv))
    {
        printf("Something wrong with args.\n");
        return -1;
    }

    FILE *f_in = fopen(argv[1], "r");
    if (!f_in)
    {
        printf("File doesn't exist");
        return -1;
    }

    FILE *f_out = fopen(argv[2], "w");

    process(f_in, f_out, argv[3], argv[4]);

    fclose(f_in);
    fclose(f_out);

    return 0;
}


