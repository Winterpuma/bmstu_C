/*
 *  This program finds out minimal distance between two local maximums of sqc.
*/

#include "stdio.h"

int process(FILE *f)
{
    typedef int ERR;
    enum ERR{no_loc_max=-1, not_enough_num=-2};

    float x1, x2, x3;
    int max_1 = 0, max_2 = 0, diff = 10000, i = 0;
    int check;

    check = fscanf(f, "%f%f%f", &x1, &x2, &x3);
    if (check < 3)
        return not_enough_num;
    i++;

    while (check)
    {
        if ((x2 > x1) && (x2 > x3))
        {
            if (!max_1)
                max_1 = i;
            else if (!max_2)
            {
                max_2 = i;
                if ((max_2 - max_1) < diff)
                    diff = max_2 - max_1;
            }
            else
            {
                max_1 = max_2;
                max_2 = i;
                if ((max_2 - max_1) < diff)
                    diff = max_2 - max_1;
            }
        }

        x1 = x2;
        x2 = x3;
        check = fscanf(f, "%f", &x3);
        i++;
    }
    if (diff == 10000)
        return no_loc_max;
    else
        return diff;
}


int main()
{
    typedef int ERR;
    enum ERR{no_loc_max=-1, not_enough_num=-2};
    ERR n;

    n = process(fopen("data.txt", "r"));
    if (n == no_loc_max)
        printf("Can't find two local maximums.");
    else if (n == not_enough_num)
        printf("You have to enter at least three numbers.");
    else
        printf("Minimal distance between two local maximums is %d.", n);
    return 0;
}
