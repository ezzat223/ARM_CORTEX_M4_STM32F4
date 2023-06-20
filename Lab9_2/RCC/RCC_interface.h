/******************************************************************************/
/* Author   : Ezzat Hegazy			        		      */
/* Date     : 12 April 2023						      */
/* Version  : V02                                                             */
/******************************************************************************/
#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H

#include "STD_TYPES.h"

typedef uint8 Rcc_PeripheralIdType;

        /* Define BUS-es	*/
#define RCC_AHB1 0UL
#define RCC_AHB2 1UL
#define RCC_APB1 2UL
#define RCC_APB2 3UL

        /* Define AHB1 Peripherals */
#define RCC_GPIOA           (Rcc_PeripheralIdType)(RCC_AHB1*32 + 0UL)
#define RCC_GPIOB           (Rcc_PeripheralIdType)(RCC_AHB1*32 + 1UL)
#define RCC_GPIOC           (Rcc_PeripheralIdType)(RCC_AHB1*32 + 2UL)
#define RCC_GPIOD           (Rcc_PeripheralIdType)(RCC_AHB1*32 + 3UL)
#define RCC_GPIOE           (Rcc_PeripheralIdType)(RCC_AHB1*32 + 4UL)
#define RCC_GPIOH           (Rcc_PeripheralIdType)(RCC_AHB1*32 + 7UL)
#define RCC_CRC             (Rcc_PeripheralIdType)(RCC_AHB1*32 + 2UL)
#define RCC_DMA1            (Rcc_PeripheralIdType)(RCC_AHB1*32 + 21UL)
#define RCC_DMA2            (Rcc_PeripheralIdType)(RCC_AHB1*32 + 22UL)

        /* Define AHB2 Peripherals */
#define RCC_OTGFS           (Rcc_PeripheralIdType)(RCC_AHB2*32 + 7UL)

        /* Define APB1 Peripherals */
#define RCC_TIM2            (Rcc_PeripheralIdType)(RCC_APB1*32 + 0UL)
#define RCC_TIM3            (Rcc_PeripheralIdType)(RCC_APB1*32 + 1UL)
#define RCC_TIM4            (Rcc_PeripheralIdType)(RCC_APB1*32 + 2UL)
#define RCC_TIM5            (Rcc_PeripheralIdType)(RCC_APB1*32 + 3UL)
#define RCC_WWDG            (Rcc_PeripheralIdType)(RCC_APB1*32 + 11UL)
#define RCC_SPI2            (Rcc_PeripheralIdType)(RCC_APB1*32 + 14UL)
#define RCC_SPI3            (Rcc_PeripheralIdType)(RCC_APB1*32 + 15UL)
#define RCC_USART2          (Rcc_PeripheralIdType)(RCC_APB1*32 + 17UL)
#define RCC_I2C1            (Rcc_PeripheralIdType)(RCC_APB1*32 + 21UL)
#define RCC_I2C2            (Rcc_PeripheralIdType)(RCC_APB1*32 + 22UL)
#define RCC_I2C3            (Rcc_PeripheralIdType)(RCC_APB1*32 + 23UL)
#define RCC_PWR             (Rcc_PeripheralIdType)(RCC_APB1*32 + 28UL)

        /* Define APB2 Peripherals */
#define RCC_TIM1            (Rcc_PeripheralIdType)(RCC_APB2*32 + 0UL)
#define RCC_USART1          (Rcc_PeripheralIdType)(RCC_APB2*32 + 4UL)
#define RCC_USART6          (Rcc_PeripheralIdType)(RCC_APB2*32 + 5UL)
#define RCC_ADC1            (Rcc_PeripheralIdType)(RCC_APB2*32 + 8UL)
#define RCC_SDIO            (Rcc_PeripheralIdType)(RCC_APB2*32 + 11UL)
#define RCC_SPI1            (Rcc_PeripheralIdType)(RCC_APB2*32 + 12UL)
#define RCC_SPI4            (Rcc_PeripheralIdType)(RCC_APB2*32 + 13UL)
#define RCC_SYSCFG          (Rcc_PeripheralIdType)(RCC_APB2*32 + 14UL)
#define RCC_TIM9            (Rcc_PeripheralIdType)(RCC_APB2*32 + 16UL)
#define RCC_TIM10           (Rcc_PeripheralIdType)(RCC_APB2*32 + 17UL)
#define RCC_TIM11           (Rcc_PeripheralIdType)(RCC_APB2*32 + 18UL)

                /*      RCC APIs    */
/*  Initialize System Clock */
void RCC_voidInit(void);
void RCC_voidInitSysClock(void);  

/* Enable Clock for a Peripheral */
void RCC_voidEnableClock(Rcc_PeripheralIdType PeripheralId);

/* Disable Clock for a Peripheral */
void RCC_voidDisableClock(Rcc_PeripheralIdType PeripheralId);


void delay(uint32 w);

#endif /* RCC_INTERFACE_H */
