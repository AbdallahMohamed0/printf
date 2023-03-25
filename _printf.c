#include <stdarg.h>
#include <stdio.h>
#include "main.h"

/**
 * _printf - Custom printf function
 * @format: Format string
 *
 * Return: Number of characters printed (excluding null byte)
 */
int _printf(const char *format, ...)
{
    int i = 0, len = 0;
    va_list args;

    va_start(args, format);

    while (format && format[i])
    {
        if (format[i] == '%')
        {
            i++;
            switch (format[i])
            {
                case 'c':
                    len += putchar(va_arg(args, int));
                    break;
                case 's':
                    len += printf("%s", va_arg(args, char *));
                    break;
                case '%':
                    len += putchar('%');
                    break;
                default:
                    putchar('%');
                    putchar(format[i]);
                    len += 2;
                    break;
            }
        }
        else
        {
            len += putchar(format[i]);
        }
        i++;
    }

    va_end(args);
    return len;
}

