#include "main.h"
#include <stdarg.h>
/**
 * _printf - customized printf function
 * @format: the string
 * Return: the number of characters printed;
 */
int _printf(const char *format, ...)
{
	va_list arg;
	char *s;
	int n;

	if(format == NULL)
		exit(0);
	va_start(arg, char);
	n = 0;
	while (*format != '\0')
	{
		if (*format != "%")
		{
			_putchar(*format);
			n++;
		}
		else
		{
			format++;
			if (*format == 'c')
				_putchar(*format);
			else if (*format == 's')
			{
				s = va_arg(arg, char *);
				while (*s)
				{
					_putchar(*s);
					s++;
				}
			}
			n++;
		}
		format++;
	}
	return (n);
}
