//
// lcd.h
// Authors: Todd Branchflower and Ryan Good
// Date: 17 October 2013
// Description: Library to interact with the Geek Box LCD.
//
#include <msp430.h>


void initSPI();

void LCDinit();

void LCDclear();

void secondLine();

void firstLine();

void print(char * string);

void scrollString(char * string1, char * string2);

void selectMessage();
