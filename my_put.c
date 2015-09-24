/*******************************************************************************
*
* File Name         : my_put.c
* Created By        : arn0f
* Creation Date     : septembre  2th, 2015
* Last Change       : septembre 24th, 2015 at 15:39:57
* Last Changed By   : arn0f
* Purpose           : That file contain all the function relative to puting a 
* 			number or a string
*
*******************************************************************************/

#include <unistd.h>
#include "my_string.h"
#include "my_put.h"

/*
 * That function permit to select one of the two dictionary existant for the
 * hexadecimal base. By default the dictionary returned is the uppercase one
 */
char * my_select_dict(int dict)
{
	if (dict != 0)
	{
		return "0123456789abcdef\0";
	}
	return "0123456789ABCDEF\0";
}

/*
 * That function permit a string of any int in the base choosen. That function
 * maximum base if only 16
 */
char * my_putnbr_base(int nbr, int base, int dict)
{ 
	char * nbr_convert;
	char * tab_base = my_select_dict(dict);

	if (nbr < base)
	{
		return (char *)char_to_str(str_to_char(tab_base + nbr));
	}
	else
	{
		nbr_convert = my_strcat(my_putnbr_base(nbr/base, base, dict), 
			char_to_str(str_to_char(tab_base + (nbr%base))));
		return (char *)nbr_convert;
	}
}

/*
 * That function works like the previous one, but it's designed for unsigned int. In 
 * that sense, bigest unsigned int can works with.
 */
char * my_put_big_nbr_base(unsigned int nbr, int base, int dict)
{ 
	char * nbr_convert;
	char * tab_base = my_select_dict(dict);
	if (nbr < base)
	{
		return (char *)char_to_str(str_to_char(tab_base + nbr));
	}
	else
	{
		nbr_convert = my_strcat(my_putnbr_base(nbr/base, base, dict), 
			char_to_str(str_to_char(tab_base + (nbr%base))));
		return (char *)nbr_convert;
	}
}

/*
 * That function permit to write any string given on the standard output
 */
int my_puts(const char *s)
{
	write(1, s, my_strlen(s));

	return (0);
}
