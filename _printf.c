#include <unistd.h>
#include "main.h"
#include <stdarg.h>
/**
 * _printf - Write a function that produces output according to a format.
 * @format: a string containing zero or more format specifiers
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	int i, num = 0;
	va_list args;

	if (format == NULL)
		return (-1);
	va_start(args, format);
	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 'c')
				num += _printf_char(args);
			else if (format[i] == 's')
				num += _printf_string(args);
			else if (format[i] == 'd' || format[i] == 'i')
				num += _printf_number(args);
			else if (format[i] == '%')
				num += _putchar('%');
			else
			{
				_putchar('%');
				_putchar(format[i]);
				num += 2;
			}
		}
		else
		{
			num += _putchar(format[i]);
		}
	}
	va_end(args);
	return (num);
}
