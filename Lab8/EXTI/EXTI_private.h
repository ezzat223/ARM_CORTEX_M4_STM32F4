/******************************************************************************/
/* Author   : Ezzat Hegazy													  */
/* Date     : 017 May 2023												   	  */
/* Version  : V01	                                        				  */
/******************************************************************************/
#ifndef EXIT_PRIVATE_H
#define EXTI_PRIVATE_H

#include "STD_TYPES.h"
#include "BIT_MATH.h"


typedef struct
{
	uint32 IMR  ;
	uint32 EMR  ;
	uint32 RTSR ;
	uint32 FTSR ;
	uint32 SWIER;
	uint32 PR   ;
	
}EXTI_t;

#define EXTI ((volatile EXTI_t *) 0x40013C00)


#endif