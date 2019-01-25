/*
 * lcdApplication.c
 *
 * Created: 2015-09-10 08:44:50
 *  Author: To Be Decided
 */ 

#include "lcdApplication.h"
#include "LCDFunctions.h"
#include "buttons.h"	/* to get the buttontype definiton */

int lcdWrite4DigitNumber(int number)
{
	/* Write code here */
	lcdClearDisplay();
	char chars[5];
	sprintf(chars, "%i", number);
	lcdWriteAsciiString(chars);
			
	return 0;	/* Assuming everything went ok */
}

int lcdWriteAsciiString(const char *string)
/* writes an ascii string up to 40 characters on the LCD display */
{
	uint8_t chars;
	uint8_t counter = 0;
	while(*string != '\0') {
		if (counter == 16)					//To allow the 2nd line to be used
		{
			for (int i = 0; i < 24; i++)
			{
				lcdWrite(0x14, LOW);
			}
		}
		chars = (uint8_t) (*string);
		lcdWrite(chars, 1);
		*string++;
		counter++;
	}
	return 0;	/* Assuming everything went ok */
}
int lcdWriteButtonValue(buttonType inputButton)
/* Writes the text corresponding to one of the buttosn on the LCD dispaly using lcdWriteAsciiString() 
 * Output should be one of SELECT, LEFT, UP, DOWN, RIGHT on the LCD display
 * if no buttons is pushed you can chose on displaying nothing or NONE  */
{
	/* Write code here */
	switch (inputButton)
	{
		case btnSELECT:
		lcdWriteAsciiString("Select");
		break;
		case btnLEFT:
		lcdWriteAsciiString("LEFT");
		break;
		case btnUP:
		lcdWriteAsciiString("UP");
		break;
		case btnDOWN:
		lcdWriteAsciiString("DOWN");
		break;
		case btnRIGHT:
		lcdWriteAsciiString("RIGHT");
		break;
		case btnNONE:
		lcdWriteAsciiString("NONE");
		break;
		
	}
	
	return 0;	/* Assuming everything went ok */
}