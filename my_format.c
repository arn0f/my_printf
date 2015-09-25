/*******************************************************************************
*
* File Name         : my_format.c
* Created By        : arn0f
* Creation Date     : septembre  2th, 2015
* Last Change       : septembre 25th, 2015 at 14:47:38
* Last Changed By   : Arnaud Fredon
* Purpose           : That file contain all the function relative to formating
* 			the string given
*
*******************************************************************************/

#include <stdlib.h>
#include "my_check.h"
#include "my_string.h"
#include "my_format.h"


/*
 * Function: format_chain
 * Purpose: That function permit to format a string keeping in mind flag, width, spe
 * Input:
 * 	char * str: string to format
 * 	char * flag: array containing all flag given
 * 	int width: width to add (before or after the string)
 * 	char type: specifier given for the string
 * 	char * spe: array containing all the specifier available
 * 	int spe_size: size of the previous array
 * Output: string containing the final formated one
 */
char * format_chain(char * str, char * flag, int width, char type, char * spe, int spe_size)
{
	int i = 0, len = my_strlen(flag), left = 0, 
	t_val = check_parameter_value(type, spe, spe_size);
	char pad = ' ';
	if (flag == NULL && width == 0)
	{
		return str;
	}
	while (i < len)
	{
		if (flag[i] == '+' && str[0] != '-') 	{str = my_strcat("+\0", str);}
		else if (flag[i] == ' ') 	{str = my_strcat(" \0", str);}
		else if (flag[i] == '0') 	{pad = '0';}
		else if (flag[i] == '-') 	{left = 1;}
		else if (flag[i] == '#' && t_val == 3)	{str = my_strcat("0\0", str);}
		else if (flag[i] == '#' && t_val == 8)	{str = my_strcat("0x\0", str);}
		else if (flag[i] == '#' && t_val == 9)	{str = my_strcat("0X\0", str);}
		i += 1;
	}

	return generate_padded_chain(str, left, pad, width);
}


/*
 * Function: generate_padded_chain
 * Purpose: That function permit to generated the string with the padding
 * add on the left or on the right depend on what specified
 * Input:
 * 	char * str: string to format
 * 	int left: 0 or 1, right or left padding
 * 	char pad: char of the padding hoped
 * 	int width: size of the padding wanted
 * Output: The string with the padding wanted added
 */
char * generate_padded_chain(char * str, int left, char pad, int width)
{
	width = width - my_strlen(str);
	char * new_pad = generate_space(pad, width);
	if (left)
	{
		str = my_strcat(str, new_pad);
	}
	else
	{
		str = my_strcat(new_pad, str);
	}

	return str;
}


/*
 * Function: generate_space
 * Purpose: The function permit to generate the padding wanted
 * Input:
 * 	char pad: char of the padding hoped
 * 	int width: size of the padding wanted
 * Output: The padding generated
 */
char * generate_space(char pad, int width)
{
	int i = 0;
	char * ret = "\0", * new_pad = char_to_str(pad);
	for (; i < width; i ++)
	{
		ret = my_strcat(ret, new_pad);
	}

	return ret;
}
