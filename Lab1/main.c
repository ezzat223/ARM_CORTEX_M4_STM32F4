/******************************************************************************/
/* Author   : Ezzat Hegazy													  */
/* Date     : 15 April 2023												   	  */
/* Version  : V02	                                        				  */
/******************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"

#include "LED.h"

int main(void)
{
	/*  Initialize System Clock */
	RCC_voidEnableClock(RCC_GPIOB);
	
	GPIO_voidConfigPin(GPIO_B, PIN3, GPIO_INPUT, INPUT_PULL_UP);


	GPIO_voidConfigPin(GPIO_B, PIN5, GPIO_OUTPUT, OUTPUT_PUSH_PULL);
	GPIO_voidWritePin(GPIO_B, PIN5, LOW);

	GPIO_voidConfigPin(GPIO_B, PIN6, GPIO_OUTPUT, OUTPUT_PUSH_PULL);
	GPIO_voidWritePin(GPIO_B, PIN6, LOW);

	GPIO_voidConfigPin(GPIO_B, PIN7, GPIO_OUTPUT, OUTPUT_PUSH_PULL);
	GPIO_voidWritePin(GPIO_B, PIN7, LOW);

	uint16 w=100;
	uint16 mux = 0;
	uint8 current_state=1;
	uint8 prev_state=1;

	while (1)
	{
		// Read Button
		current_state = GPIO_uint8ReadInputValue(GPIO_B, PIN3);

		// If Button is Pressed
		if((current_state==0) && (prev_state==1))
		{
			// Delay to make sure it wasn't noise
			for (uint16 i = 0; i < w; i++)
			{
				for (uint16 j = 0; j < w; j++)
				{
					/* Assembly order No OPeration */
					asm("NOP");
				}
			}

			current_state = GPIO_uint8ReadInputValue(GPIO_B, PIN3);

			// If still Pressed so wasn't Noise
			if(current_state == 0)
			{
				mux = (++mux)%8;
				prev_state=0;
			}
		}

		GPIO_voidWritePin(GPIO_B, PIN5, GET_BIT(mux, 0));
		GPIO_voidWritePin(GPIO_B, PIN6, GET_BIT(mux, 1));
		GPIO_voidWritePin(GPIO_B, PIN7, GET_BIT(mux, 2));

		if(current_state==1)
		{
			prev_state=1;
		}
	}
	return 0;
}
