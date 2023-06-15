/******************************************************************************/
/* Author   : Ezzat Hegazy													  */
/* Date     : 13 April 2023												   	  */
/* Version  : V02	                                        				  */
/******************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"

#include "RCC_config.h"
#include "GPIO_config.h"

#include "RCC_private.h"
#include "GPIO_private.h"

#include "LED.h"
#include "7_segment.h"

int main(void)
{
	/*  Initialize System Clock */
	RCC_voidEnableClock(RCC_GPIOA);
	RCC_voidEnableClock(RCC_GPIOB);

	for (uint8 i=0; i<7 ; i++)
	{
		GPIO_voidConfigPin(GPIO_B, i, GPIO_OUTPUT, OUTPUT_PUSH_PULL);
	}
	
	LED_voidOn(GPIO_A, PIN14);

	uint8 counter = 0;
	while (1)
	{
		SEVEN_SEGMENT_voidDisplyNumber(COMMON_CATHODE, counter);

		delay(1200);

		LED_voidToggle(GPIO_A, PIN14);
		delay(200);
		
		counter = (counter + 1)%10;
    }
	return 0;
}
