/*******************************************************************************
*
* File Name         : my_string.h
* Created By        : arn0f
* Creation Date     : septembre  3th, 2015
* Last Change       : septembre 22th, 2015 at 23:30:36
* Last Changed By   : arn0f
* Purpose           : That file containing all the prototypes of the functions 
* 			contained in 'string.c' file
*
*******************************************************************************/

#ifndef MY_STRLEN_H
#define MY_STRLEN_H

int my_strlen(const char *s);

#endif


#ifndef MY_STRCAT_H
#define MY_STRCAT_H

char * my_strcat(char * dest, char * src);

#endif


#ifndef CHAR_TO_STR_H
#define CHAR_TO_STR_H

char * char_to_str(char src);

#endif


#ifndef STR_TO_CHAR_H
#define STR_TO_CHAR_H

char str_to_char(char * str);

#endif


#ifndef NON_PRINTABLE_OCTAL_H
#define NON_PRINTABLE_OCTAL_H

char * non_printable_octal(char * str);

#endif
