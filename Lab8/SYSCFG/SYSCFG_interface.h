/******************************************************************************/
/* Author   : Ezzat Hegazy													  */
/* Date     : 09 May 2023												   	  */
/* Version  : V01	                                        				  */
/******************************************************************************/
#ifndef SYSCFG_INTERFACE_H
#define SYSCFG_INTERFACE_H

#include "STD_TYPES.h"
#include "BIT_MATH.h"

void SYSCFG_voidEXTISelectPortsPin(uint8 Copy_uint8EXTILine, uint8 Copy_uint8Port);

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

		/* Define Ports */
#define SYSCFG_GPIO_A  0b0000
#define SYSCFG_GPIO_B  0b0001
#define SYSCFG_GPIO_C  0b0010
#define SYSCFG_GPIO_D  0b0011
#define SYSCFG_GPIO_E  0b0100


#endif