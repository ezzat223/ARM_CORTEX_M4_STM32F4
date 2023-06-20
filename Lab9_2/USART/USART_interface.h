/******************************************************************************/
/* Author   : Ezzat Hegazy													  */
/* Date     : 30 MAY 2023												   	  */
/* Version  : V01	                                        				  */
/******************************************************************************/
#ifndef USART_INTERFACE_H
#define USART_INTERFACE_H

#include "STD_TYPES.h"
#include "BIT_MATH.h"

void USART2_voidInit(void);

uint8 USART2_uint8TransmintByte(uint8 Byte);

uint8 USART2_uint8RecieveByte(void);

void USART2_voidTransmitString(const char* Str);

#endif /* USART_INTERFACE_H */