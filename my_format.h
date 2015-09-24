/*******************************************************************************
*
* File Name         : my_format.h
* Created By        : arn0f
* Creation Date     : septembre  2th, 2015
* Last Change       : septembre 22th, 2015 at 23:22:12
* Last Changed By   : arn0f
* Purpose           : That file contain all the prototypes of the functions 
* 			defined in the file 'my_format.c'
*
*******************************************************************************/

#ifndef FORMAT_H
#define FORMAT_H

char * format_chain(char * str, char * flag, int width, char type, char * spe, int spe_size);

#endif


#ifndef GENERATE_PADDED_CHAIN_H
#define GENERATE_PADDED_CHAIN_H

char * generate_padded_chain(char * str, int left, char pad, int width);

#endif


#ifndef GENERATE_SPACE_H
#define GENERATE_SPACE_H

char * generate_space(char pad, int width);

#endif