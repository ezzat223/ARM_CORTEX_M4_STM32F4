/******************************************************************************/
/* Author   : Ezzat Hegazy													  */
/* Date     : 6 May 2023												   	  */
/* Version  : V02	                                        				  */
/******************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "7_SEGMENT.h"
#include "KEYPAD_interface.h"

uint8 key = RELEASED;

int main(void)
{
	RCC_voidInitSysClock();
	RCC_voidEnableClock(RCC_GPIOA);
	RCC_voidEnableClock(RCC_GPIOB);

	for(uint8 i=0; i<7; i++)
	{
		GPIO_voidConfigPin(GPIO_A, i, GPIO_OUTPUT, OUTPUT_PUSH_PULL);
	}

	KEYPAD_voidInit();

	while (1)
	{
		KEYPAD_voidManage();
		delay(100);
	}
	return 0;
}

void KEYPAD_voidCallOut_KeyPressNotification(void)
{
	uint8 local_key =  KEYPAD_uint8GetKey();
	SEVEN_SEGMENT_voidDisplyNumber(COMMON_CATHODE, local_key);
}


