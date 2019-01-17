#include <string.h>
#include <stdarg.h>

#include "my_snprintf.h"

/**
 * My realization of snprintf
 * Allowed specifiers: d x X s hd hx hX
 * @param s - pointer to beginning of result string
 * @param n - max len of string
 * @param format - format string
 * @param ... arguments for format
 * @return len of snprintfed string or -1 in case of overflowing
 */
int my_snprintf(char *s, size_t n, const char *format, ...)
{
    va_list argv;
    va_start(argv, format);

    s[n-1] = 0;

    int flag_finish = 0;
    int s_len = 0;
    int len_last_word = 0;

    while (!flag_finish && *format && s_len<n)
    {
        if (*format == '%')
        {
            format++;
            switch (*format)
            {
                case ('%'):
                    *s = '%';
                    move_ptr(&s, &s_len, 1);
                    break;
                case ('s'):
                    strcpy(s, va_arg(argv, char*));
                    len_last_word = strlen(s);
                    move_ptr(&s, &s_len, len_last_word);
                    break;
                case ('h'):
                    format++;
                    flag_finish = handle_numbers(&format, &s, &s_len,
                                                 (int)va_arg(argv, unsigned int));
                    break;

                default:
                    flag_finish = handle_numbers(&format, &s, &s_len, va_arg(argv, int));
                    break;
            }
        }
        else
        {
            *s = *format;
            move_ptr(&s, &s_len, 1);
        }
        format++;
    }

    va_end(argv);
    *s = 0;

    return (s_len >= n) ? -1 : s_len;
}

/**
 * Move pointer by step and upd its len
 * @param ptr - pointer to string
 * @param ptr_len - pointer to string len
 * @param step - step size
 */
void move_ptr(char **ptr, int *ptr_len, int step)
{
    *ptr += step;
    *ptr_len += step;
}

/**
 * Handle int specifiers
 * @param format - pointer to  pointer to curr position of format string
 * @param s - pointer to pointer to curr position of result string
 * @param s_len - pointer to length of s
 * @param num - number from args
 * @return -1 if wrong specifier, 0 - else
 */
int handle_numbers(const char **format, char **s, int *s_len, int num)
{
    int flag_err = 0;
    switch (**format)
    {
        case ('d'):
            add_num(s, s_len, num, "0123456789");
            break;
        case ('x'):
            add_num(s, s_len, num, "0123456789abcdef");
            break;
        case ('X'):
            add_num(s, s_len, num, "0123456789ABCDEF");
            break;
        default:
            flag_err = -1;
            break;
    }
    return flag_err;
}

/**
 * Insert minus sign if num < o and converts num to positive
 * @param s - pointer to string to insert to
 * @param s_len - pointer to length of string
 * @param num - number to check
 */
void check_negative(char **s, int *s_len, int *num)
{
    if (*num < 0)
    {
        *num *= -1;
        **s = '-';
        move_ptr(s, s_len, 1);
    }
}

/**
 * Count length of number in certain base
 * @param num - number
 * @param base - base of counting
 * @return length in digits
 */
int count_len(int num, int base)
{
    int counter = 0;

    do
    {
        num /= base;
        counter++;
    }
    while (num);

    return counter;
}

/**
 * Add num to string
 * @param s - pointer to curr position
 * @param s_len - pointer to s len
 * @param num - number
 * @param alphabet - array with language chars
 */
void add_num(char **s, int *s_len, int num, char alphabet[])
{
    char *cur;
    int base = (int)strlen(alphabet);
    int num_len = 0;

    check_negative(s, s_len, &num);

    cur = *s;
    num_len = count_len(num, base);
    cur += num_len;

    // write num backward
    do
    {
        cur -= 1;
        *cur = alphabet[num % base];
        num /= base;
    }
    while (num);

    move_ptr(s, s_len, num_len);
}
