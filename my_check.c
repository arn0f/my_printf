/*******************************************************************************
*
* File Name         : my_check.c
* Created By        : arn0f
* Creation Date     : septembre 23th, 2015
* Last Change       : septembre 24th, 2015 at 15:39:57
* Last Changed By   : arn0f
* Purpose           : That file contain all the function that permit to check
* 			which parameters are given
*
*******************************************************************************/

/*
 * Function: check_parameter
 * Purpose: That function permit to check if a parameter is valid or not
 * Input: 
 * 	str: the parameter char to check validity
 * 	tab: array containing all possible parameters
 * 	size: size of the array given
 * Output: 0 or 1 (false or true)
 */
int check_parameter(char str, char * tab, int size)
{
	int i = 0;
	while (i < size)
	{
		if (str == tab[i])
		{
			return 1;
		}
		i ++;
	}
	return 0;
}


/*
 * Function: check_parameter_value
 * Purpose: That function permit to return the index of the parameter in the array
 *  if exist
 * Input: 
 * 	str: the parameter char to check validity
 * 	tab: array containing all possible parameters
 * 	size: size of the array given
 * Output: index of the parameter in the array. If not in the array, -1 returned
 */
int check_parameter_value(char str, char * tab, int size)
{
	int i = 0;
	while (i < size)
	{
		if (str == tab[i])
		{
			return i;
		}
		i ++;
	}
	return -1;
}
