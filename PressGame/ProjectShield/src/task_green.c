/*
* player1.c
*
* Created: 2018-10-17 13:31:26
*  Author: jake & stefan
*/

#include <asf.h>
#include "task_green.h"			//Pin created for button green
#include "task_control.h"		//Pin created for a led lamp

#define P47		IOPORT_CREATE_PIN(PIOC, 16)
#define LED3	IOPORT_CREATE_PIN(PIOC, 9)

void task_green(void *pvParameters) {
	vTaskDelay(500);											//Delay the task so controller can catch the semaphores at initialization
	ioport_enable_pin(LED3);									//Enables the pin created
	ioport_set_pin_dir(LED3, IOPORT_DIR_OUTPUT);				//Sets the pin created as output so we now can write to it
	uint32_t Button_green = 0;									//Creates a variable for button that later will changed if it is pressed
	while (1){
		Button_green = ~ioport_get_pin_level(P47) & 1;			//IOport get pin level is a boolean and returns 1 if it is pressed
		xSemaphoreTake(xSemaphoreGreen, 0);						//Tries to take the semaphore every tick
		if(Button_green){
			xSemaphoreGive(xSemaphoreGreen);					//Gives the semaphore if the button was pressed, if the controller receives this one first this task has won
		}
	}
}