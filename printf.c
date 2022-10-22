#include "main.h"
#include <stdarg.h>
/**
 *printS - prints a string
 *@s: the string
 *@n: the number of characters to printed;
 */
void printS(char *s, int *n)
{
	while (*s)
	{
		putchar(*s);
		*n += 1;
		s++;
	}
	*n -= 1;
}
/**
 * _printf - customised printf function
 * @format: the string
 * Return: the number of characters printed;
 */
int _printf(const char *format, ...)
{
	va_list arg;
	char c;
	int n;

	n = 0;
	if (format == NULL)
		return (0);
	va_start(arg, format);
	while (*format != '\0')
	{
		c = *format;
		format++;
		if ((c == '%') &&
		(*format == 'c' || *format == 's'  || *format == '\0' || *format == '%'))
		{
			switch (*format)
			{
				case 'c':
					putchar(va_arg(arg, int));
					break;
				case 's':
					printS(va_arg(arg, char *), &n);
					break;
				case '%':
					putchar('%');
					break;
				case '\0':
					n--;
					continue;
			}
			format++;
		}
		else if (c != '%')
			_putchar(c);
		n++;
	}
	va_end(arg);
	return (n);
}
