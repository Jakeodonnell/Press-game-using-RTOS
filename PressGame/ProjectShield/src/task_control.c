/*
* control.c
*
* Created: 2018-10-19 12:23:21
*  Author: jake & stefan
*/

#include <asf.h>
#include "lcdApplication.h"
#include "LCDFunctions.h"
#include "DelayFunctions.h"
#include "buttons.h"
#include "task_control.h"
#include "task_blue.h"
#include "task_green.h"
#define LED1	IOPORT_CREATE_PIN(PIOC, 14)		//Pin created for a led lamp
#define LED2	IOPORT_CREATE_PIN(PIOC, 12)		//Pin created for a led lamp
#define LED3	IOPORT_CREATE_PIN(PIOC, 9)		//Pin created for a led lamp

#define P47		IOPORT_CREATE_PIN(PIOC, 16)		//Pin created for button green
#define P45		IOPORT_CREATE_PIN(PIOC, 18)		//Pin created for button blue


xSemaphoreHandle xSemaphoreBlue;				//Semaphores are created
xSemaphoreHandle xSemaphoreGreen;

void task_control(void *pvParameters){
	xSemaphoreTake( xSemaphoreBlue, (portTickType) 10);							//Semaphores are taken immediately when created 
	xSemaphoreTake( xSemaphoreGreen, (portTickType) 10);
	int Number = (((uint32_t )trng_read_output_data(TRNG)) % 5+2) * 1000000;	//A random number between 2 and 5
	ioport_enable_pin(LED2);													//Enables pin to use it
	ioport_set_pin_dir(LED2, IOPORT_DIR_OUTPUT);								//Sets pin to output 
	state_t current = START;													//Sets initialization of state machine to start
	state_t nextState = START;
	uint32_t Button_green = 0;
	uint32_t Button_blue = 0;
	uint32_t go;
	uint16_t timeSincePress;
	
	while (1){
		switch(current){														//State machine with current state as input, current will get changed to next when appropriate 
			case (START):
			ioport_set_pin_level(LED1, LOW);								
			ioport_set_pin_level(LED2, LOW);
			ioport_set_pin_level(LED3, LOW);
			lcdClearDisplay();
			lcdWriteAsciiString("PRESS LEFT TO   START THE GAME");
			delayMicroseconds(50000);
			if (readLCDbutton() == btnLEFT){									//Starts game when left button is pressed
				lcdClearDisplay();
				lcdWriteAsciiString("GAME STARTING");
				delayMicroseconds(Number);										//Delays with random number before you can press
				nextState = RUNNING;											//Changes state to Running
				} else{
				nextState = START;
			}
			break;
			
			case(RUNNING):
			if ((Button_green = ~ioport_get_pin_level(P47) & 1)){				//Checks if button is pressed before lamp is lightened, this means the player is holding the button and is cheating
				lcdClearDisplay();
				lcdWriteAsciiString("BLUE WIN        GREEN CHEATER");
				delayMicroseconds(1000000);
				nextState = START;
			}
			else if ((Button_blue = ~ioport_get_pin_level(P45) & 1)){			//Checks if button is pressed before lamp is lightened, this means the player is holding the button and is cheating
				lcdClearDisplay();
				lcdWriteAsciiString("GEEN WIN        BLUE CHEATER");
				delayMicroseconds(1000000);
				nextState = START;
			}
			else{
				xSemaphoreGive(xSemaphoreBlue);
				xSemaphoreGive(xSemaphoreGreen);
				ioport_set_pin_level(LED2, HIGH);
				go = xTaskGetTickCount();
				nextState = WINNER;
			}
			break;
			
			case(WINNER):
			lcdClearDisplay();
			lcdWriteAsciiString("GO");
			delayMicroseconds(50000);
			uint32_t currTick = xTaskGetTickCount();							//Gets tick count at start of game, will subtract it with when a button is pressed
			
			if ((currTick - go)> 20000){										//If someone has not pressed a button within 2 seconds the game will end
				lcdClearDisplay();
				lcdWriteAsciiString("NOBODY WINS");
				delayMicroseconds(1000000);
				currTick = 0;
				nextState = START;
			}
			
			else if (xSemaphoreTake(xSemaphoreBlue,0) == pdTRUE){				//Tries to take the blue semaphore, can only do this is bluebutton has been pressed
				uint32_t blueTick = xTaskGetTickCount();						//Other tick count that is subtracted with "go" tick count
				ioport_set_pin_level(LED2, LOW);
				ioport_set_pin_level(LED1, HIGH);
				lcdClearDisplay();
				uint16_t timeforpress = (uint16_t)((blueTick - go)/10);			//timeforpress is ticks / 10 to get in milliseconds
				char num[16];
				sprintf(num, "BLUE WIN!       TIME:%u" "ms", timeforpress);
				lcdWriteAsciiString(num);
				delayMicroseconds(4000000);
				
				nextState = START;
			}
			
			else if (xSemaphoreTake(xSemaphoreGreen,0) == pdTRUE){				//Tries to take the blue semaphore, can only do this is greenbutton has been pressed
				uint32_t greenTick = xTaskGetTickCount();						//Other tick count that is subtracted with "go" tick count
				ioport_set_pin_level(LED2, LOW);
				ioport_set_pin_level(LED3, HIGH);
				lcdClearDisplay();
				timeSincePress = (uint16_t)((greenTick - go)/100);				//timeforpress is ticks / 10 to get in milliseconds
				char num[16];
				sprintf(num, "GREEN WIN!      TIME:%u" "ms", timeSincePress);
				lcdWriteAsciiString(num);
				delayMicroseconds(4000000);
				nextState = START;
			}

			else{
				nextState = WINNER;
			}
			break;
		};
		current = nextState;

	}
}

