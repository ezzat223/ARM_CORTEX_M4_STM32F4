/******************************************************************************/
/* Author   : Ezzat Hegazy													  */
/* Date     : 28 April 2023												   	  */
/* Version  : V01	                                        				  */
/******************************************************************************/
#ifndef KEYPAD_CONFIG_H
#define	KEYPAD_CONFIG_H

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"

/* Columns pins */
#define COL_PORT            GPIO_B
#define COL_START_INDEX     0
#define COL_END_INDEX       2


/* Rows pins */
#define ROW_PORT            GPIO_B
#define ROW_START_INDEX     7
#define ROW_END_INDEX       10



#endif
