/******************************************************************************/
/* Author   : Ezzat Hegazy													                          */
/* Date     : 30 MAY 2023												   	                          */
/* Version  : V02	                                                  				  */
/******************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "stm32f4xx.h"

#include "GPIO_interface.h"
#include "GPIO_private.h"

#include "SPI_config.h"
#include "SPI_interface.h"


#define GPIOA_P ((GpioType*) (GPIOA_BASE_ADDR))
#define SPI1_AF_EN() (GPIOA_P ->AFRL |= (0x555 << (5 * 4)))
#define SPI1 ((SpiType *)0x40013000)


void SPI1_voidInit(void) 
{
                /* Config Pins as AF */
    GPIO_voidConfigPin(GPIO_A, 5, GPIO_AF , GPIO_PUSH_PULL);
    GPIO_voidConfigPin(GPIO_A, 6, GPIO_AF , GPIO_PUSH_PULL);
    GPIO_voidConfigPin(GPIO_A, 7, GPIO_AF , GPIO_PUSH_PULL);

                /* Config Pins as SPI */
    SPI1_AF_EN();


    SPI1->CR1 |= (0x3 << SPI_CR1_SSI_Pos);

                /* MASTER OR SLAVE */
    SPI1->CR1 &= ~(1 << SPI_CR1_MSTR_Pos);
    SPI1->CR1 |= (MASTER_OR_SLAVE << SPI_CR1_MSTR_Pos);

                /* CPOL */
    SPI1->CR1 &= ~(1 << SPI_CR1_CPOL_Pos);
    SPI1->CR1 |= (CPOL << SPI_CR1_CPOL_Pos);

                /* CPHA */
    SPI1->CR1 &= ~(1 << SPI_CR1_CPHA_Pos);
    SPI1->CR1 |= (CPHA << SPI_CR1_CPHA_Pos);

    /*************************************************************************/
                    /* Baud Rate */
    SPI1->CR1 &= ~(0x7 << SPI_CR1_BR_Pos);
    SPI1->CR1 |= (0x3 << SPI_CR1_BR_Pos);  // 16/16 -> 1MHZ
    /*************************************************************************/

                  /* SPI Enable */
    SPI1->CR1 |= (1 << SPI_CR1_SPE_Pos);
}

uint8 SPI1_uint8TransmitRecieveByte(uint8 TxData) 
{
    /* Transmit buffer is Empty */
    if(SPI1->SR & (1 << SPI_SR_TXE_Pos)) 
    {
      SPI1->DR = TxData;
      /* Delay till not BUSY -> Transmission is COMPLETE */
      while (SPI1->SR & (1 << SPI_SR_BSY_Pos));
      /* Return Received Data */
      return SPI1->DR;
    }
    /* Incase of FAILURE */
    return -1;
}
