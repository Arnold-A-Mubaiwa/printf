#include "main.h"
/**
 * get_printf - get_printf to get function from function.c
 * @ap: arg
 * @c: char
 * Return: char
 */
int get_printf(const char c, va_list ap)
{
	int i = 0;
	int j = 0;
	print_t type[] = {
		{'c', pchar},
		{'s', pstr},
		{'%', pperc},
		{'d', pint},
		{'i', pint},
		{'b', pbin},
		{'u', puns},
		{'o', poct},
		{'x', phex},
		{'X', pHEX},
		{'p', ppntr},
    };

	while (type[i].data != 0)
	{
		if (type[i].data == c)
		{
			j += type[i].f(ap);
			return (j);
		}
		i++;
	}
	return (0);
}
