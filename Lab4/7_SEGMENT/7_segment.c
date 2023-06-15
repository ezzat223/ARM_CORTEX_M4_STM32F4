/******************************************************************************/
/* Author   : Ezzat Hegazy													  */
/* Date     : 13 April 2023												   	  */
/* Version  : V01	                                        				  */
/******************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "7_SEGMENT.h"
#include "GPIO_interface.h"

void SEVEN_SEGMENT_voidDisplyNumber(uint8 Copy_uint8CommonType, uint8 Copy_uint8Number)
{
    switch (Copy_uint8CommonType)
    {
    case COMMON_CATHODE:
        switch(Copy_uint8Number)
	  {

	   case 0:
			GPIO_voidWritePin(GPIO_B, 0, HIGH);
			GPIO_voidWritePin(GPIO_B, 1, HIGH);
			GPIO_voidWritePin(GPIO_B, 2, HIGH);
			GPIO_voidWritePin(GPIO_B, 3, HIGH);
			GPIO_voidWritePin(GPIO_B, 4, HIGH);
			GPIO_voidWritePin(GPIO_B, 5, HIGH);
			GPIO_voidWritePin(GPIO_B, 6, LOW);
		break;

		case 1:
			GPIO_voidWritePin(GPIO_B, 0, LOW);
			GPIO_voidWritePin(GPIO_B, 1, HIGH);
			GPIO_voidWritePin(GPIO_B, 2, HIGH);
			GPIO_voidWritePin(GPIO_B, 3, LOW);
			GPIO_voidWritePin(GPIO_B, 4, LOW);
			GPIO_voidWritePin(GPIO_B, 5, LOW);
			GPIO_voidWritePin(GPIO_B, 6, LOW);
		break;

		case 2:
			GPIO_voidWritePin(GPIO_B, 0, HIGH);
			GPIO_voidWritePin(GPIO_B, 1, HIGH);
			GPIO_voidWritePin(GPIO_B, 2, LOW);
			GPIO_voidWritePin(GPIO_B, 3, HIGH);
			GPIO_voidWritePin(GPIO_B, 4, HIGH);
			GPIO_voidWritePin(GPIO_B, 5, LOW);
			GPIO_voidWritePin(GPIO_B, 6, HIGH);
		break;

		case 3:
			GPIO_voidWritePin(GPIO_B, 0, HIGH);
			GPIO_voidWritePin(GPIO_B, 1, HIGH);
			GPIO_voidWritePin(GPIO_B, 2, HIGH);
			GPIO_voidWritePin(GPIO_B, 3, HIGH);
			GPIO_voidWritePin(GPIO_B, 4, LOW);
			GPIO_voidWritePin(GPIO_B, 5, LOW);
			GPIO_voidWritePin(GPIO_B, 6, HIGH);
		break;

		case 4:
			GPIO_voidWritePin(GPIO_B, 0, LOW);
			GPIO_voidWritePin(GPIO_B, 1, HIGH);
			GPIO_voidWritePin(GPIO_B, 2, HIGH);
			GPIO_voidWritePin(GPIO_B, 3, LOW);
			GPIO_voidWritePin(GPIO_B, 4, LOW);
			GPIO_voidWritePin(GPIO_B, 5, HIGH);
			GPIO_voidWritePin(GPIO_B, 6, HIGH);
		break;

		case 5:
			GPIO_voidWritePin(GPIO_B, 0, HIGH);
			GPIO_voidWritePin(GPIO_B, 1, LOW);
			GPIO_voidWritePin(GPIO_B, 2, HIGH);
			GPIO_voidWritePin(GPIO_B, 3, HIGH);
			GPIO_voidWritePin(GPIO_B, 4, LOW);
			GPIO_voidWritePin(GPIO_B, 5, HIGH);
			GPIO_voidWritePin(GPIO_B, 6, HIGH);
		break;

		case 6:
			GPIO_voidWritePin(GPIO_B, 0, HIGH);
			GPIO_voidWritePin(GPIO_B, 1, LOW);
			GPIO_voidWritePin(GPIO_B, 2, HIGH);
			GPIO_voidWritePin(GPIO_B, 3, HIGH);
			GPIO_voidWritePin(GPIO_B, 4, HIGH);
			GPIO_voidWritePin(GPIO_B, 5, HIGH);
			GPIO_voidWritePin(GPIO_B, 6, HIGH);
		break;

		case 7:
			GPIO_voidWritePin(GPIO_B, 0, HIGH);
			GPIO_voidWritePin(GPIO_B, 1, HIGH);
			GPIO_voidWritePin(GPIO_B, 2, HIGH);
			GPIO_voidWritePin(GPIO_B, 3, LOW);
			GPIO_voidWritePin(GPIO_B, 4, LOW);
			GPIO_voidWritePin(GPIO_B, 5, LOW);
			GPIO_voidWritePin(GPIO_B, 6, HIGH);
		break;

		case 8:
			GPIO_voidWritePin(GPIO_B, 0, HIGH);
			GPIO_voidWritePin(GPIO_B, 1, HIGH);
			GPIO_voidWritePin(GPIO_B, 2, HIGH);
			GPIO_voidWritePin(GPIO_B, 3, HIGH);
			GPIO_voidWritePin(GPIO_B, 4, HIGH);
			GPIO_voidWritePin(GPIO_B, 5, HIGH);
			GPIO_voidWritePin(GPIO_B, 6, HIGH);
		break;

		case 9:
			GPIO_voidWritePin(GPIO_B, 0, HIGH);
			GPIO_voidWritePin(GPIO_B, 1, HIGH);
			GPIO_voidWritePin(GPIO_B, 2, HIGH);
			GPIO_voidWritePin(GPIO_B, 3, HIGH);
			GPIO_voidWritePin(GPIO_B, 4, LOW);
			GPIO_voidWritePin(GPIO_B, 5, HIGH);
			GPIO_voidWritePin(GPIO_B, 6, HIGH);
		break;
        
		default:
			break;
	   }
        break;
    case COMMON_ANODE:
    switch(Copy_uint8Number)
	  {

	   case 0:
			GPIO_voidWritePin(GPIO_B, 0, LOW);
			GPIO_voidWritePin(GPIO_B, 1, LOW);
			GPIO_voidWritePin(GPIO_B, 2, LOW);
			GPIO_voidWritePin(GPIO_B, 3, LOW);
			GPIO_voidWritePin(GPIO_B, 4, LOW);
			GPIO_voidWritePin(GPIO_B, 5, LOW);
			GPIO_voidWritePin(GPIO_B, 6, HIGH);
		break;

		case 1:
			GPIO_voidWritePin(GPIO_B, 0, HIGH);
			GPIO_voidWritePin(GPIO_B, 1, LOW);
			GPIO_voidWritePin(GPIO_B, 2, LOW);
			GPIO_voidWritePin(GPIO_B, 3, HIGH);
			GPIO_voidWritePin(GPIO_B, 4, HIGH);
			GPIO_voidWritePin(GPIO_B, 5, HIGH);
			GPIO_voidWritePin(GPIO_B, 6, HIGH);
		break;
        /* Ma kmltsh elly taht*/
		case 2:
			GPIO_voidWritePin(GPIO_B, 0, HIGH);
			GPIO_voidWritePin(GPIO_B, 1, HIGH);
			GPIO_voidWritePin(GPIO_B, 2, LOW);
			GPIO_voidWritePin(GPIO_B, 3, HIGH);
			GPIO_voidWritePin(GPIO_B, 4, HIGH);
			GPIO_voidWritePin(GPIO_B, 5, LOW);
			GPIO_voidWritePin(GPIO_B, 6, HIGH);
		break;

		case 3:
			GPIO_voidWritePin(GPIO_B, 0, HIGH);
			GPIO_voidWritePin(GPIO_B, 1, HIGH);
			GPIO_voidWritePin(GPIO_B, 2, HIGH);
			GPIO_voidWritePin(GPIO_B, 3, HIGH);
			GPIO_voidWritePin(GPIO_B, 4, LOW);
			GPIO_voidWritePin(GPIO_B, 5, LOW);
			GPIO_voidWritePin(GPIO_B, 6, HIGH);
		break;

		case 4:
			GPIO_voidWritePin(GPIO_B, 0, LOW);
			GPIO_voidWritePin(GPIO_B, 1, HIGH);
			GPIO_voidWritePin(GPIO_B, 2, HIGH);
			GPIO_voidWritePin(GPIO_B, 3, LOW);
			GPIO_voidWritePin(GPIO_B, 4, LOW);
			GPIO_voidWritePin(GPIO_B, 5, HIGH);
			GPIO_voidWritePin(GPIO_B, 6, HIGH);
		break;

		case 5:
			GPIO_voidWritePin(GPIO_B, 0, HIGH);
			GPIO_voidWritePin(GPIO_B, 1, LOW);
			GPIO_voidWritePin(GPIO_B, 2, HIGH);
			GPIO_voidWritePin(GPIO_B, 3, HIGH);
			GPIO_voidWritePin(GPIO_B, 4, LOW);
			GPIO_voidWritePin(GPIO_B, 5, HIGH);
			GPIO_voidWritePin(GPIO_B, 6, HIGH);
		break;

		case 6:
			GPIO_voidWritePin(GPIO_B, 0, HIGH);
			GPIO_voidWritePin(GPIO_B, 1, LOW);
			GPIO_voidWritePin(GPIO_B, 2, HIGH);
			GPIO_voidWritePin(GPIO_B, 3, HIGH);
			GPIO_voidWritePin(GPIO_B, 4, HIGH);
			GPIO_voidWritePin(GPIO_B, 5, HIGH);
			GPIO_voidWritePin(GPIO_B, 6, HIGH);
		break;

		case 7:
			GPIO_voidWritePin(GPIO_B, 0, HIGH);
			GPIO_voidWritePin(GPIO_B, 1, HIGH);
			GPIO_voidWritePin(GPIO_B, 2, HIGH);
			GPIO_voidWritePin(GPIO_B, 3, LOW);
			GPIO_voidWritePin(GPIO_B, 4, LOW);
			GPIO_voidWritePin(GPIO_B, 5, LOW);
			GPIO_voidWritePin(GPIO_B, 6, HIGH);
		break;

		case 8:
			GPIO_voidWritePin(GPIO_B, 0, HIGH);
			GPIO_voidWritePin(GPIO_B, 1, HIGH);
			GPIO_voidWritePin(GPIO_B, 2, HIGH);
			GPIO_voidWritePin(GPIO_B, 3, HIGH);
			GPIO_voidWritePin(GPIO_B, 4, HIGH);
			GPIO_voidWritePin(GPIO_B, 5, HIGH);
			GPIO_voidWritePin(GPIO_B, 6, HIGH);
		break;

		case 9:
			GPIO_voidWritePin(GPIO_B, 0, HIGH);
			GPIO_voidWritePin(GPIO_B, 1, HIGH);
			GPIO_voidWritePin(GPIO_B, 2, HIGH);
			GPIO_voidWritePin(GPIO_B, 3, HIGH);
			GPIO_voidWritePin(GPIO_B, 4, LOW);
			GPIO_voidWritePin(GPIO_B, 5, HIGH);
			GPIO_voidWritePin(GPIO_B, 6, HIGH);
		break;
        
		default:
			break;
	   }
        break;
    default:
        break;
    }
}
