/******************************************************************************/
/* Author   : Ezzat Hegazy						    						  */
/* Date     : 10 April 2023		          			     					  */
/* Version  : V02	                                        			      */
/******************************************************************************/
#ifndef GPIO_PRIVATE_H
#define GPIO_PRIVATE_H

#include "STD_TYPES.h"
#include "Utils.h"

#define GPIOA_BASE_ADDR    0x40020000
#define GPIOB_BASE_ADDR    0x40020400

typedef struct 
{
	uint32 MODER;
	uint32 OTYPER;
	uint32 OSPEEDR;
	uint32 PUPDR;
	uint32 IDR;
	uint32 ODR;
	uint32 BSRR;
	uint32 LCKR;
	uint32 AFRL;
	uint32 AFRH;
} GpioType;

#endif /* GPIO_PRIVATE_H */