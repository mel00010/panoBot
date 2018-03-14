#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

int main(void) {
	DDRB = 0xFF;
//set fast pwm, mode 3 from data sheet
	TCCR1A |= (1 << WGM01) | (1 << WGM00);
	TCCR1A |= (1 << COM2A0) | (1 << CS22); // prescaler of 64

	ICR1L = 4999;

<<<<<<< HEAD
	OCR1A = 4999 - 2000;
=======
OCR0A = 4999 - 2000;
>>>>>>> branch 'master' of git@github.com:mel00010/panoBot.git

<<<<<<< HEAD
	OCR1A = ICR1L - 100;
=======
while(1){

	OCR0A = ICR2A - 100;
>>>>>>> branch 'master' of git@github.com:mel00010/panoBot.git
	delay_ms(100);
<<<<<<< HEAD
	OCR1A = ICR1L - 2200;
=======
	OCR0A = ICR2A - 2200;
>>>>>>> branch 'master' of git@github.com:mel00010/panoBot.git
	delay_ms(100);

	while (1) {

	}

}
