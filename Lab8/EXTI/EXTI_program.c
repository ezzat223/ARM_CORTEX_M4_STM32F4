/******************************************************************************/
/* Author   : Ezzat Hegazy													  */
/* Date     : 18 May 2023												   	  */
/* Version  : V01															  */
/*			  V02 --> for STM32F401X	                                      */
/******************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "EXTI_interface.h"
#include "EXTI_config.h"
#include "EXTI_private.h"

#include "GPIO_interface.h"

extern uint8 Global_uint8Display;


	/* LINE & MODE*/
void MEXTI_voidInit(void) 
{
	#if   EXTI_LINE == EXTI_LINE0
		SET_BIT(EXTI -> IMR, 0);
	#elif EXTI_LINE == EXTI_LINE1
		SET_BIT(EXTI -> IMR, 1);
	#elif EXTI_LINE == EXTI_LINE2
		SET_BIT(EXTI -> IMR, 2);
	#elif EXTI_LINE == EXTI_LINE3
		SET_BIT(EXTI -> IMR, 3);
	#elif EXTI_LINE == EXTI_LINE4
		SET_BIT(EXTI -> IMR, 4);
	#elif EXTI_LINE == EXTI_LINE5
		SET_BIT(EXTI -> IMR, 5);
	#elif EXTI_LINE == EXTI_LINE6
		SET_BIT(EXTI -> IMR, 6);
	#elif EXTI_LINE == EXTI_LINE7
		SET_BIT(EXTI -> IMR, 7);
	#elif EXTI_LINE == EXTI_LINE8
		SET_BIT(EXTI -> IMR, 8);
	#elif EXTI_LINE == EXTI_LINE9
		SET_BIT(EXTI -> IMR, 9);
	#elif EXTI_LINE == EXTI_LINE10
		SET_BIT(EXTI -> IMR, 10);
	#elif EXTI_LINE == EXTI_LINE11
		SET_BIT(EXTI -> IMR, 11);
	#elif EXTI_LINE == EXTI_LINE12
		SET_BIT(EXTI -> IMR, 12);
	#elif EXTI_LINE == EXTI_LINE13
		SET_BIT(EXTI -> IMR, 13);
	#elif EXTI_LINE == EXTI_LINE14
		SET_BIT(EXTI -> IMR, 14);
	#elif EXTI_LINE == EXTI_LINE15
		SET_BIT(EXTI -> IMR, 15);
	#else
		#error ("Wrong EXTI LINE!")
	#endif


	#if   EXTI_SENSE_MODE == RISING_EDGE
	SET_BIT(EXTI -> RTSR, EXTI_LINE);
	#elif EXTI_SENSE_MODE == FALLING_EDGE
	SET_BIT(EXTI -> FTSR, EXTI_LINE);
	#elif EXTI_SENSE_MODE == ON_CHANGE
	SET_BIT(EXTI -> RTSR, EXTI_LINE);
	SET_BIT(EXTI -> FTSR, EXTI_LINE);
	#else
		#error	("Wrong EXTI MODE!")
	#endif

}

	/* Change Mode in RunTime */
void MEXTI_voidSetSignalLatch(uint8 Copy_uint8EXTILine, uint8 Copy_uint8EXTISenseMode)
{
	switch(Copy_uint8EXTISenseMode)
	{
		case RISING_EDGE		:
			SET_BIT(EXTI -> RTSR, Copy_uint8EXTILine);
			break;
		case FALLING_EDGE	:
			SET_BIT(EXTI -> FTSR, Copy_uint8EXTILine);
			break;
		case ON_CHANGE	:
			SET_BIT(EXTI -> RTSR, Copy_uint8EXTILine);
			SET_BIT(EXTI -> FTSR, Copy_uint8EXTILine);
			break;
	}
}

void MEXTI_voidEnableEXTI(uint8 Copy_uint8EXTILine)
{
	SET_BIT(EXTI -> IMR, Copy_uint8EXTILine);
}

void MEXTI_voidDisableEXTI(uint8 Copy_uint8EXTILine)
{
	CLR_BIT(EXTI -> IMR, Copy_uint8EXTILine);
}

void EXTI0_IRQHandler(void)
{
	if(Global_uint8Display < 9)
	{
		++Global_uint8Display;
	}
	else
	{
		/* Do NoThing */
	}
	
	SET_BIT(EXTI -> PR, 0);
}

void EXTI1_IRQHandler(void)
{
	if(Global_uint8Display > 0)
	{
		--Global_uint8Display;
	}
	else
	{
		/* Do NoThing */
	}

	/* Clear Pending FLAG1 as this is EXTI1 */
	/* HINT! These bits are cleared by writing 1 on them */
	SET_BIT(EXTI -> PR, 0);
}
