#include "main.h"
/**
 * _printf - A Function that prints in stdout
 *@format:the parameters passed into the function.
 *Return: character to be printed.
 */
int _printf(const char *format, ...)
{
	int i = 0, j = 0, a = 0;
	va_list ap;

	if (format == NULL || (strlen(format) == 1 && format[0] == '%'))
	{
		return (-1);
	}
	va_start(ap, format);
	while (format && format[i])
	{
		if (format[i] != '%')
		{
			putchar(format[i]);
			j++;
		}
		if (format[i] == '%' && format[i + 1] != 'K' && format[i + 1] != '!')
		{
			a = get_printf(*(format + (i + 1)), ap);
			if (a != 0)
				j = j + a;
			i = i + 2;
			continue;
			if (*(format + (i + 1)) == '\0')
			{
				putchar(format[i]);
				j++;
			}
		}
		else if ((format[i] == '%' && format[i + 1] == 'K') ||
		 (format[i] == '%' && format[i + 1] == '!'))
		{
			putchar(format[i]);
			j++;
		}
		i++;
	}
	va_end(ap);
	return (j);
}
