/******************************************************************************/
/* Author   : Ezzat Hegazy													  */
/* Date     : 30 MAY 2023												   	  */
/* Version  : V01	                                        				  */
/******************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Utils.h"

#include "GPIO_interface.h"
#include "RCC_interface.h"

#include "I2C_interface.h"
#include "DS1307_interface.h"
#include "USART_interface.h"


#define CHAR(x)  ((x) + '0')

void timeToStr(uint8 time[], sint8 data[]);



int main(void) 
{
	RCC_voidInitSysClock();
	RCC_voidEnableClock(RCC_GPIOA);
	RCC_voidEnableClock(RCC_GPIOB);
	RCC_voidEnableClock(RCC_USART2);
	sint8 usart2TimeData[] = {' ', ' ', ':', ' ', ' ', ':',' ', ' ', '\r', '\n', '\0'};
	uint8 buffer[3] = {0};
	

	USART2_voidInit();
	I2C1_voidInit();
	RTC_Init();


	while (1) 
	{
		RTC_GetTime(&buffer[0], &buffer[1], &buffer[2]);
		timeToStr(buffer, usart2TimeData);
		USART2_voidTransmitString(usart2TimeData);
	}

	return 0;
}
void timeToStr(uint8 time[], sint8 data[])
{
	data[0] = CHAR((time[0]) >> 4);
	data[1] = CHAR((time[0]) & 0x0F);

	data[3] = CHAR((time[1]) >> 4);
	data[4] = CHAR((time[1]) & 0x0F);

	data[6] = CHAR((time[3]) >> 4);
	data[7] = CHAR((time[3]) & 0x0F);
}
