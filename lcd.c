#include "lcd.h"

char LCDCON = 0, LCDSEND = 0;

void initSPI(){
	UCB0CTL1 |= UCSWRST;
	UCB0CTL0 |= UCCKPH|UCMSB|UCMST|UCSYNC;
	UCB0CTL1 |= UCSSEL1;
	UCB0STAT |= UCLISTEN;
	P1DIR |= BIT0;

	P1SEL |= BIT5;
	P1SEL2 |= BIT5;

	P1SEL |= BIT7;
	P1SEL2 |= BIT7;

	P1SEL |= BIT6;
	P1SEL2 |= BIT6;

	UCB0CTL1 &= ~UCSWRST;

}

void setSlaveSelectLo(){
	P1OUT &= ~BIT0;
}

void setSlaveSelectHi(){
	P1OUT |= BIT0;
}

void SPISEND(){

}

//formerly LCDDELAY1 in assembly
void LCDdelayShort(){

}

//formerly LCDDELAY2 in assembly
void LCDdelayLong(){

}

void LCDwriteFour(char LCDDATA){
	char halfCharacter = LCDDATA;
	halfCharacter &= 0x0f;
	halfCharacter |= LCDCON;
	halfCharacter &= 0x7f;
	SPISEND();
	LCDdelayShort();

	halfCharacter |= 0x80;
	SPISEND();
	LCDdelayShort();

	halfCharacter |= 0x7f;
	SPISEND();
	LCDdelayShort();

}

void LCDwriteEight(){

}



void LCDinit(){

}

void LCDclear(){

}

//might not need
void printCharacter(char asciiChar){

}

void print(char * string){

}

void scrollString(char * string1, char * string2){

}

void getButton(){

}

//moves cursor to the second line
void secondLine(){

}

//moves cursor to the first line
void firstLine(){

}

void selectMessage(){

}

void debounce(){

}
