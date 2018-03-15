#include <avr/io.h>
#include <util/delay.h>

void Wait()
{
   uint8_t i;
   for(i=0;i<50;i++)
   {
      _delay_loop_2(0);
      _delay_loop_2(0);
      _delay_loop_2(0);
   }

}

void main()
{
//   TCCR1A|=(1<<COM1A1)|(1<<COM1B1)|(1<<WGM11);
//   TCCR1B|=(1<<WGM13)|(1<<WGM12)|(1<<CS11)|(1<<CS10); //PRESCALER=64 MODE 14(FAST PWM)
//
//   ICR1=4999;

   DDRB|= 0xFF;

   for(;;) {
	   PORTB |= _BV(PB5);
	   _delay_ms(1);
	   PORTB &= ~_BV(PB5);
	   _delay_ms(19);
   }

//   OCR1A=970;
//   Wait();
//   OCR1A=316;
//   Wait();
//   OCR1A=425;
//   Wait();
//   OCR1A=535;
//   Wait();

   while(1)
   {


   }
}
