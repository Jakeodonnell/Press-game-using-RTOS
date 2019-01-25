/*
* player1.c
*
* Created: 2018-10-17 13:31:26
*  Author: jake
*/

#include <asf.h>
#include "task_player1.h"

#define P22		IOPORT_CREATE_PIN(PIOB, 26)

void task_player1(void *pvParameters) {
	portTickType xLastWakeTime;
	const portTickType xTimeIncrement = 4;
	xLastWakeTime = xTaskGetTickCount();

	ioport_enable_pin(P22);
	ioport_set_pin_dir(P22, IOPORT_DIR_OUTPUT);
	while(1) {
		vTaskDelayUntil(&xLastWakeTime, xTimeIncrement);

		//ioport_set_pin_level(P22, HIGH);
		
		ioport_set_pin_level(P22, HIGH);
		volatile j;
		j=0;
		for (int i=0; i < 1000; i++) {
			j++;
			ioport_set_pin_level(P22, HIGH);
		}
		ioport_set_pin_level(P22, LOW);
		
	}
}
