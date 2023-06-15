/******************************************************************************/
/* Author   : Ezzat Hegazy													                          */
/* Date     : 10 April 2023												   	                        */
/* Version  : V02	                                                  				  */
/******************************************************************************/
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "Utils.h"

#include "GPIO_config.h"
#include "GPIO_interface.h"
#include "GPIO_private.h"

uint32 GPIO_Addresses[2] = { 0x40020000, 0x40020400 };
#define GPIO_REG(REG_ID, PORT_ID) ((uint32*)((PORT_ID) + (REG_ID)))


void GPIO_voidConfigPin(uint8 PortName, uint8 PinNum, uint8 PinMode, uint8 DefaultState) 
{
    uint8 PortId = PortName - GPIO_A;
    GpioType * gpioReg =  GPIO_Addresses[PortId];

    uint8 OutputState = DefaultState & 0x1;
    uint8 InputState = DefaultState >> 1;

    gpioReg->GPIO_MODER &= ~(0x3 << (2 * PinNum));
    gpioReg->GPIO_MODER |= (PinMode << (2 * PinNum));

    gpioReg->GPIO_OTYPER  &= ~(0x01 << PinNum);
    gpioReg->GPIO_OTYPER |= (OutputState << PinNum);

    gpioReg->GPIO_PUPDR &= ~(0x3 << (2 * PinNum));
    gpioReg->GPIO_PUPDR |= (InputState << (2*PinNum));
}

void GPIO_voidWritePin(uint8 PortName, uint8 PinNum, uint8 Data) 
{
    uint8 PortId = PortName - GPIO_A;
    GpioType * gpioReg =  GPIO_Addresses[PortId];
    gpioReg->GPIO_ODR &= ~(0x01 << PinNum);
    gpioReg->GPIO_ODR |= (Data << PinNum);
}

uint8 GPIO_uint8ReadInputValue(uint8 PortName, uint8 PinNum)
{
    uint8 data = 0;
    uint8 PortId = PortName - GPIO_A;
    GpioType * gpioReg =  GPIO_Addresses[PortId];
    data = (gpioReg->GPIO_IDR & (1 << PinNum)) >> PinNum;
    return data;
}

uint8 GPIO_uint8ReadOutputValue(uint8 PortName, uint8 PinNum)
{
    uint8 data = 0;
    uint8 PortId = PortName - GPIO_A;
    GpioType * gpioReg =  GPIO_Addresses[PortId];
    data = (gpioReg->GPIO_ODR& (1 << PinNum)) >> PinNum;
    return data;  
}

