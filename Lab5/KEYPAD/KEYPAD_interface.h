/******************************************************************************/
/* Author   : Ezzat Hegazy													  */
/* Date     : 28 April 2023												   	  */
/* Version  : V01	                                        				  */
/******************************************************************************/
#ifndef KEYPAD_INTERFACE_H
#define	KEYPAD_INTERFACE_H

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"

#define RELEASED            22

            /* API Provided functions */
/* Configures pins */
void KEYPAD_voidInit(void);

void KEYPAD_voidManage(void);

uint8 KEYPAD_uint8GetKey(void);

/* Required function (Implemented by app to interface with) */
// To be called when Button is pressed
void KEYPAD_voidCallOut_KeyPressNotification(void);


#endif
