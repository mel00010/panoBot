#F_CPU 16000000
#include <avr/io.h>
#include <util/delay.h>

int main(void){
DDRD = 0xFF;
//set fast pwm, mode 3 from data sheet 
TCCR0A |= (1 << WGM1) | (1 << WGM0);
TCCR2A |= (1 << COM2A) | (1<< CS22);// prescaler of 64

ICR2A = 4999

OCR0A = 4999 - 2000;

while(1){

	OCR0A = ICR2A - 100;
	delay_ms(100);
	OCR0A = ICR2A - 2200;
	delay_ms(100);

}


}