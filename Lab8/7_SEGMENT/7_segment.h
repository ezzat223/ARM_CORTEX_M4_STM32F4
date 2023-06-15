/******************************************************************************/
/* Author   : Ezzat Hegazy													  */
/* Date     : 13 April 2023												   	  */
/* Version  : V01	                                        				  */
/******************************************************************************/
#ifndef SEVEN_SEGMENT_H
#define SEVEN_SEGMENT_H

#include "STD_TYPES.h"

#define COMMON_CATHODE      1
#define COMMON_ANODE        0

void SEVEN_SEGMENT_voidDisplyNumber(uint8 Copy_uint8CommonType, uint8 Copy_uint8Number);

#endif