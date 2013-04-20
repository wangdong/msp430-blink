/*
 * Blink.c
 *
 *  Created on: Apr 20, 2013
 *      Author: wangdong
 */
#include <msp430.h>

void loop();
void delay();

int main(void) {
	WDTCTL = WDTPW + WDTHOLD;

	P2DIR = 0x0F;
	P6DIR = BIT7;

	for (;;)
		loop();
}

void loop() {
	P2OUT ^= BIT0;
	P2OUT ^= BIT1;
	P2OUT ^= BIT2;
	P2OUT ^= BIT3;
	//P6DIR ^= BIT7;
	delay(2000);
}

void delay(int ms) {
	enum { cycles_per_step = 1000 };
	for (int i = 0; i < ms; ++i)
		__delay_cycles(cycles_per_step);
}
