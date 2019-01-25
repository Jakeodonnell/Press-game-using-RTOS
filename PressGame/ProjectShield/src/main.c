/*
* main.c
*
* Created: 2018-10-19 12:21:56
*  Author: jake & stefan
*/
#include "asf.h"
#include "conf_board.h"
#include "LCDFunctions.h"
#include "adcFunctions.h"
#include "DelayFunctions.h"
#include "task_blue.h"
#include "task_green.h"
#include "task_control.h"


int main(void) {
	
	/*
	init of different parts 
	*/
	ioport_init();
	sysclk_init();
	board_init();
	delayInit();
	lcdInit();
	analogInit(0);
	pmc_enable_periph_clk(ID_TRNG);
	trng_enable(TRNG);
	lcdWrite(0x0C, LOW);
	/*
	two semaphores are created
	*/
	xSemaphoreGreen = xSemaphoreCreateMutex();
	xSemaphoreBlue = xSemaphoreCreateMutex();
	/*
	tasks are created and started
	*/
	xTaskCreate(task_control, (const signed char * const) "task_control", task_control_STACK_SIZE, NULL, task_control_PRIORITY, NULL);
	xTaskCreate(task_green, (const signed char * const) "task_green", task_green_STACK_SIZE, NULL, task_green_PRIORITY, NULL);
	xTaskCreate(task_blue, (const signed char * const) "task_blue", task_blue_STACK_SIZE, NULL, task_blue_PRIORITY, NULL);
	vTaskStartScheduler();
}

