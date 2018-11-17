#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

#include "process.h"
#include "my_str.h"

/**
 * Main function of programm
 * @param f_in [in] - in file
 * @param f_out [out] - out file
 * @param search [in] - pointer to search string
 * @param replace [in] - pointer to replace string
 */
void process(FILE *f_in, FILE *f_out, const char *search, const char *replace)
{
    size_t size_line = 0;
    char *str = NULL;
    char *str_edited = NULL;

    while (my_getline(&str, &size_line, f_in))
    {
        str_edited = str_replace(str, search, replace);
        fprintf(f_out, "%s", str_edited);
    }

    free(str);
    free(str_edited);

}

/**
 * Check args for correctness
 * @return 0 if args are correct
 */
int check_args(int argc, char *argv[])
{
    if (argc != 5)
        return 1;
    return 0;
}
