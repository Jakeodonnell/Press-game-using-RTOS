/*
* buttons.c
*
* Created: 2015-06-12 16:28:53
* Author: To Be Decided
*/

#include "buttons.h"
#include "adcFunctions.h"	/* Must use the value from the ADC to figure out which button */
buttonType readLCDbutton(void)
{
	/* Write code here */
	uint32_t adcValue = analogRead(0);
	if (adcValue < 50)
	{
		return btnRIGHT;
		
	}else if (adcValue < 1000)
	{
		return btnUP;
	} else if (adcValue < 2000)
	{
		return btnDOWN;
	} else if (adcValue < 2800)
	{
		return btnSELECT;
	}
	else if (adcValue < 3500)
	{
		return btnLEFT;
	}
	
	return btnNONE;/* Change to actual value */
}