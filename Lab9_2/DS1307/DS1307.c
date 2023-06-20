/******************************************************************************/
/* Author   : Ezzat Hegazy													  */
/* Date     : 30 MAY 2023												   	  */
/* Version  : V01	                                        				  */
/******************************************************************************/
#include "I2C_interface.h"

void RTC_Init(void) 
{
    I2C1_voidStart();   
    I2C1_voidMasterTxAddr(0xD0);
    /* Set Register Pointer to 0x07 */
    I2C1_voidMasterTxSingleData(0x07); 
    I2C1_voidMasterTxSingleData(0x00);
    I2C1_voidStop(); 
}

void RTC_GetTime(unsigned char *h, unsigned char *m, unsigned char *s) 
{
    I2C1_voidStart();   
    I2C1_voidMasterTxAddr(0xD0);
    /* Set Register Pointer to 0 */
    I2C1_voidMasterTxSingleData(0x00);
    I2C1_voidStop();

    /* Read Time Data */
    I2C1_voidStart();   
    I2C1_voidMasterTxAddr(0xD0);
    I2C1_voidMasterRxMulti(0x00, s, 1);
    I2C1_voidMasterRxMulti(0x01, m, 1);
    I2C1_voidMasterRxMulti(0x02, h, 1);
    I2C1_voidStop();
}

void RTC_SetTime(unsigned char Buffer[]){
}