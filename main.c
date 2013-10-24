#include <msp430.h> 
#include "lcd.h"
#include "button.h"

/*
 * main.c
 */
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
