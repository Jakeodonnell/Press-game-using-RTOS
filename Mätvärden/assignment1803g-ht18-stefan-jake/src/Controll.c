/*
 * Controll.c
 *
 * Created: 2018-10-19 10:48:31
 *  Author: jake
 */ 
#include <asf.h>
#include "../src/lcdApplication.h"
#include "../src/buttons.h"	/* Just to get the buttonType defintion as an argument to lcdWriteButtonValue() */
#include "../src/LCDFunctions.h"
#include "DelayFunctions.h"
#include <inttypes.h>
#include "Controll.h"


void startGame(void){
			lcdClearDisplay();
			lcdWriteAsciiString("testjakestfan");
}