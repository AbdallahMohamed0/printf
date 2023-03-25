#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <ctype.h>

/**
 * get_precision - Calculates the precision for printing
 * @format: Formatted string in which to print the arguments
 * @i: Index of the current character in the format string
 * @list: List of arguments to be printed
 *
 * Return: Precision
 */
int get_precision(const char *format, int *i, va_list list)
{
    int curr_i = *i + 1;
    int precision = -1;

    if (format[curr_i] != '.')
        return precision;

    precision = 0;
    curr_i++;

    if (format[curr_i] == '*')
    {
        precision = va_arg(list, int);
        curr_i++;
    }
    else
    {
        while (isdigit(format[curr_i]))
        {
            precision = (precision * 10) + (format[curr_i] - '0');
            curr_i++;
        }
    }

    *i = curr_i - 1;

    return precision;
}

/**
 * _printf - Prints a formatted string to the standard output
 * @format: Formatted string in which to print the arguments
 *
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
    if (format == NULL)
        return -1;

    int chars_printed = 0;
    int i = 0;
    va_list list;

    va_start(list, format);

    while (format[i] != '\0')
    {
        if (format[i] == '%')
        {
            int width = 0;
            int precision = -1;
            int left_align = 0;
            int pad_zero = 0;
            char specifier = '\0';
            i++;

            if (format[i] == '-')
            {
                left_align = 1;
                i++;
            }

            if (format[i] == '0')
            {
                pad_zero = 1;
                i++;
            }

            width = get_width(format, &i, list);
            precision = get_precision(format, &i, list);
            specifier = format[i];

            if (specifier == '\0')
                break;

            if (!is_custom_specifier(specifier))
                precision = -1;

            chars_printed += print_arg(list, specifier, width, precision, left_align, pad_zero);
        }
        else
        {
            putchar(format[i]);
            chars_printed++;
        }

        i++;
    }

    va_end(list);

    return chars_printed;
}

