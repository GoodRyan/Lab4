//
// lcd.h
// AuthorL Ryan Good
// Date: 17 October 2013
// Description: Clears the LCD screen on the geek box, then asks the user for an input.
// displays a message based on the following user input.
//


#include <msp430.h> 
#include "lcd.h"
#include "button.h"

int main(void) {
    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer
    char buttonPressed = 0;

    initSPI();

    LCDinit();
	
    LCDclear();

    print("Message?");
    secondLine();
    print("Press123");
    firstLine();
    buttonPressed = getButton();
    selectMessage(buttonPressed);

    while(1){}

	return 0;
}
