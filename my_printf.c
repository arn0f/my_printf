/*******************************************************************************
*
* File Name         : my_printf.c
* Created By        : arn0f
* Creation Date     : septembre  9th, 2015
* Last Change       : septembre 25th, 2015 at 14:59:02
* Last Changed By   : Arnaud Fredon
* Purpose           : That file realize alle the function relative to 'my_printf'
*
*******************************************************************************/

#include <stdarg.h>
#include "my_string.h"
#include "my_put.h"
#include "my_put.1.h"
#include "my_maths.h"
#include "my_check.h"
#include "my_format.h"

int G_specifier_size = 12;
char G_specifier [12] = {'c', 'd', 'i', 'o', 'b', 's', 'S', 'u', 'x', 'X', 'p', '%'};

int G_flag_size = 5;
char G_flag [5] = {'+', '-', ' ', '#', '0'};

int G_width_size = 11;
char G_width [11] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '*'};

/*
 * Function: get_specifier_chain
 * Purpose: Function permit to get the string associated to the parameter given
 * Input:
 * 	char spe: character related to specifier
 * 	va_list ap: argument pointer
 * Output: string formated as specifier recommanded
 */
char * get_specifier_chain(char spe, va_list ap)
{
	char * ret;
	if (spe == 'c')	ret = char_to_str(va_arg(ap, int));
	else if (spe == 'd' || spe == 'i')	ret = my_put_decimal(va_arg(ap, int));
	else if (spe == 'o')	ret = my_putnbr_base(va_arg(ap, int), 8, 0);
	else if (spe == 'b')	ret = my_putnbr_base(va_arg(ap, int), 2, 0);
	else if (spe == 's')	ret = va_arg(ap, char *);
	else if (spe == 'S')	ret = non_printable_octal(va_arg(ap, char *));
	else if (spe == 'u')	ret = my_put_big_nbr_base(va_arg(ap, unsigned int), 10, 0);
	else if (spe == 'x')	ret = my_put_hexa(va_arg(ap, int), 1);
	else if (spe == 'X')	ret = my_put_hexa(va_arg(ap, int), 0);
	else if (spe == 'p')	ret = my_put_ptr(va_arg(ap, int));
	else if (spe == '%')	ret = char_to_str('%');

	return (char *)ret;
}

/*
 * Function: get_width
 * Purpose: Function return the decimal value related to char value given as width parameter
 * Input: 
 * 	int width: old width
 * 	char val: char value to add to width
 * Output: width with, the char width added 
 */
int get_width(int width, char val)
{
	width = width*10 + (val - '0');
	return width;
}


/*
 * Function: my_printf
 * Purpose: That function is the central one for the 'my_print_f'. It's permit to check that all
 * the parameter given are correct. After that, functions needed are called. All functions
 * called for parameter return string. It's a choice to permit to easily manipulate 
 * different flag, delimiter, precision, specifier...
 * Input:
 * 	char * format: string to works with
 * 	...: any other else parameter with any type wanted
 * Output: 0 if no problem 
 */
int my_printf(const char * format, ...)
{
	int str_size = my_strlen(format), cnt = 0, width = 0;
	char * printed_chain = "\0", * flag = "\0", * str = "\0";
	va_list ap;

	va_start(ap, format);

	for (; cnt < str_size; cnt ++)
	{
		if (format[cnt] == '%')
		{
			cnt += 1;
			if (check_parameter(format[cnt], G_flag, G_flag_size))
			{
				do {flag = my_strcat(flag, char_to_str(format[cnt])); cnt += 1;}
				while(check_parameter(format[cnt], G_flag, G_flag_size));
			}
			if(check_parameter(format[cnt], G_width, G_width_size)){
                do{width = get_width(width, format[cnt]); cnt += 1;}
                while('0' <= format[cnt] && format[cnt] <= '9');
            }
			if (check_parameter(format[cnt], G_specifier, G_specifier_size))
			{
				str = (char *)get_specifier_chain(format[cnt], ap);
				printed_chain = my_strcat(printed_chain, format_chain(str, flag, width, format[cnt], G_specifier, G_specifier_size));
				cnt += 1;
			}
			else printed_chain = my_strcat(printed_chain, "%\0");
		}
		printed_chain = my_strcat(printed_chain, char_to_str(format[cnt]));
	}
	my_puts(printed_chain);

	return (0);
}
