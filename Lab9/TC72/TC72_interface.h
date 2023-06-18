/******************************************************************************/
/* Author   : Ezzat Hegazy													  */
/* Date     : 30 MAY 2023												   	  */
/* Version  : V01	                                        				  */
/******************************************************************************/
#ifndef TC72_INTERFACE_H
#define TC72_INTERFACE_H

#include "STD_TYPES.h"
#include "BIT_MATH.h"

void TC72_voidInit(void);

void TC72_voidRegisterWrite(uint8 RegAdd, uint8 Data);

void TC72_voidRegisterRead(uint8 RegAdd, uint8 * DataPtr);

#endif /* TC72_INTERFACE_H */