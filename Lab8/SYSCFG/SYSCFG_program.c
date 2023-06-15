/******************************************************************************/
/* Author   : Ezzat Hegazy													  */
/* Date     : 17 May 2023												   	  */
/* Version  : V01	                                        				  */
/******************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "SYSCFG_config.h"
#include "SYSCFG_interface.h"
#include "SYSCFG_private.h"

void SYSCFG_voidEXTISelectPortsPin(uint8 Copy_uint8EXTILine, uint8 Copy_uint8Port)
{
    uint8 Local_uint8LineNumber = Copy_uint8EXTILine % 4;
    if ((Copy_uint8EXTILine >= 0) && (Copy_uint8EXTILine <= 3))
    {
        SYSCFG->EXTICR1 &= ~(0b1111 << 4*Local_uint8LineNumber);
        SYSCFG->EXTICR1 |=  (Copy_uint8Port << 4*Local_uint8LineNumber);
    }
    else if (Copy_uint8EXTILine <= 7)
    {
        SYSCFG->EXTICR2 &= ~(0b1111 << 4*Local_uint8LineNumber);
        SYSCFG->EXTICR2 |=  (Copy_uint8Port << 4*Local_uint8LineNumber);
    }
    else if (Copy_uint8EXTILine <= 11)
    {
        SYSCFG->EXTICR3 &= ~(0b1111 << 4*Local_uint8LineNumber);
        SYSCFG->EXTICR3 |=  (Copy_uint8Port << 4*Local_uint8LineNumber);
    }
    else if (Copy_uint8EXTILine <= 15)
    {
        SYSCFG->EXTICR4 &= ~(0b1111 << 4*Local_uint8LineNumber);
        SYSCFG->EXTICR4 |=  (Copy_uint8Port << 4*Local_uint8LineNumber);
    }
    else
    {
        /* Generate Error */
    }
}
