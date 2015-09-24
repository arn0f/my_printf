/*******************************************************************************
*
* File Name         : my_print.h
* Created By        : arn0f
* Creation Date     : septembre  2th, 2015
* Last Change       : septembre 22th, 2015 at 23:22:12
* Last Changed By   : arn0f
* Purpose           : That file contain all the prototypes of the functions 
* 			defined in the file 'my_printf.c'
*
*******************************************************************************/

#ifndef GET_SPECIFIER_CHAIN_H
#define GET_SPECIFIER_CHAIN_H

char * get_specifier_chain(char spe, va_list ap);

#endif


#ifndef GET_WIDTH_H
#define GET_WIDTH_H

int get_width(int width, char val);

#endif


#ifndef MY_PRINTF_H
#define MY_PRINTF_H

int my_printf(const char * format, ...);

#endif