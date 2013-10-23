#include <msp430.h> 
#include "lcd.h"

/*
 * main.c
 */
int main(void) {
    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer

    initSPI();

    LCDinit();
	
    LCDclear();

    while(1){}

	return 0;
}
