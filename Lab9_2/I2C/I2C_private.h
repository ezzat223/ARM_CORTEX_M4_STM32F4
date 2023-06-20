/******************************************************************************/
/* Author   : Ezzat Hegazy													  */
/* Date     : 31 MAY 2023												   	  */
/* Version  : V01	                                        				  */
/******************************************************************************/
#ifndef I2C_PRIVATE_H
#define I2C_PRIVATE_H

#include "stm32f4xx.h"


#define I2C1_CR1           (I2C1->CR1)
#define I2C1_CR2           (I2C1->CR2)
#define I2C1_OAR1          (I2C1->OAR1)
#define I2C1_DR            (I2C1->DR)
#define I2C1_SR1           (I2C1->SR1)
#define I2C1_SR2           (I2C1->SR2)
#define I2C1_CCR           (I2C1->CCR)
#define I2C1_TRISE         (I2C1->TRISE)




#endif /* I2C_PRIVATE_H */
