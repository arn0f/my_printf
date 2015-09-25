/*******************************************************************************
*
* File Name         : my_string.c
* Created By        : arn0f
* Creation Date     : septembre  3th, 2015
* Last Change       : septembre 25th, 2015 at 15:00:01
* Last Changed By   : Arnaud Fredon
* Purpose           : That file containing all the function related on strings 
* 			actions
*
*******************************************************************************/

#include <stdlib.h>
#include "my_put.h"

/*
 * Function: my_strlen
 * Purpose: That function permit to return the legnth (numbre of character) of any
 * string given
 * Input: 
 * 	char * s: string to return the length
 * Output: 
 * 	integer: the length of the string
 */
int my_strlen(const char *s)
{
	int size_t = 0;

	while (s[size_t] != '\0')
	{
		size_t ++;
	}

	return (size_t);
}

/*
 * Function: my_strcat
 * Purpose: That function permit to concatanate any string. The string returned is the
 * concatanate one
 * Input:
 * 	char * dest: first string in concatenation
 * 	char * src: second string in the concatenation
 * Output: the resulting string of the concatenation
 */
char * my_strcat(char *dest, char *src)
{
	int cnt = 0, len_dest = my_strlen(dest),\
		  len_cat = len_dest + my_strlen(src);
	char * str = malloc ((len_cat + 1) * sizeof(char));
	
	while (cnt < len_dest)
	{
		* (str + cnt) = * (dest + cnt);
		cnt ++;
	}
	cnt = 0;

	while ((cnt + len_dest) < len_cat)
	{
		* (str + cnt + len_dest) = * (src + cnt);
		cnt ++;
	}
	* (str + len_cat) = '\0';

	return str;
}

/*
 * Function: char_to_str
 * Purpose: That function permit to convert a char into string
 * Input:
 * 	char src: char to set in str
 * Output: the string of the char
 */
char * char_to_str(char src)
{
	char * ret = malloc(sizeof(char) * 2);
	* ret = src;
	* (ret + 1) = '\0';

	return ret;
}

/*
 * Function: str_to_char
 * Purpose: That function permit to convert a string into char
 * Input:
 * 	char * str: string to get the first letter 
 * Output: char of the first letter of the string
 */
char str_to_char(char * str)
{
	char ret = * str;
	return ret;
}

/*
 * Function: non_printable_octal
 * Purpose: That function permit to return formated with the octal value of 
 * non-printable character of the string given. For example, if the string given 
 * is "as'10'tek", the returned string will be "as\012ek" with '\012' the octal 
 * value of the non-printable character '10' ('\n' in the ASCII table)
 * Input:
 * 	char * str: string to get the extended format
 * Output: extended string of the char given
 */
char * non_printable_octal(char * str)
{
	int i = 0;
	char * ret = malloc(my_strlen(str) * sizeof(char));

	while (str[i])
	{
		if (str[i] < 32)
		{
			ret = my_strcat(my_strcat(ret, "\\0"), 
				(char *)my_putnbr_base(str[i], 8, 0));
		}
		else
		{
			ret = my_strcat(ret, char_to_str(str[i]));
		}

		i++;
	}

	return ret;
}
