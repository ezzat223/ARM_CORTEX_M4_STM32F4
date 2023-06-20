/******************************************************************************/
/* Author   : Ezzat Hegazy													                          */
/* Date     : 31 MAY 2023												   	                          */
/* Version  : V01	                                        				            */
/******************************************************************************/
#include "stm32f4xx.h"
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Utils.h"

#include "I2C_config.h"
#include "I2C_interface.h"
#include "I2C_private.h"

#include "GPIO_interface.h"
#include "RCC_interface.h"

#define I2C1_AF_EN()  (GPIOB -> AFR[0] |= (0x44 << (6 * 4)))

#define I2C1_START_GEN()   (I2C1_CR1 |=  I2C_CR1_START_Msk)
#define I2C1_STOP_GEN()    (I2C1_CR1 |=  I2C_CR1_STOP_Msk)
#define I2C1_MASTER_ACK()  (I2C1_CR1 |=  (I2C_CR1_ACK_Msk))
#define I2C1_MASTER_NACK() (I2C1_CR1 &= ~(I2C_CR1_ACK_Msk))

void I2C1_voidInit(void) 
{
    RCC_voidEnableClock(RCC_I2C1);

        /* B6, B7 as AF --> OPEN_DRAIN */
    GPIO_voidConfigPin(GPIO_B, 6, GPIO_AF, GPIO_OPEN_DRAIN);
    GPIO_voidConfigPin(GPIO_B, 7, GPIO_AF, GPIO_OPEN_DRAIN);

        /* B6, B7 --> I2C1 */
    I2C1_AF_EN();

        /* Disable I2C1 */
    I2C1_CR1 &= ~(I2C_CR1_PE_Msk);

    /* Standard mode 2MHZ Peripheral freq */
    I2C1_CR2 &= ~(I2C_CR2_FREQ_Msk);
    I2C1_CR2 |= 16;

      /*      CCR -> F/S (Frequency ut of I2C to SCL)
          SM--> 100KHZ
          FM--> 400KHZ
      */
    /* 100 KHz  master clk*/
    I2C1_CCR = 0;
    I2C1_CCR |= 80;

    /* Sm mode, the maximum allowed SCL rise time is 1000 ns. */
    I2C1_TRISE = 17;

    /* Enable Interrupt */
    //   I2C1_CR2 |= I2C_CR2_ITEVTEN_Msk;
    //   I2C1_CR2 |= I2C_CR2_ITBUFEN_Msk;
    //   NVIC_ISER0 = (1 << 31);

    /* Enable I2C1 */
    I2C1_CR1 |= I2C_CR1_PE_Msk;
}

void I2C1_voidStart(void) 
{
  I2C1_START_GEN();
  while (!(I2C1 -> SR1 & I2C_SR1_SB_Msk));
}

void I2C1_voidStop(void) 
{
  I2C1_STOP_GEN();
  while (!(I2C1 -> SR1 & I2C_SR1_STOPF_Msk));
}
void I2C1_voidMasterTxAddr(uint8 SlaveAddr) 
{
  I2C1->DR = SlaveAddr;
  while (!(I2C1->SR1 & I2C_SR1_ADDR_Msk));

  /* Flag cleared by reading two registers */
  I2C1->SR1;
  I2C1->SR2;
}

void I2C1_voidMasterTxSingleData(uint8 Data) 
{
  while (!(I2C1->SR1 & I2C_SR1_TXE_Msk));
  I2C1->DR = Data;
  while (!(I2C1->SR1 & I2C_SR1_BTF_Msk));
}

void I2C1_voidMasterTxMultiData(uint8 DataPtr[], uint32 Size) 
{
  while (!(I2C1->SR1 & I2C_SR1_TXE_Msk));
  while (Size) 
  {
    while (!(I2C1->SR1 & I2C_SR1_TXE_Msk));
    I2C1 -> DR = *DataPtr;
    DataPtr++;
    Size--;
  }
  while (!(I2C1->SR1 & I2C_SR1_BTF_Msk));
}



void I2C1_voidMasterRxMulti(uint8 SlaveAddr, uint8* Buffer, uint32 Size)
{
  I2C1 -> DR = SlaveAddr;

  while (!(I2C1->SR1 & I2C_SR1_ADDR_Msk));
  /* Flag cleared by reading two registers */
  I2C1->SR1;
  I2C1->SR2;

  if (Size == 1) 
  {
      I2C1->CR1 &= ~(I2C_CR1_ACK_Msk);

      I2C1_STOP_GEN();
      while (!(I2C1->SR1 & I2C_SR1_RXNE_Msk));

      *Buffer = I2C1->DR;
  } 
  else 
  {
      while(Size > 2) 
      {
        while (!(I2C1->SR1 & I2C_SR1_RXNE_Msk));

        *Buffer = I2C1->DR;
        Buffer++;
        Size--;
      }
      /* Size == 2 */
      while (!(I2C1->SR1 & I2C_SR1_RXNE_Msk));

      *Buffer = I2C1->DR;
      Buffer++;
      Size--;

      I2C1->CR1 &= ~(I2C_CR1_ACK_Msk);
      I2C1_STOP_GEN();
      while (!(I2C1->SR1 & I2C_SR1_RXNE_Msk));
      *Buffer = I2C1->DR;
  }
}
