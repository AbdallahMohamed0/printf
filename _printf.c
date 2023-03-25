#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - produces output according to a format.
 * @format: character string containing zero or more directives.
 * Return: number of characters printed (excluding null byte used to end output to strings).
 */
int _printf(const char *format, ...)
{
    va_list arg;
    int printed_chars = 0;

    va_start(arg, format);

    while (*format)
    {
        if (*format == '%')
        {
            format++;

            if (*format == 'c')
            {
                char c = va_arg(arg, int);
                write(1, &c, 1);
                printed_chars++;
            }
            else if (*format == 's')
            {
                char *str = va_arg(arg, char *);
                int len = 0;

                while (str[len])
                    len++;

                write(1, str, len);
                printed_chars += len;
            }
            else if (*format == '%')
            {
                write(1, "%", 1);
                printed_chars++;
            }
            else
            {
                write(1, "%", 1);
                write(1, format, 1);
                printed_chars += 2;
            }
        }
        else
        {
            write(1, format, 1);
            printed_chars++;
        }

        format++;
    }

    va_end(arg);

    return (printed_chars);
}

