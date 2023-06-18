/******************************************************************************/
/* Author   : Ezzat Hegazy													  */
/* Date     : 30 MAY 2023												   	  */
/* Version  : V01	                                        				  */
/******************************************************************************/
#ifndef SPI_INTERFACE_H
#define SPI_INTERFACE_H

#include "STD_TYPES.h"

typedef struct 
{
    uint32 CR1;
    uint32 UNUSED;
    uint32 SR;
    uint32 DR;
    uint32 CRCPR;
    uint32 RXCRCR;
    uint32 TXCRCR;
    uint32 I2SCFGR;
    uint32 I2SPR;
}SpiType;


void  SPI1_voidInit(void);
uint8 SPI1_uint8TransmitRecieveByte(uint8 TxData);

#endif /* SPI_INTERFACE_H */