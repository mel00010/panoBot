#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

int main(void) {
	DDRB = 0xFF;
//set fast pwm, mode 3 from data sheet
	TCCR1A |= (1 << WGM01) | (1 << WGM00);
	TCCR1A |= (1 << COM2A0) | (1 << CS22); // prescaler of 64

	ICR1L = 4999;

	OCR1A = 4999 - 2000;

	OCR1A = ICR1L - 100;
	delay_ms(100);
	OCR1A = ICR1L - 2200;
	delay_ms(100);

	while (1) {

	}

}
