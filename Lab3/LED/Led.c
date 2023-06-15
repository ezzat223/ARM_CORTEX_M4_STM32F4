/******************************************************************************/
/* Author   : Ezzat Hegazy													  */
/* Date     : 14 April 2023												   	  */
/* Version  : V02	                                        				  */
/******************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "LED.h"
#include "RCC_interface.h"
#include "GPIO_interface.h"

void LED_voidOn(uint8 Copy_uint8Port, uint8 Copy_uint8PinNum)
{

    GPIO_voidConfigPin(Copy_uint8Port, Copy_uint8PinNum, GPIO_OUTPUT, OUTPUT_PUSH_PULL);
    GPIO_voidWritePin(Copy_uint8Port, Copy_uint8PinNum, HIGH);
}


void LED_voidOff(uint8 Copy_uint8Port, uint8 Copy_uint8PinNum)
{
	GPIO_voidWritePin(Copy_uint8Port, Copy_uint8PinNum, LOW);
}


void LED_voidToggle(uint8 Copy_uint8Port, uint8 Copy_uint8PinNum)
{
    uint8 state = GPIO_uint8ReadOutputValue(Copy_uint8Port, Copy_uint8PinNum);
    switch (state)
    {
    case 1:
        LED_voidOff(Copy_uint8Port, Copy_uint8PinNum);
        break;
    case 0:
        LED_voidOn(Copy_uint8Port, Copy_uint8PinNum);
        break;
    default:
        break;
    }
}
