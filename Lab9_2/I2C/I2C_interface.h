/******************************************************************************/
/* Author   : Ezzat Hegazy													  */
/* Date     : 31 MAY 2023												   	  */
/* Version  : V01	                                        				  */
/******************************************************************************/
#ifndef I2C_INTERFACE_H
#define I2C_INTERFACE_H

#include "STD_TYPES.h"

#define ACK  1
#define NACK 0

void I2C1_voidInit (void);
void I2C1_voidStart(void);
void I2C1_voidStop (void);

void I2C1_voidMasterTxAddr      (uint8 SlaveAddr);
void I2C1_voidMasterTxSingleData(uint8 Data);
void I2C1_voidMasterTxMultiData (uint8 DataPtr[], uint32 Size);
void I2C1_voidMasterRxMulti     (uint8 SlaveAddr, uint8 * Buffer, uint32 Size);


#endif /* I2C_INTERFACE_H */
