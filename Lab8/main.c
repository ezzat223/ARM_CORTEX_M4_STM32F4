/******************************************************************************/
/* Author   : Ezzat Hegazy													  */
/* Date     : 18 May 2023												   	  */
/* Version  : V01															  */
/*			  V02 --> Race Condition	                                      */
/******************************************************************************/
#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "EXTI_interface.h"
#include "SYSCFG_interface.h"
#include "7_SEGMENT.h"


#define NVIC_ISER0 (*(uint32 *) 0xE000E100)

uint8 Global_uint8Display;

int main(void) 
{
	RCC_voidInitSysClock();
	RCC_voidEnableClock(RCC_GPIOA);
	RCC_voidEnableClock(RCC_GPIOB);
	RCC_voidEnableClock(RCC_SYSCFG);

	MEXTI_voidInit();

	SYSCFG_voidEXTISelectPortsPin(EXTI_LINE0, SYSCFG_GPIO_A);
	SYSCFG_voidEXTISelectPortsPin(EXTI_LINE1, SYSCFG_GPIO_A);

	MEXTI_voidSetSignalLatch(EXTI_LINE1, FALLING_EDGE);
	MEXTI_voidEnableEXTI(EXTI_LINE1);

	/* Enable EXTI0 & EXTI1 on NVIC as their position is 6 & 7 */
	/* Look at NVIC tables in Ref manual */
	SET_BIT(NVIC_ISER0, 6); 
	SET_BIT(NVIC_ISER0, 7);  

	for(uint8 i=0; i<7; i++)
	{
		GPIO_voidConfigPin(GPIO_B, i, GPIO_OUTPUT, OUTPUT_PUSH_PULL);
	}

	/* For Race Condition */
	uint8 LocalData = 0;

	while (1)
	{
		/* Critical section for Race condition */
		MEXTI_voidDisableEXTI(EXTI_LINE0);
		MEXTI_voidDisableEXTI(EXTI_LINE1);

		LocalData = Global_uint8Display;

		MEXTI_voidEnableEXTI(EXTI_LINE0);
		MEXTI_voidEnableEXTI(EXTI_LINE1);

		SEVEN_SEGMENT_voidDisplyNumber(COMMON_CATHODE, Global_uint8Display);
	}
	return 0;
}
