/*---------------------------------------------------------------------
File Name:		<Keypad.h>
Created on:		<9/6/2019>
Author:			<Abdelrahman Tarek>
Description:	<Module's Header File>
Status: 		<<Finished>>
----------------------------------------------------------------------*/
#ifndef KEYPAD_H_
#define KEYPAD_H_
/******************************INCLUDES********************************/

#include "micro_config.h"
#include "common_macros.h"
#include "std_types.h"

/*******************Definitions and Configurations*********************/

typedef uint8 	ButtonType;

#define COL_NUM 4
#define ROW_NUM 4

#define KEYPAD_PORT_REG 	PORTC
#define KEYPAD_DIR_REG 		DDRC
#define KEYPAD_READ_REG 	PINC

#define ROWS_PINS_FIRST		STD_ON   // (STD_ON,STD_OFF)


#if (ROWS_PINS_FIRST == STD_ON)
#define ROWS_DIR_CFG 			(KEYPAD_DIR_REG & 0xf0)
#define INTERNAL_PULLUP 		((KEYPAD_PORT_REG & 0xf0)|(0x0f))
#define COL_SWITCH_DIR_CFG		((KEYPAD_DIR_REG & 0x0f)|(1<<(col+4)))
#define COL_SWITCH_PORT_CFG		((KEYPAD_PO	RT_REG & 0x0f)|(~(1<<(col+4))))

#elif (ROWS_PINS_FIRST == STD_OFF)
#define ROWS_DIR_CFG 			(KEYPAD_DIR_REG & 0x0f)
#define INTERNAL_PULLUP 		((KEYPAD_PORT_REG & 0x0f)|(0xf0))
#define COL_SWITCH_DIR_CFG		((KEYPAD_DIR_REG & 0xf0)|(1<<col))
#define COL_SWITCH_PORT_CFG		((KEYPAD_PORT_REG & 0x0f)|(~(1<<col)))

#endif


#if (COL_NUM == 3)

#define BUTTON_1 	(1)
#define BUTTON_2 	(2)
#define BUTTON_3 	(3)
#define BUTTON_4 	(4)
#define BUTTON_5 	(5)
#define BUTTON_6 	(6)
#define BUTTON_7 	(7)
#define BUTTON_8 	(8)
#define BUTTON_9 	(9)
#define BUTTON_10 	('*')
#define BUTTON_11 	(0)
#define BUTTON_12 	('#')

#elif (COL_NUM == 4)

#define BUTTON_1 	(7)
#define BUTTON_2 	(8)
#define BUTTON_3 	(9)
#define BUTTON_4 	('%')
#define BUTTON_5 	(4)
#define BUTTON_6 	(5)
#define BUTTON_7 	(6)
#define BUTTON_8 	('*')
#define BUTTON_9 	(1)
#define BUTTON_10 	(2)
#define BUTTON_11 	(3)
#define BUTTON_12 	('-')
#define BUTTON_13 	('#')
#define BUTTON_14 	(0)
#define BUTTON_15 	('=')
#define BUTTON_16 	('+')

#endif
/****************Extern Module Shared Global Variables*****************/

/********************************ENUMS********************************/

/************************Structures and Unions**************************/

/************************Function-Like MACROS**************************/

/************************Function Declarations**************************/

ButtonType Keypad_getKeyValue (void);



#endif /* KEYPAD_H_ */
