/******************************************************************************/
/* Author   : Ezzat Hegazy													  */
/* Date     : 6 May 2023												   	  */
/* Version  : V02	                                        				  */
/******************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"

#include "KEYPAD_config.h"
#include "KEYPAD_interface.h"


// [Key map] Array to choose from
uint8 look_up[4][3] =
{
	{1, 2, 3},
	{4, 5, 6},
	{7, 8, 9},
	{0, 0, 0}    // was supposed to be {*, 0, #} But we're not using them for now
};

extern uint8 key;

/* Configures pins */
void KEYPAD_voidInit(void)
{
    uint8 index=0;
    /* Config columns as INPUT | PULLUP */
    for(index = COL_START_INDEX; index<=COL_END_INDEX; index++)
    {
        GPIO_voidConfigPin(COL_PORT, index, GPIO_INPUT, INPUT_PULL_UP);
    }

    /* Config Rows as OUTPUT | PUSHPULL */
    for(index = ROW_START_INDEX; index<=ROW_END_INDEX; index++)
    {
        GPIO_voidConfigPin(ROW_PORT, index, GPIO_OUTPUT, OUTPUT_PUSH_PULL);
        /* IDLE state (De-activate all) */
        GPIO_voidWritePin(ROW_PORT, index, HIGH);
    }
}

/* Scan all keys to check which one is pressed */
void KEYPAD_voidManage(void)
{
	if(key == RELEASED)
	{
		uint8 row;
		uint8 column;
		uint8 currentState =1;
		uint8 prevState =1;

		uint8 rowCounter= -1;
		uint8 colCounter= -1;

		for(row = ROW_START_INDEX; row <= ROW_END_INDEX; row++) // @suppress("Statement has no effect")
		{
			rowCounter= row - ROW_START_INDEX;
			GPIO_voidWritePin(ROW_PORT, row, LOW);

			for(column = COL_START_INDEX; column <= COL_END_INDEX; column++) // @suppress("Statement has no effect")
			{
				colCounter= column - COL_START_INDEX;
				currentState = GPIO_uint8ReadInputValue(COL_PORT, column);

				if((currentState == 0) && (prevState == 1))
				{
					delay(100);
					currentState = GPIO_uint8ReadInputValue(COL_PORT, column);
					if(currentState == 0)
					{
						key = look_up[rowCounter][colCounter];
						prevState=0;
						KEYPAD_voidCallOut_KeyPressNotification();
						colCounter=-1;
						break;

					}
				}
				else if(currentState == 1)
				{
					prevState=1;
				}
			}
			/* DeActivate again */
			GPIO_voidWritePin(ROW_PORT, row, HIGH);
		}
	}
}

uint8 KEYPAD_uint8GetKey(void)
{
	uint8 return_val = key;
	/* Notify KEYPAD_manage that key is released */
	key = RELEASED;
    return return_val;
}
