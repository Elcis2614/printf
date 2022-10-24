#include "main.h"
#include <stdarg.h>
/**
 * printD - print an integer
 * @s: the integer to print
 * @n: the number of character printed
 */
void printD(int s, int *n)
{
	int t, d;

	t = d = s;
	if (t < 0)
	{
		putchar('-');
		d *= -1;
		t *= -1;
		*n += 1;
	}
	if ((t - (t % 10)) != 0)
	{
		t = (t - (t % 10)) / 10;
		printD(t, n);
		putchar((d % 10) + '0');
	}
	else
		putchar(d + '0');
	*n += 1;
}
/**
 *printS - prints a string
 *@t: the string
 *@n: the number of characters to printed;
 */
void printS(char *t, int *n)
{
	char *s;

	if (t == NULL)
		s = "(null)";
	else
		s = t;
	while (*s)
	{
		_putchar(*s);
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
		exit(0);
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
					_putchar(va_arg(arg, int));
					break;
				case 's':
					printS(va_arg(arg, char *), &n);
					break;
				case '%':
					_putchar('%');
					break;
				case '\0':
					n--;
					continue;
			}
			format++;
		}
		else
			_putchar(c);
		n++;
	}
	va_end(arg);
	return (n);
}
