/******************************************************************************/
/* Author   : Ezzat Hegazy						                  */
/* Date     : 30 MAY 2023									*/
/* Version  : V01	                                        			      */
/******************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Utils.h"

#include "USART_interface.h"

#include "stm32f401xe.h"
#include "GPIO_interface.h"


void USART2_voidInit(void) 
{
          /* Config Pins as AF */
    GPIO_voidConfigPin(GPIO_A, 2, GPIO_AF, GPIO_PUSH_PULL);
    GPIO_voidConfigPin(GPIO_A, 3, GPIO_AF, GPIO_PUSH_PULL);

         /* Config Pins as USART2 */
    GPIOA->AFR[0] &= ~(0xff << 4 * 2);
    GPIOA->AFR[0] |= 0x77 << 4 * 2;

          /* Word Length --> 8bit */
    USART2->CR1 &= ~(1 << USART_CR1_M_Pos);

          /* STOP Bits --> 1 */
    USART2->CR2 &= ~(USART_CR2_STOP);

          /* Oversampling --> 16 */
    USART2->CR1 &= ~(1 << USART_CR1_OVER8_Pos);

          /* Baud Rate --> 9600 */
    USART2->BRR = 0x683;

          /* Enable Transmission block */
    USART2->CR1 |= (1 << USART_CR1_TE_Pos);

          /* Enable Receive block */
    USART2->CR1 |= (1 << USART_CR1_RE_Pos);

          /* Enable USART2 */
    USART2->CR1 |= (1 << USART_CR1_UE_Pos);
}

uint8 USART2_uint8TransmintByte(uint8 Byte)
{
    if (USART2->SR & USART_SR_TXE) 
    {
      USART2->DR = Byte;
      while (!(USART2->SR & USART_SR_TC));
          /* Clearing TC bit */
      USART2->SR &= ~(1 << USART_SR_TC_Pos);
      return OK;
    }
    return NOK;
}

uint8 USART2_uint8RecieveByte(void)
{
    while (!(USART2->SR & USART_SR_RXNE));
    return USART2->DR;
}

void USART2_voidTransmitString(const char* Str)
{
    uint32 i = 0;
    uint8 transmitResult = -1;
    while (Str[i] != '\0') 
    {
        transmitResult = USART2_uint8TransmintByte(Str[i]);
        if(transmitResult == OK)
        {
          i++;
        }
    }
}
