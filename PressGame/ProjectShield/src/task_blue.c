/*
* player1.c
*
* Created: 2018-10-17 13:31:26
*  Author: jake & stefan
*/

#include <asf.h>
#include "task_blue.h"
#include "task_control.h"

#define P45		IOPORT_CREATE_PIN(PIOC, 18)		//Pin created for button blue
#define LED1	IOPORT_CREATE_PIN(PIOC, 14)		//Pin created for a led lamp

void task_blue(void *pvParameters) {
	vTaskDelay(500);											//Delay the task so controller can catch the semaphores at initialization
	ioport_enable_pin(LED1);									//Enables the pin created
	ioport_set_pin_dir(LED1, IOPORT_DIR_OUTPUT);				//Sets the pin created as output so we now can write to it
	uint32_t Button_blue = 0;									//Creates a variable for button that later will changed if it is pressed
	while (1){
		Button_blue = ~ioport_get_pin_level(P45) & 1;			//IOport get pin level is a boolean and returns 1 if it is pressed
		xSemaphoreTake(xSemaphoreBlue, 0);						//Tries to take the semaphore every tick
		if(Button_blue){
			xSemaphoreGive(xSemaphoreBlue);						//Gives the semaphore if the button was pressed, if the controller receives this one first this task has won
		}
	}
}
