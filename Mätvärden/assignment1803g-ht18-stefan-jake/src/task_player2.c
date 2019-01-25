/*
 * player1.c
 *
 * Created: 2018-10-17 13:31:26
 *  Author: jake
 */ 

#include <asf.h>
#include "task_player2.h"

#define P23		IOPORT_CREATE_PIN(PIOA, 14)

void task_player2(void *pvParameters) { 
	ioport_enable_pin(P23);
	ioport_set_pin_dir(P23, IOPORT_DIR_OUTPUT);
	 while(1) {        /* Insert your code toggling one I/O pin here (first high then l ow) */ 
		 ioport_set_pin_level(P23, HIGH);
  } 
}