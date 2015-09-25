/*******************************************************************************
*
* File Name         : my_maths.c
* Created By        : arn0f
* Creation Date     : septembre  1th, 2015
* Last Change       : septembre 25th, 2015 at 14:52:08
* Last Changed By   : Arnaud Fredon
* Purpose           : That file contain all the function related on maths 
* 			actions
*
*******************************************************************************/

/*
 * Function: my_absolute
 * Purpose: That function permit to return the absolue value of any integer given
 * Input:
 * 	int integer: integer to get the absolute value
 * Output: absolute value of the integer
 */
int my_absolute(int integer)
{
	if (integer < 0)
	{
		integer = (-1) * integer;
	}

	return integer;
}
