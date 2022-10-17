#include "main.h"
/**
 *print_char - function that prints single character
 *@ptr: input data from user
 *Return: character to be print
 */
int print_char(va_list ptr)
{
	char c;

	c = va_arg(ptr, int);

	if (c == '\0')
	{
		return ('\0');
	}

	_putchar(c);
	return (1);
}
/**
 *print_string - prints a sequence of character.
 *@ptr: input data from users.
 *Return: the sequence of character to be print.
 */

int print_string(va_list ptr)
{
	char *str;
	int i;

	str = va_arg(ptr, char *);

	if (*str == '\0')
	{
		_putchar('\0');
	}

	for (i = 0 ; str[i] != '\0'; i++)
	{
		_putchar(str[i]);
	}

	return (i);
}

/**
 * print_numbers - Prints the integer
 * @arp: Argument Pointer
 *
 * Return: Count of all numbers printed
 */

int print_numbers(va_list arp)
{
	int num = 0, count = 0;

	num = va_arg(arp, int);
	count += print_int(num);

	return (count);
}

/**
 * print_int - Prints the integer
 * @i: Number to be printed
 *
 * Return: Count of all numbers printed
 */

int print_int(int i)
{
	int count = 1;
	unsigned int num = 0;

	if (i < 0)
	{
		_putchar('-');
		count++;
		num = i * -1;
	}
	else
	{
		num = i;
	}
	if (num / 10)
	{
		count += print_int(num / 10);
	}
	_putchar((num % 10) + 48);

	return (count);
}

int pperc(va_list arg)
{
	(void)arg;
	putchar('%');
	return (1);
}

/**
 * pbin - make a b
 * @arg: arg
 * Return: len
 */
int pbin(va_list arg)
{
	unsigned int b[32];
	int i = 0;
	unsigned int n = 0, j = 0;

	n = va_arg(arg, unsigned int);
	if (n <= 1)
	{
		putchar(n + '0');
		j++;
	}
	else
	{
		while (n > 0)
		{
			b[i] = n % 2;
			n = n / 2;
			i++;
		}
		for (i = i - 1; i >= 0; i--)
		{
			putchar(b[i] + '0');
			j++;
		}
	}
	return (j);
}

int puns(va_list arg)
{
	unsigned int num, a = 0, div;

	num = va_arg(arg, int);

	if (num == 0)
	{
		putchar('0');
		a = 1;
	}
	if (num > 0)
	{
		for (div = 1; (num / div) > 9; div *= 10)
			;
		while (div != 0)
		{
			putchar((num / div) + '0');
			num %= div;
			div /= 10;
			a++;
		}
	}
	return (a);
}

/**
 * poct - Unsigned octal
 *
 * @arg: arg
 * Return: length
 */
int poct(va_list arg)
{

	unsigned int num, a = 0, i = 0;
	int tab[100];

	num = va_arg(arg, int);
	if (num < 9)
	{
		putchar(num + '0');
		a = 1;
	}
	else if (num >= 9)
	{
		while (num > 0)
		{
			tab[i] = num % 8;
			num /= 8;
			i++;
		}
	}
	while (i--)
	{
		putchar(tab[i] + '0');
		a++;
	}
	return (a);
}

/**
 * phex - Unsigned hexadecimal integer
 * @arg: arg
 * Return: length
 */
int phex(va_list arg)
{
	unsigned int n = va_arg(arg, unsigned int);
	unsigned int a[1024];
	int i = 0, t = 0;
	char p;

	if (n < 1)
	{
		write(1, "0", 1);
		return (1);
	}
	for (i = 0; n > 0; i++, t++)
	{
		a[t] = n % 16;
		n = n / 16;
		if (a[t] > 10)
			a[i] = a[t] + 39;
		else
			a[i] = a[t];
	}
	for (i = t - 1; i >= 0; i--)
	{
		p = a[i] + '0';
		putchar(p);
	}
	return (t);
}

/**
 * pHEX - Unsigned hexadecimal integer (uppercase)
 * @arg: arg
 * Return: length
 */
int pHEX(va_list arg)
{

	unsigned int n = va_arg(arg, unsigned int);
	int a[1024], i = 0, t = 0;
	char p;

	if (n < 1)
	{
		putchar('0');
		return (1);
	}
	for (i = 0; n > 0; i++)
	{
		a[t] = n % 16;
		n = n / 16;
		if (a[i] > 10)
			a[i] = a[t] + 7;
		else
		{
			a[i] = a[t];
		}
		t++;
	}
	for (i = t - 1; i >= 0; i--)
	{
		p = a[i] + '0';
		putchar(p);
	}
	return (t);
}
