#ifndef _MAIN_H_
#define _MAIN_H_

/*LIBRARIES*/
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*STRUCTURE*/

/**
*struct - a type to print.
*@data: data type.
*@f: function type.
*/
typedef struct pick
{
    char data;
    int (*f)(va_list ptr);

} pick_t;

typedef struct parameters
{
	unsigned int unsign			: 1;

	unsigned int plus_flag		: 1;
	unsigned int space_flag		: 1;
	unsigned int hashtag_flag	: 1;
	unsigned int zero_flag		: 1;
	unsigned int minus_flag		: 1;

	unsigned int width;
	unsigned int precision;

	unsigned int h_modifier		: 1;
	unsigned int l_modifier		: 1;
} params_t;

/*PROTOTYPE TO WRITE OUTPUT TO STDOUT*/
int _putchar(char c);

/*main function*/
int _printf(const char *format, ...);

/*prototypes*/
int print_string(va_list ptr); /*to print string*/
int print_char(va_list ptr); /* to print a single character*/
int print_numbers(va_list arp);
int print_int(int i);
int print_unsigned(va_list ap, params_t *params);
#endif