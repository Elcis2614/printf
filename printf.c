#include "main.h"
#include <stdarg.h>
/**
 *_printf - customized printf function
 *@format: the string
 *Return: the number of characters printed;
 */
int _printf(const char *format, ...)
{
	va_list arg;
	char *s, c;
	int n;

	if (format == NULL)
		exit(0);
	va_start(arg, format);
	n = 0;
	while (*format != '\0')
	{
		if (*format != '%')
		{
			_putchar(*format);
			n += 1;
		}
		else
		{
			c = *format;
			format++;
			if (*format == 'c')
			{
				_putchar(va_arg(arg, int));
				n += 1;
			}
			else if (*format == 's')
			{
				s = va_arg(arg, char *);
				while (*s)
				{
					_putchar(*s);
					n += 1;
					s++;
				}
			}
			else if (*format == '%')
			{
				putchar(*format);
				n++;
			}
			else
			{
				putchar(c);
				putchar(*format);
				n += 2;
			}
		}
		format++;
	}
	return (n);
}
