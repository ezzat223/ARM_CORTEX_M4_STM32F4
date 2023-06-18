/******************************************************************************/
/* Author   : Ezzat Hegazy													  */
/* Date     : 10 April 2023												   	  */
/* Version  : V02	                                        				  */
/******************************************************************************/
#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H

#include "STD_TYPES.h"

		/* PORT Name */
#define GPIO_A 'A'
#define GPIO_B 'B'
#define GPIO_C 'C'
#define GPIO_D 'D'

		/* PIN Mode */
#define GPIO_INPUT  0x00
#define GPIO_OUTPUT 0x01
#define GPIO_AF     0x02
#define GPIO_ANALOG 0x03

			/* Default State */
/* OUTPUT type (OTYPER) */
#define GPIO_PUSH_PULL  0
#define GPIO_OPEN_DRAIN 1

/* INPUT type (PUPDR) */
#define GPIO_NO_PULL		(0x00 << 1)	
#define GPIO_PULL_UP		(0x01 << 1)
#define GPIO_PULL_DOWN		(0x02 << 1)


		/* Data */
#define LOW  0x00
#define HIGH 0x01

		/* Define PIN_S */
#define		PIN0	0
#define		PIN1	1
#define		PIN2	2
#define		PIN3	3
#define		PIN4	4
#define		PIN5	5
#define		PIN6	6
#define		PIN7	7
#define		PIN8	8
#define		PIN9	9
#define		PIN10	10
#define		PIN11	11
#define		PIN12	12
#define		PIN13	13
#define		PIN14	14
#define		PIN15	15

					/* APIs */
void  GPIO_voidConfigPin       (uint8 PortName, uint8 PinNum, uint8 PinMode, uint8 DefaultState);
void  GPIO_voidWritePin        (uint8 PortName, uint8 PinNum, uint8 Data)						;
uint8 GPIO_uint8ReadInputValue (uint8 PortName, uint8 PinNum)									;
uint8 GPIO_uint8ReadOutputValue(uint8 PortName, uint8 PinNum)									;

#endif /* GPIO_PRIVATE_H */
