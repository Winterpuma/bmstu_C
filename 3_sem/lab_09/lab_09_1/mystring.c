#include <string.h>

/**
My realisation of strrchr

@param str [in]
@param ch [in] - char to find
@return index of last ch in str or null
*/
char *my_strrchr(const char *str, int ch)
{
    char *last_found = 0;
    while (*str)
    {
        if (*str == ch)
            last_found = (char *)str;

        str++;
    }

    if (ch == '\0')
        last_found = (char *)str;

    return last_found;
}
