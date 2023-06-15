/******************************************************************************/
/* Author   : Ezzat Hegazy													  */
/* Date     : 04 May 2023												   	  */
/* Version  : V01	                                        				  */
/******************************************************************************/
#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H

#include "STD_TYPES.h"
#include "BIT_MATH.h"


void MEXTI_voidInit(void); // Line & Mode
void MEXTI_voidSetSignalLatch(uint8 Copy_uint8EXTILine, uint8 Copy_uint8SenseMode); //MODE(RISING, FALLING, ON_CHANGE)
void MEXTI_voidEnableEXTI(uint8 Copy_uint8EXTILine);
void MEXTI_voidDisableEXTI(uint8 Copy_uint8EXTILine);



#define		EXTI_LINE0		0
#define		EXTI_LINE1		1
#define		EXTI_LINE2		2
#define		EXTI_LINE3		3
#define		EXTI_LINE4		4
#define		EXTI_LINE5		5
#define		EXTI_LINE6		6
#define		EXTI_LINE7		7
#define		EXTI_LINE8		8
#define		EXTI_LINE9		9
#define		EXTI_LINE10		10
#define		EXTI_LINE11		11
#define		EXTI_LINE12		12
#define		EXTI_LINE13		13
#define		EXTI_LINE14		14
#define		EXTI_LINE15		15


#define		RISING_EDGE		    0
#define		FALLING_EDGE		1
#define		ON_CHANGE			2



#endif 