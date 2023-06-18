/******************************************************************************/
/* Author   : Ezzat Hegazy													                          */
/* Date     : 30 MAY 2023												   	                          */
/* Version  : V01	                                        				            */
/******************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "SPI_interface.h"

#include "TC72_config.h"
#include "TC72_interface.h"

void TC72_voidInit(void) 
{
    TC72_voidRegisterWrite(0x80, TC72_MODE);
}

void TC72_voidRegisterWrite(uint8 RegAdd, uint8 Data) 
{
    SPI1_uint8TransmitRecieveByte(RegAdd | (1 << 7));
    SPI1_uint8TransmitRecieveByte(Data);
}

void TC72_voidRegisterRead(uint8 RegAdd, uint8* DataPtr) 
{
    SPI1_uint8TransmitRecieveByte(RegAdd & (~(1 << 7)));
    *DataPtr = SPI1_uint8TransmitRecieveByte(0);
}
