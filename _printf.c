#include "main.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * _printf - produces output according to a format
 * @format: character string containing zero or more directives
 *
 * Return: number of characters printed (excluding null byte)
 */
int _printf(const char *format, ...)
{
	va_list args;
	int printed_chars = 0;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
			{
				char c = va_arg(args, int);
				putchar(c);
				printed_chars++;
			}
			else if (*format == 's')
			{
				char *str = va_arg(args, char *);
				if (!str)
					str = "(null)";
				while (*str)
				{
					putchar(*str);
					printed_chars++;
					str++;
				}
			}
			else if (*format == '%')
			{
				putchar('%');
				printed_chars++;
			}
			else
			{
				putchar('%');
				putchar(*format);
				printed_chars += 2;
			}
		}
		else
		{
			putchar(*format);
			printed_chars++;
		}
		format++;
	}
	va_end(args);
	return (printed_chars);
}

