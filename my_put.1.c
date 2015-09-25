/*******************************************************************************
*
* File Name         : my_put.c
* Created By        : arn0f
* Creation Date     : septembre  2th, 2015
* Last Change       : septembre 25th, 2015 at 13:44:37
* Last Changed By   : Arnaud Fredon
* Purpose           : That file contain all the function relative to puting a 
* 			number or a string
*
*******************************************************************************/

#include "my_put.h"
#include "my_maths.h"
#include "my_string.h"

/*
 * Function: my_put_decimal
 * Purpose: That function permit to return the string associated to any decimal
 * Input: 
 * 	nbr: integer to return string value
 * Output: string value of the integer
 */
char * my_put_decimal(int nbr)
{
	int neg = 0;
	char * ret;
	if (nbr < 0)
	{
		nbr = my_absolute(nbr);
		neg = 1;
	}
	if (nbr < 2147483648)
	{
		ret = my_put_big_nbr_base(nbr, 10, 0);
	}
	else
	{
		ret = my_putnbr_base(nbr, 10, 0);
	}
	if (neg)
	{
		ret = my_strcat("-\0", ret);
	}
	return ret;
}


/*
 * Function: my_put_ptr
 * Purpose: The function permit to return the hexadecimal value of any pointer given
 * Input:
 * 	ptr: pointer to return hexadecimal value
 * Output: the hexadecimal value of the pointer
 */
char * my_put_ptr(int ptr)
{
	char * ret = my_strcat("0x\0", my_putnbr_base(ptr, 16, 1));

	return ret;
}


/*
 * Function: my_put_hexa
 * Purpose: Permit to return the hexadecimal value of (in uppercase or lowercase)
 * of the integer given
 * Input:
 * 	nbr: integer to return hexadecimal value
 * 	upper: 0 or 1, uppercase or lowercase
 * Output: the hexadecimal value of the integer
 */
char * my_put_hexa(int nbr, int upper)
{
	char * ret;
	if (nbr < 0)
	{
		ret = my_put_big_nbr_base(nbr, 16, upper);
	}
	else
	{
		ret = my_putnbr_base(nbr, 16, upper);
	}

	return ret;
}
