/******************************************************************************/
/* Author   : Ezzat Hegazy													  */
/* Date     : 13 April 2023												   	  */
/* Version  : V01	                                        				  */
/******************************************************************************/
#include"STD_TYPES.h"

#ifndef LED_H
#define LED_H


void LED_voidOn(uint8 Copy_uint8Port, uint8 Copy_uint8PinNum);
void LED_voidOff(uint8 Copy_uint8Port, uint8 Copy_uint8PinNum);
void LED_voidToggle(uint8 Copy_uint8Port, uint8 Copy_uint8PinNum);


#endif