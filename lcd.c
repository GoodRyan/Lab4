#include "lcd.h"

#define RS_MASK 0x40

char LCDCON = 0;// LCDSEND = 0;

void initSPI(){
	UCB0CTL1 |= UCSWRST;

	UCB0CTL0 |= UCCKPH|UCMSB|UCMST|UCSYNC;
	UCB0CTL1 |= UCSSEL1;
	//UCB0STAT |= UCLISTEN;
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

void SPIsend(char byteToSend){
	volatile char readByte;

	setSlaveSelectLo();

	UCB0TXBUF = byteToSend;

	while(!(UCB0RXIFG & IFG2)){
		//waiting for byte
	}

	readByte = UCB0RXBUF;

	setSlaveSelectHi();

}

//formerly LCDDELAY1 in assembly
void LCDdelayShort(){
	_delay_cycles(100);
}

//formerly LCDDELAY2 in assembly
void LCDdelayLong(){
	_delay_cycles(1900);
}

void LCDwriteFour(char LCDdata){
	char halfCharacter = LCDdata;
	halfCharacter &= 0x0f;
	halfCharacter |= LCDCON;
	halfCharacter &= 0x7f;
	SPIsend(halfCharacter);
	LCDdelayShort();

	halfCharacter |= 0x80;
	SPIsend(halfCharacter);
	LCDdelayShort();

	halfCharacter &= 0x7f;
	SPIsend(halfCharacter);
	LCDdelayShort();

}

void LCDwriteEight(char byteToSend){
	unsigned char sendByte = byteToSend;

	sendByte &= 0xF0;

	sendByte = sendByte >> 4;

	LCDwriteFour(sendByte);

	sendByte = byteToSend;

	sendByte &= 0x0F;

	LCDwriteFour(sendByte);


}

void writeCommandNibble(char commandNibble){
	LCDCON &= ~RS_MASK;
	LCDwriteFour(commandNibble);
	LCDdelayLong();
}

void writeCommandByte(char commandByte){
	LCDCON &= ~RS_MASK;
	LCDwriteEight(commandByte);
	LCDdelayLong();
}

void writeDataByte(char dataByte){
	LCDCON |= RS_MASK;
	LCDwriteEight(dataByte);
	LCDdelayLong();
}

void LCDinit(){
	writeCommandNibble(0x03);

	writeCommandNibble(0x03);

	writeCommandNibble(0x03);

    writeCommandNibble(0x02);

    writeCommandByte(0x28);

    writeCommandByte(0x0C);

    writeCommandByte(0x01);

    writeCommandByte(0x06);

    writeCommandByte(0x01);

    writeCommandByte(0x02);

    SPIsend(0);
    LCDdelayShort();
}

void LCDclear(){
	writeCommandByte(1);
}

//might not need
void printCharacter(char asciiChar){
	writeDataByte(asciiChar);
}

void print(char * string){
	int stringTracker = 0;

	while (stringTracker < 8 && *string != 0x00){
		printCharacter(*string);
		string++;
		stringTracker++;
	}

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
