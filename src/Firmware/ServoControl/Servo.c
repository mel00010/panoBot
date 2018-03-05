/*16MHz clock timer */
#define F_CPU 16000000 
#define OUTPUTPIN1 PD4
#define OUTPUTPIN2 PD5
#include <avr/io.h>
#include <util/delay.h>
/*50MHz update , 20 ms update period */

/*waits using 16bit timer*/
void delay(){
	uint8_t i;
	for(i =0; i < 50; i++){
		/*delay loop for 16bit timer found in delay.h*/
		_delay_loop_2(0);
		_delay_loop_2(0);
		_delay_loop_2(0); 
	}
}

/* set the prescaler of pins, PWM MODE , Inverted or not*/
void initialize_servo(){

	TCCR1A|=(1<<COM1A1)|(1<<COM1B1)|(1<<WGM11);        //NON Inverted PWM
    TCCR1B|=(1<<WGM13)|(1<<WGM12)|(1<<CS11)|(1<<CS10); //prescaler = 64, mode =  14(FAST PWM)
    /*Mode 14 TOV1 Flag set at top of wgm */

    /*setting output pins */
    DDRD |= (1 << OUTPUTPIN1) | (1 << OUTPUTPIN2);

	ICR1 = 4999; /*Fast PMW mode*/
	/*milisec is about 100 4999/50			*/

	/* compare when OCR1A is a value, we will be at an angle*/
	OCR1A = 0;

}

/* used to get the angle feed the duty cycle 1ms 1.5ms 2ms, looking at about 1
us(microsecond) per degree*/
float get_angle(uint8_t dCycle){
	return ((dCycle - DCYCLEMIN) * 360) / (DCYCLEMAX - DCYCLEMIN + 1);
}

