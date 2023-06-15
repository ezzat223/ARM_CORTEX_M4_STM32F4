/******************************************************************************/
/* Author   : Ezzat Hegazy													  */
/* Date     : 13 April 2023												   	  */
/* Version  : V01	                                        				  */
/******************************************************************************/
#ifndef LED_H
#define LED_H

#include"STD_TYPES.h"

void LED_voidOn(uint8 Copy_uint8Port, uint8 Copy_uint8PinNum);
void LED_voidOff(uint8 Copy_uint8Port, uint8 Copy_uint8PinNum);
void LED_voidToggle(uint8 Copy_uint8Port, uint8 Copy_uint8PinNum);


#endif
