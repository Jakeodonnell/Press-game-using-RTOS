/**
* \file
*
* \brief Empty user application template
*
*/

/**
* \mainpage User Application template doxygen documentation
*
* \par Empty user application template
*
* Bare minimum empty user application template
*
* \par Content
*
* -# Include the ASF header files (through asf.h)
* -# "Insert system clock initialization code here" comment
* -# Minimal main function that starts with a call to board_init()
* -# "Insert application code here" comment
*
*/

/*
* Include header files for all drivers that have been imported from
* Atmel Software Framework (ASF).
*/
/*
* Support and FAQ: visit <a href="http://www.atmel.com/design-support/">Atmel Support</a>
*/
#include <inttypes.h>	/* See http://en.wikipedia.org/wiki/C_data_types#Fixed-width_integer_types for more info */
#include <setjmp.h>
#include <stdio.h>
#include <stdio_serial.h>
#include <asf.h>
#include "conf_board.h"
//#include "task_player1.h"
//#include "task_player2.h"
#include "adcFunctions.h"
#include "DelayFunctions.h"
#include "lcdApplication.h"
#include "LCDFunctions.h"
#include "Controll.h"

//#define P24		IOPORT_CREATE_PIN(PIOA, 15)
//#define P22		IOPORT_CREATE_PIN(PIOB, 26)
//#define P23		IOPORT_CREATE_PIN(PIOA, 14)

void setUp(void);
void tearDown(void);
void resetTest(void);

int main (void)
{
	/* Insert system clock initialization code here (sysclk_init()). */

	board_init();
	sysclk_init();
	lcdInit();
	delayInit();
	startGame();
	//ioport_enable_pin(P24);
	//ioport_set_pin_dir(P24, IOPORT_DIR_OUTPUT);

	//xTaskCreate(task_player1, (const signed char * const) "player1", TASK_PLAYER1_STACK_SIZE, NULL, TASK_PLAYER1_PRIORITY, NULL);
	//xTaskCreate(task_player2, (const signed char * const) "player2", TASK_PLAYER2_STACK_SIZE, NULL, TASK_PLAYER2_PRIORITY, NULL);        /* Start the FreeRTOS scheduler running all tasks indefinitely*/
	//vTaskStartScheduler();
	
	/* Insert application code here, after the board has been initialized. */
}

//void vApplicationTickHook(void){
	//ioport_set_pin_level(P24, HIGH);
	//volatile int j=0;   /* makes sure j doesn't overflow */
	//for (int i=0; i<10; i++) /* The delay counter */
	//{
	//j++;   /* some easy predictable operation */
	//}
	//ioport_set_pin_level(P24, LOW);
	//ioport_set_pin_level(P23, LOW);
	//ioport_set_pin_level(P22, LOW);
//}

void setUp(void)
{
	/* Do nothing */
}

void tearDown(void)
{
	/* Do nothing */
}

void resetTest(void)
{
	tearDown();
	setUp();
}

