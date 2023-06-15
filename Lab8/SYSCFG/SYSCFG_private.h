/******************************************************************************/
/* Author   : Ezzat Hegazy													  */
/* Date     : 17 May 2023												   	  */
/* Version  : V01	                                        				  */
/******************************************************************************/
#ifndef SYSCFG_PRIVATE_H
#define SYSCFG_PRIVATE_H

#include "STD_TYPES.h"
#include "BIT_MATH.h"


typedef struct
{
    uint32 MEMRMP;
    uint32 PMC;
    uint32 EXTICR1;
    uint32 EXTICR2;
    uint32 EXTICR3;
    uint32 EXTICR4;
    uint32 RESERVED1;
    uint32 RESERVED2;
    uint32 CMPCR;
}SYSCFG_t;

#define SYSCFG ((volatile SYSCFG_t *) 0x40013800)





#endif