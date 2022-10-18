#include "main.h"
/**
 * pchar - return char
 * @arg: arg
 * Return: 1 on success
 */
int pchar(va_list arg)
{
	putchar(va_arg(arg, int));
	return (1);
}

/**
 * pstr - return an str
 * @arg: var to write
 * Return: string
 */
int pstr(va_list arg)
{
	int i = 0;
	char *s = va_arg(arg, char *);

	if (s == NULL)
		s = "(null)";
	while (s[i] != '\0')
	{
		putchar(s[i]);
		i++;
	}
	return (i);
}

/**
 * pperc - return per
 * @arg: arg
 * Return: per
 */
int pperc(va_list arg)
{
	(void)arg;
	putchar('%');
	return (1);
}

/**
 * pint - retun an int
 * @arg: arg
 * Return: len
 */
int pint(va_list arg)
{
	int n = va_arg(arg, int);
	int d, len;
	unsigned int num;

	d = 1;
	len = 0;
	num = n;
	if (n < 0)
	{
		putchar('-');
		len++;
		num = -n;
	}

	while (num / d > 9)
		d *= 10;
	while (d != 0)
	{
		putchar('0' + num / d);
		len++;
		num %= d;
		d /= 10;
	}
	return (len);
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
/**
 * hexa - prints in hexadecimal form in lowercase.
 * @n: unsigned ling int
 * Return: j
 */
int hexa(unsigned int n)
{
	unsigned int a[1024];
	int i = 0, j = 0;
	char p;

	if (n < 1)
	{
		putchar('0');
		return (1);
	}
	for (i = 0; n > 0; i++, j++)
	{
		a[j] = n % 16;
		n = n / 16;
		if (a[j] > 10)
			a[i] = a[j] + 39;
		else
			a[i] = a[j];
	}
	for (i = j - 1; i >= 0; i--)
	{
		p = a[i] + '0';
		putchar(p);
	}
	return (j);
}

/**
 * ppntr - print pointer
 * @arg: arg
 * Return: length
 */
int ppntr(va_list arg)
{

	unsigned long int n = va_arg(arg, unsigned long int);
	int len = 0;

	putchar('0');
	putchar('x');
	len += hexa(n);
	len = len + 2;
	return (len);
}
