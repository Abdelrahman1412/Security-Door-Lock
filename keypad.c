/*---------------------------------------------------------------------
File Name:		<Keypad.c>
Created on:		< 9 / 6 / 2019>
Author:			<Abdelrahman Tarek>
Description:	<Module's Source File>
Status: 		<<Finished>>
----------------------------------------------------------------------*/

/******************************INCLUDES********************************/
#include "keypad.h"

/**************************Global Variables****************************/
#if (COL_NUM == 3)
static ButtonType Keypad_4x3_KeyAdjustment(uint8 button_number);
#elif (COL_NUM == 4)
static ButtonType Keypad_4x4_KeyAdjustment(uint8 button_number);
#endif

/************************Function Definitions**************************/
/*---------------------------------------------------------------------
Function Name:	<Keypad_getKeyValue>
Description:
----------------------------------------------------------------------*/
ButtonType Keypad_getKeyValue (void)
{
	uint8 col;
	uint8 row;
	static ButtonType result = 0;
	KEYPAD_DIR_REG = ROWS_DIR_CFG;
	KEYPAD_PORT_REG = INTERNAL_PULLUP;

	for (col=0 ; col < COL_NUM; col++)
	{
		KEYPAD_DIR_REG = COL_SWITCH_DIR_CFG;

		KEYPAD_PORT_REG  = COL_SWITCH_PORT_CFG;

		for (row=0 ; row < ROW_NUM ;row++)
		{
#if (ROWS_PINS_FIRST == STD_ON)
			if (BIT_IS_CLEAR(KEYPAD_READ_REG,row))
#elif (ROWS_PINS_FIRST == STD_OFF)
				if (BIT_IS_CLEAR(KEYPAD_READ_REG,(row+4)))
#endif
				{
#if (COL_NUM == 3)
					result = Keypad_4x3_KeyAdjustment ( ((row*ROW_NUM) +col+1) );
#elif (COL_NUM == 4)
					result = Keypad_4x4_KeyAdjustment ( ((row*ROW_NUM) +col+1) );
#endif
				}
		}
	}
	return result;
}

/*---------------------------------------------------------------------
Function Name:	<Keypad_4x3_KeyAdjustment>
Description:
----------------------------------------------------------------------*/

#if (COL_NUM == 3)
static ButtonType Keypad_4x3_KeyAdjustment(uint8 button_number)
{
	switch (button_number)
	{
	case 1: button_number = BUTTON_1;
	break;
	case 2: button_number = BUTTON_2;
	break;
	case 3: button_number = BUTTON_3;
	break;
	case 4: button_number = BUTTON_4;
	break;
	case 5: button_number = BUTTON_5;
	break;
	case 6: button_number = BUTTON_6;
	break;
	case 7: button_number = BUTTON_7;
	break;
	case 8: button_number = BUTTON_8;
	break;
	case 9: button_number = BUTTON_9;
	break;
	case 10: button_number = BUTTON_10;
	break;
	case 11: button_number = BUTTON_11;
	break;
	case 12: button_number = BUTTON_12;
	break;
	default:;
	break;
	}
	return button_number;
}


#elif (COL_NUM == 4)
static ButtonType Keypad_4x4_KeyAdjustment(uint8 button_number)
{
	switch (button_number)
	{
	case 1: button_number = BUTTON_1;
	break;
	case 2: button_number = BUTTON_2;
	break;
	case 3: button_number = BUTTON_3;
	break;
	case 4: button_number = BUTTON_4;
	break;
	case 5: button_number = BUTTON_5;
	break;
	case 6: button_number = BUTTON_6;
	break;
	case 7: button_number = BUTTON_7;
	break;
	case 8: button_number = BUTTON_8;
	break;
	case 9: button_number = BUTTON_9;
	break;
	case 10: button_number = BUTTON_10;
	break;
	case 11: button_number = BUTTON_11;
	break;
	case 12: button_number = BUTTON_12;
	break;
	case 13: button_number = BUTTON_13;
	break;
	case 14: button_number = BUTTON_14;
	break;
	case 15: button_number = BUTTON_15;
	break;
	case 16: button_number = BUTTON_16;
	break;
	default:;
	break;
	}
	return button_number;
}

#endif
