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

#include "SPI_interface.h"
#include "TC72_interface.h"
#include "USART_interface.h"


			/* Which to operate? */
// #define Lab9_USART

#define TC72_SELECT()   (GPIO_voidWritePin(GPIO_B, 0, 1))
#define TC72_UNSELECT() (GPIO_voidWritePin(GPIO_B, 0, 0))

void floatToStr(float val, char data[]);

int main(void) 
{
#if defined(Lab9_USART)
	RCC_voidInitSysClock();
	RCC_voidEnableClock(RCC_GPIOA);
	RCC_voidEnableClock(RCC_USART2);
	USART2_voidInit();
	uint8 data = 0;
	while(1)
	{
		data = USART2_uint8RecieveByte();
		if(data == '1')
		{
			USART2_voidTransmitString("Hello\r\n");
		}
		if(data == '2')
		{
			USART2_voidTransmitString("Welcome\r\n");
		}
	}
#else // Clear line 11 to enable SPI code
	char usart2Data[] = { '-', ' ', ' ', '.', ' ', ' ', '\r', '\n', '\0' };
	uint8 spiData = 0;
	float32 temperature = 0;

	RCC_voidInitSysClock();
	RCC_voidEnableClock(RCC_GPIOA);
	RCC_voidEnableClock(RCC_GPIOB);
	RCC_voidEnableClock(RCC_SPI1);
	RCC_voidEnableClock(RCC_USART2);

	/* Slave Select */
	GPIO_voidConfigPin(GPIO_B, 0, GPIO_OUTPUT , GPIO_PUSH_PULL);
	GPIO_voidWritePin(GPIO_B, 0, 0);


	USART2_voidInit();
	SPI1_voidInit();

	TC72_SELECT();
	TC72_voidInit();
	TC72_UNSELECT();

	while (1) 
	{
		temperature = 0.0f;
		TC72_SELECT();
		TC72_voidRegisterRead(0x01, &spiData);
		TC72_UNSELECT();

		if (spiData & (1 << 7)) 
		{
			temperature += 0.5f;
		}
		if (spiData & (1 << 6)) 
		{
			temperature += 0.25f;
		}

		TC72_SELECT();
		TC72_voidRegisterRead(0x02, &spiData);
		TC72_UNSELECT();

		temperature += (signed char) spiData;

		/* we want to printf "13.5" how?? */
		floatToStr(temperature, usart2Data);  

		USART2_voidTransmitString(usart2Data);

		/* Delay */
		delay(500);
	}
#endif
	return 0;
}

void floatToStr(float val, char data[]) 
{
	if (val < 0) 
	{
		*data = '-';
		data++;
		val *= -1;
	}
	int intVal = val * 100;
	data[4] = (intVal % 10) + '0';
	intVal /= 10;
	data[3] = (intVal % 10) + '0';
	data[2] = '.';
	intVal /= 10;
	data[1] = (intVal % 10) + '0';
	intVal /= 10;
	data[0] = (intVal % 10) + '0';

	data[5] = '\r';
	data[6] = '\n';
	data[7] = '\0';
}
